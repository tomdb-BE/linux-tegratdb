# SPDX-License-Identifier: GPL-2.0
obj-$(CONFIG_PINCTRL_TEGRA)		+= pinctrl-tegra.o
obj-$(CONFIG_PINCTRL_TEGRA20)		+= pinctrl-tegra20.o
obj-$(CONFIG_PINCTRL_TEGRA30)		+= pinctrl-tegra30.o
obj-$(CONFIG_PINCTRL_TEGRA114)		+= pinctrl-tegra114.o
obj-$(CONFIG_PINCTRL_TEGRA124)		+= pinctrl-tegra124.o
obj-$(CONFIG_PINCTRL_TEGRA210)		+= pinctrl-tegra210.o
obj-$(CONFIG_PINCTRL_TEGRA_XUSB)	+= pinctrl-tegra-xusb.o
GCOV_PROFILE_pinctrl-tegra186-padctl.o := y

ccflags-y += -I$(srctree)/drivers/pinctrl
ccflags-y += -I$(srctree)/drivers/pinctrl/tegra
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/include

obj-$(CONFIG_PINCTRL_TEGRA186)  += pinctrl-tegra186.o
obj-$(CONFIG_PINCTRL_TEGRA186_PADCTL) += pinctrl-tegra186-padctl.o
obj-$(CONFIG_PINCTRL_TEGRA186_DPAUX)  += pinctrl-tegra186-dpaux.o

GCOV_PROFILE_pinctrl-tegra194-padctl.o := y
obj-$(CONFIG_PINCTRL_TEGRA194)  += pinctrl-tegra194.o
obj-$(CONFIG_PINCTRL_TEGRA194_PEXCLK_PADCTL) += pinctrl-tegra194-pexclk-padctrl.o
