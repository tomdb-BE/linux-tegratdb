GCOV_PROFILE := y
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/video/tegra/camera
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -I$(srctree)/include
ccflags-y += -Werror

obj-$(CONFIG_TEGRA_CAMERA_RTCPU) += capture-common.o
obj-$(CONFIG_TEGRA_CAMERA_RTCPU) += capture-vi.o
obj-$(CONFIG_TEGRA_CAMERA_RTCPU) += capture-vi-channel.o
obj-$(CONFIG_TEGRA_CAMERA_RTCPU) += capture-isp.o
obj-$(CONFIG_TEGRA_CAMERA_RTCPU) += capture-isp-channel.o
