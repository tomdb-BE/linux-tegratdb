GCOV_PROFILE := y

ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -I$(srctree)/include
ccflags-y += -Werror

nvhost-slvsec-objs = slvsec.o

obj-$(CONFIG_TEGRA_GRHOST_SLVSEC) += nvhost-slvsec.o
