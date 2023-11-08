/*
 * Copyright (c) 2016-2020, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/clockchips.h>
#include <linux/cpu.h>
#include <linux/cpumask.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/version.h>
#if KERNEL_VERSION(4, 15, 0) > LINUX_VERSION_CODE
#include <soc/tegra/fuse.h>
#else
#include <soc/tegra/fuse.h>
#endif
#include <linux/tick.h>
#include <linux/vmalloc.h>
#include <linux/syscore_ops.h>
#include <linux/version.h>

#define TMRCR	0x000
#define TMRSR	0x004
#define TMRCSSR	0x014
#define TKEIE	0x100

#define TIMER10_OFFSET          0x90
#define TIMER_FOR_CPU(cpu) (TIMER10_OFFSET + (cpu) * 8)

static void __iomem *tegra210_timer_reg_base;
static u32 usec_config;
static u32 timer_us_mult, timer_us_shift;

struct tegra210_tke;

struct tegra210_tmr {
	struct clock_event_device evt;
	u64 tmr_index;
	u64 cpu_index;
	u32 freq;
	char name[20];
	void __iomem *reg_base;
	struct tegra210_tke *tke;
};

struct tegra210_tke {
	void __iomem *reg_base;
	struct tegra210_tmr tegra210_tmr[CONFIG_NR_CPUS];
};

static struct tegra210_tke *tke;

static int tegra210_timer_set_next_event(unsigned long cycles,
					 struct clock_event_device *evt)
{
	struct tegra210_tmr *tmr;
	tmr = container_of(evt, struct tegra210_tmr, evt);
	__raw_writel((1 << 31) /* EN=1, enable timer */
		     | ((cycles > 1) ? (cycles - 1) : 0), /* n+1 scheme */
		     tmr->reg_base + TMRCR);
	return 0;
}

static inline void _shutdown(struct tegra210_tmr *tmr)
{
	__raw_writel(0 << 31, /* EN=0, disable timer */
		     tmr->reg_base + TMRCR);
}

static int tegra210_timer_shutdown(struct clock_event_device *evt)
{
	struct tegra210_tmr *tmr;
	tmr = container_of(evt, struct tegra210_tmr, evt);

	_shutdown(tmr);
	return 0;
}

static int tegra210_timer_set_periodic(struct clock_event_device *evt)
{
	struct tegra210_tmr *tmr  = container_of(evt, struct tegra210_tmr, evt);

	_shutdown(tmr);
	__raw_writel((1 << 31) /* EN=1, enable timer */
		     | (1 << 30) /* PER=1, periodic mode */
		     | ((tmr->freq / HZ) - 1), /* PTV, preset value*/
		     tmr->reg_base + TMRCR);
	return 0;
}

static irqreturn_t tegra210_timer_isr(int irq, void *dev_id)
{
	struct tegra210_tmr *tmr;

	tmr = (struct tegra210_tmr *) dev_id;
	__raw_writel(1 << 30, /* INTR_CLR */
		     tmr->reg_base + TMRSR);
	tmr->evt.event_handler(&tmr->evt);
	return IRQ_HANDLED;
}

static int tegra210_timer_setup(unsigned int cpu)
{
	struct tegra210_tmr *tmr = &tke->tegra210_tmr[cpu];

	clockevents_config_and_register(&tmr->evt, tmr->freq,
					1, /* min */
					0x1fffffff); /* 29 bits */
#ifdef CONFIG_SMP
	if (irq_force_affinity(tmr->evt.irq, cpumask_of(cpu))) {
		pr_err("%s: cannot set irq %d affinity to CPU%d\n",
		       __func__, tmr->evt.irq, cpu);
		BUG();
	}
#endif
	enable_irq(tmr->evt.irq);
	return 0;
}

static int tegra210_timer_stop(unsigned int cpu)
{
        struct tegra210_tmr *tmr = &tke->tegra210_tmr[cpu];

        _shutdown(tmr);
        disable_irq_nosync(tmr->evt.irq);

	return 0;
}

static int tegra210_timer_suspend(void)
{
        int cpu = smp_processor_id();
        struct tegra210_tmr *tmr = &tke->tegra210_tmr[cpu];

        _shutdown(tmr);

        return 0;

}

static void tegra210_timer_resume(void)
{
	__raw_writel(usec_config, tegra210_timer_reg_base + TMRCSSR);
}

static struct syscore_ops tegra210_timer_syscore_ops = {
	.suspend = tegra210_timer_suspend,
	.resume = tegra210_timer_resume,
};

