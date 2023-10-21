# SPDX-License-Identifier: GPL-2.0
obj-y += amd/ intel/ arm/
obj-$(CONFIG_IOMMU_API) += iommu.o
obj-$(CONFIG_IOMMU_API) += iommu-traces.o
obj-$(CONFIG_IOMMU_API) += iommu-sysfs.o
obj-$(CONFIG_IOMMU_DEBUGFS) += iommu-debugfs.o
obj-$(CONFIG_IOMMU_DMA) += dma-iommu.o
obj-$(CONFIG_IOMMU_IO_PGTABLE) += io-pgtable.o
obj-$(CONFIG_IOMMU_IO_PGTABLE_ARMV7S) += io-pgtable-arm-v7s.o
obj-$(CONFIG_IOMMU_IO_PGTABLE_LPAE) += io-pgtable-arm.o
obj-$(CONFIG_IOASID) += ioasid.o
obj-$(CONFIG_IOMMU_IOVA) += iova.o
obj-$(CONFIG_OF_IOMMU)	+= of_iommu.o
obj-$(CONFIG_MSM_IOMMU) += msm_iommu.o
obj-$(CONFIG_IPMMU_VMSA) += ipmmu-vmsa.o
obj-$(CONFIG_IRQ_REMAP) += irq_remapping.o
obj-$(CONFIG_MTK_IOMMU) += mtk_iommu.o
obj-$(CONFIG_MTK_IOMMU_V1) += mtk_iommu_v1.o
obj-$(CONFIG_OMAP_IOMMU) += omap-iommu.o
obj-$(CONFIG_OMAP_IOMMU_DEBUG) += omap-iommu-debug.o
obj-$(CONFIG_ROCKCHIP_IOMMU) += rockchip-iommu.o
obj-$(CONFIG_SUN50I_IOMMU) += sun50i-iommu.o
obj-$(CONFIG_TEGRA_IOMMU_GART) += tegra-gart.o
obj-$(CONFIG_TEGRA_IOMMU_SMMU) += tegra-smmu.o
obj-$(CONFIG_EXYNOS_IOMMU) += exynos-iommu.o
obj-$(CONFIG_FSL_PAMU) += fsl_pamu.o fsl_pamu_domain.o
obj-$(CONFIG_S390_IOMMU) += s390-iommu.o
obj-$(CONFIG_HYPERV_IOMMU) += hyperv-iommu.o
obj-$(CONFIG_VIRTIO_IOMMU) += virtio-iommu.o
obj-$(CONFIG_IOMMU_SVA_LIB) += iommu-sva-lib.o io-pgfault.o
obj-$(CONFIG_SPRD_IOMMU) += sprd-iommu.o
obj-$(CONFIG_APPLE_DART) += apple-dart.o
ifdef CONFIG_ARCH_TEGRA_19x_SOC

ccflags-y += -Werror
ccflags-y += -I$(srctree)/drivers/iommu

obj-$(CONFIG_TEGRA_ARM_SMMU_T19x) += arm-smmu-t19x.o
obj-$(CONFIG_ARM_SMMU) += arm-smmu-regs.o
obj-$(CONFIG_ARM_SMMU) += of_tegra-smmu.o
obj-y += dma-override.o

endif

obj-$(CONFIG_ARM_SMMU_SUSPEND) += arm-smmu-suspend.o
obj-$(CONFIG_OF_IOMMU) += of_tegra-smmu.o

