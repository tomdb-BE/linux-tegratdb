GCOV_PROFILE := y

ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -I$(srctree)/include
ccflags-y += -Werror

nvhost-capture-objs = capture-support.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-capture.o
