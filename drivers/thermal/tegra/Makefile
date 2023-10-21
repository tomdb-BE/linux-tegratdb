# SPDX-License-Identifier: GPL-2.0
obj-$(CONFIG_TEGRA_SOCTHERM)		+= tegra-soctherm.o
obj-$(CONFIG_TEGRA_BPMP_THERMAL)	+= tegra-bpmp-thermal.o
obj-$(CONFIG_TEGRA30_TSENSOR)		+= tegra30-tsensor.o

tegra-soctherm-y				:= soctherm.o soctherm-fuse.o
tegra-soctherm-$(CONFIG_ARCH_TEGRA_124_SOC)	+= tegra124-soctherm.o
tegra-soctherm-$(CONFIG_ARCH_TEGRA_132_SOC)	+= tegra132-soctherm.o
tegra-soctherm-$(CONFIG_ARCH_TEGRA_210_SOC)	+= tegra210-soctherm.o

obj-$(CONFIG_TEGRA_AOTAG)       += aotag.o
obj-$(CONFIG_TEGRA_TJ_THERMAL)  += tegra_tj_thermal.o
obj-$(CONFIG_TEGRA_CORE_CAPS)   += tegra-core-action.o
obj-$(CONFIG_TEGRA_DFLL_CAPS)   += tegra-dfll-action.o

