GCOV_PROFILE := y
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/video/tegra/camera
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -Werror

nvhost-vi-objs += vi.o
nvhost-vi-objs += vi_irq.o
nvhost-vi-objs += tegra_vi.o

obj-$(CONFIG_VIDEO_TEGRA_VI) += nvhost-vi.o
