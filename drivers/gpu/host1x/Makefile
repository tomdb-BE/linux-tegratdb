# SPDX-License-Identifier: GPL-2.0
host1x-y = \
	bus.o \
	syncpt.o \
	dev.o \
	intr.o \
	cdma.o \
	channel.o \
	job.o \
	debug.o \
	mipi.o \
	fence.o \
	hw/host1x01.o \
	hw/host1x02.o \
	hw/host1x04.o \
	hw/host1x05.o \
	hw/host1x06.o \
	hw/host1x07.o

obj-$(CONFIG_TEGRA_HOST1X) += host1x.o
ccflags-y += -Idrivers/gpu/host1x

host1x-t186-y = \
        dev_t186.o \
        hw/host1x05.o

obj-$(CONFIG_ARCH_TEGRA_18x_SOC) += host1x-t186.o

