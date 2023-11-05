/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Generic PWM backlight driver data - see drivers/video/backlight/pwm_bl.c
 */
#ifndef __LINUX_PWM_BACKLIGHT_H
#define __LINUX_PWM_BACKLIGHT_H

#include <linux/backlight.h>

struct pwm_bl_data {
        struct pwm_device       *pwm;
        struct device           *dev;
        unsigned int            period;
        unsigned int            lth_brightness;
        unsigned int            *levels;
        bool                    enabled;
        struct regulator        *power_supply;
        struct gpio_desc        *enable_gpio;
        unsigned int            scale;
        bool                    legacy;
        unsigned int            post_pwm_on_delay;
        unsigned int            pwm_off_delay;
        unsigned int            pwm_gpio;
        u8                      *bl_measured;
        int                     (*notify)(struct device *,
                                          int brightness);
        void                    (*notify_after)(struct device *,
                                        int brightness);
        int                     (*check_fb)(struct device *, struct fb_info *);
        void                    (*exit)(struct device *);
};

struct pwm_bl_data_dt_ops {
        int (*init)(struct device *dev);
        int (*notify)(struct device *, int brightness);
        void (*notify_after)(struct device *, int brightness);
        int (*check_fb)(struct device *, struct fb_info *);
        void (*exit)(struct device *);
        const char *blnode_compatible;
};


struct platform_pwm_backlight_data {
	int pwm_id;
	unsigned int max_brightness;
	unsigned int dft_brightness;
	unsigned int lth_brightness;
	unsigned int pwm_period_ns;
	unsigned int *levels;
	unsigned int post_pwm_on_delay;
	unsigned int pwm_off_delay;
	unsigned int pwm_gpio;
        u8 *bl_measured;
	int (*init)(struct device *dev);
	int (*notify)(struct device *dev, int brightness);
	void (*notify_after)(struct device *dev, int brightness);
	void (*exit)(struct device *dev);
	int (*check_fb)(struct device *dev, struct fb_info *info);
};

#endif