static int __init tegra210_timer_init(struct device_node *np)
{
	int cpu;
	struct tegra210_tmr *tmr;
	u32 tmr_count;
	u32 freq;
	int irq_count;
	unsigned long tmr_index, irq_index;

	/* Allocate the driver struct */
	tke = vmalloc(sizeof(*tke));
	BUG_ON(!tke);
	memset(tke, 0, sizeof(*tke));

	/* MAp MMIO */
	tke->reg_base = of_iomap(np, 0);
	tegra210_timer_reg_base = tke->reg_base;
	if (!tke->reg_base) {
		pr_err("%s: can't map timer registers\n", __func__);
		BUG();
	}

	/* Read the parameters */
	BUG_ON(of_property_read_u32(np, "tmr-count", &tmr_count));
	irq_count = of_irq_count(np);

	BUG_ON(of_property_read_u32(np, "clock-frequency", &freq));

        /*
         * Configure microsecond timers to have 1MHz clock
         * Config register is 0xqqww, where qq is "dividend", ww is "divisor"
         * Uses n+1 scheme
         */
        switch (freq) {
        case 12000000:
                usec_config = 0x000b; /* (11+1)/(0+1) */
                break;
        case 12800000:
                usec_config = 0x043f; /* (63+1)/(4+1) */
                break;
        case 13000000:
                usec_config = 0x000c; /* (12+1)/(0+1) */
                break;
        case 16800000:
                usec_config = 0x0453; /* (83+1)/(4+1) */
                break;
        case 19200000:
                usec_config = 0x045f; /* (95+1)/(4+1) */
                break;
        case 26000000:
                usec_config = 0x0019; /* (25+1)/(0+1) */
                break;
        case 38400000:
                usec_config = 0x04bf; /* (191+1)/(4+1) */
                break;
        case 48000000:
                usec_config = 0x002f; /* (47+1)/(0+1) */
                break;
        default:
                BUG();
        }

	tmr_index = 0;
	for_each_possible_cpu(cpu) {
		tmr = &tke->tegra210_tmr[cpu];
		tmr->tke = tke;
		tmr->tmr_index = tmr_index;
		tmr->freq = freq;

		/* Allocate a TMR */
		BUG_ON(tmr_index >= tmr_count);
		tmr->reg_base = tke->reg_base + TIMER_FOR_CPU(cpu);

		/* Allocate an IRQ */
		irq_index = tmr_index;
		BUG_ON(irq_index >= irq_count);
		tmr->evt.irq = irq_of_parse_and_map(np, cpu);
		BUG_ON(!tmr->evt.irq);

		/* Configure OSC as the TKE source */
		__raw_writel(usec_config, tmr->reg_base + TMRCSSR);

		snprintf(tmr->name, sizeof(tmr->name), "tegra210_timer%d", cpu);
		tmr->evt.name = tmr->name;
		tmr->evt.cpumask = cpumask_of(cpu);
		tmr->evt.features = CLOCK_EVT_FEAT_PERIODIC |
			CLOCK_EVT_FEAT_ONESHOT;
		tmr->evt.set_next_event     = tegra210_timer_set_next_event;
		tmr->evt.set_state_shutdown = tegra210_timer_shutdown;
		tmr->evt.set_state_periodic = tegra210_timer_set_periodic;
		tmr->evt.set_state_oneshot  = tegra210_timer_shutdown;
		tmr->evt.tick_resume        = tegra210_timer_shutdown;

		/* want to be preferred over arch timers */
		tmr->evt.rating = 460;
		irq_set_status_flags(tmr->evt.irq, IRQ_NOAUTOEN | IRQ_PER_CPU);
		if (request_irq(tmr->evt.irq, tegra210_timer_isr,
				  IRQF_TIMER | IRQF_NOBALANCING,
				  tmr->name, tmr)) {
			pr_err("%s: cannot setup irq %d for CPU%d\n",
				__func__, tmr->evt.irq, cpu);
			BUG();
		}
		tmr_index++;
	}

        clocks_calc_mult_shift(&timer_us_mult, &timer_us_shift,
                                freq, USEC_PER_SEC, 0);


	cpuhp_setup_state(CPUHP_AP_TEGRA_TIMER_STARTING,
			  "AP_TEGRA_TIMER_STARTING", tegra210_timer_setup,
			  tegra210_timer_stop);

	register_syscore_ops(&tegra210_timer_syscore_ops);

	return 0;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
CLOCKSOURCE_OF_DECLARE(tegra210_timer, "nvidia,tegra210-timer",
		       tegra210_timer_init);
#else
TIMER_OF_DECLARE(tegra210_timer, "nvidia,tegra210-timer",
		       tegra210_timer_init);
#endif
