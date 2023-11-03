GCOV_PROFILE := y
ccflags-y += -I$(srctree)/drivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -I$(srctree)/drivers/media/platform/tegra
ccflags-y += -I$(srctree)/include
ccflags-y += -Werror

nvhost-nvcsi-objs  = \
		nvcsi.o \
		deskew.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-nvcsi.o

nvhost-nvcsi-t194-objs = nvcsi-t194.o

obj-$(CONFIG_TEGRA_GRHOST_NVCSI) += nvhost-nvcsi-t194.o
