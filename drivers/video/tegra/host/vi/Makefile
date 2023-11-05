GCOV_PROFILE := y

ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -I$(srctree)/include

CONFIG_VIDEO_TEGRA_VI := y
obj-$(CONFIG_VIDEO_TEGRA_VI) += host_vi_notify.o
obj-$(CONFIG_VIDEO_TEGRA_VI) += vi_notify.o

ccflags-y += -Werror

obj-y += vi5.o

#obj-$(CONFIG_VIDEO_TEGRA_VI) += nvhost-vi5.o
