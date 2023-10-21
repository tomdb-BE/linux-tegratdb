# SPDX-License-Identifier: GPL-2.0
obj-y += fuse/

obj-y += common.o
obj-$(CONFIG_SOC_TEGRA_FLOWCTRL) += flowctrl.o
obj-$(CONFIG_SOC_TEGRA_PMC) += pmc.o
obj-$(CONFIG_SOC_TEGRA_POWERGATE_BPMP) += powergate-bpmp.o
obj-$(CONFIG_SOC_TEGRA20_VOLTAGE_COUPLER) += regulators-tegra20.o
obj-$(CONFIG_SOC_TEGRA30_VOLTAGE_COUPLER) += regulators-tegra30.o
obj-y += tegra-bpmp-dvfs.o
obj-$(CONFIG_DEBUG_FS) += tegra-bpmp-ec.o
obj-$(CONFIG_ARCH_TEGRA_210_SOC)        += pm-tegra210.o
obj-$(CONFIG_TEGRA_PROC_POWER_MODEL)    += tegra-ppm.o
