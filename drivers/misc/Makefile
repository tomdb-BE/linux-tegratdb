# SPDX-License-Identifier: GPL-2.0
#
# Makefile for misc devices that really don't fit anywhere else.
#

obj-$(CONFIG_IBM_ASM)		+= ibmasm/
obj-$(CONFIG_IBMVMC)		+= ibmvmc.o
obj-$(CONFIG_AD525X_DPOT)	+= ad525x_dpot.o
obj-$(CONFIG_AD525X_DPOT_I2C)	+= ad525x_dpot-i2c.o
obj-$(CONFIG_AD525X_DPOT_SPI)	+= ad525x_dpot-spi.o
obj-$(CONFIG_ATMEL_SSC)		+= atmel-ssc.o
obj-$(CONFIG_DUMMY_IRQ)		+= dummy-irq.o
obj-$(CONFIG_ICS932S401)	+= ics932s401.o
obj-$(CONFIG_LKDTM)		+= lkdtm/
obj-$(CONFIG_TIFM_CORE)       	+= tifm_core.o
obj-$(CONFIG_TIFM_7XX1)       	+= tifm_7xx1.o
obj-$(CONFIG_PHANTOM)		+= phantom.o
obj-$(CONFIG_QCOM_COINCELL)	+= qcom-coincell.o
obj-$(CONFIG_QCOM_FASTRPC)	+= fastrpc.o
obj-$(CONFIG_SENSORS_BH1770)	+= bh1770glc.o
obj-$(CONFIG_SENSORS_APDS990X)	+= apds990x.o
obj-$(CONFIG_ENCLOSURE_SERVICES) += enclosure.o
obj-$(CONFIG_KGDB_TESTS)	+= kgdbts.o
obj-$(CONFIG_SGI_XP)		+= sgi-xp/
obj-$(CONFIG_SGI_GRU)		+= sgi-gru/
obj-$(CONFIG_CS5535_MFGPT)	+= cs5535-mfgpt.o
obj-$(CONFIG_GEHC_ACHC)		+= gehc-achc.o
obj-$(CONFIG_HP_ILO)		+= hpilo.o
obj-$(CONFIG_APDS9802ALS)	+= apds9802als.o
obj-$(CONFIG_ISL29003)		+= isl29003.o
obj-$(CONFIG_ISL29020)		+= isl29020.o
obj-$(CONFIG_SENSORS_TSL2550)	+= tsl2550.o
obj-$(CONFIG_DS1682)		+= ds1682.o
obj-$(CONFIG_C2PORT)		+= c2port/
obj-$(CONFIG_HMC6352)		+= hmc6352.o
obj-y				+= eeprom/
obj-y				+= cb710/
obj-$(CONFIG_VMWARE_BALLOON)	+= vmw_balloon.o
obj-$(CONFIG_PCH_PHUB)		+= pch_phub.o
obj-y				+= ti-st/
obj-y				+= lis3lv02d/
obj-$(CONFIG_ALTERA_STAPL)	+=altera-stapl/
obj-$(CONFIG_INTEL_MEI)		+= mei/
obj-$(CONFIG_VMWARE_VMCI)	+= vmw_vmci/
obj-$(CONFIG_LATTICE_ECP3_CONFIG)	+= lattice-ecp3-config.o
obj-$(CONFIG_SRAM)		+= sram.o
obj-$(CONFIG_SRAM_EXEC)		+= sram-exec.o
obj-$(CONFIG_GENWQE)		+= genwqe/
obj-$(CONFIG_ECHO)		+= echo/
obj-$(CONFIG_CXL_BASE)		+= cxl/
obj-$(CONFIG_DW_XDATA_PCIE)	+= dw-xdata-pcie.o
obj-$(CONFIG_PCI_ENDPOINT_TEST)	+= pci_endpoint_test.o
obj-$(CONFIG_OCXL)		+= ocxl/
obj-$(CONFIG_BCM_VK)		+= bcm-vk/
obj-y				+= cardreader/
obj-$(CONFIG_PVPANIC)   	+= pvpanic/
obj-$(CONFIG_HABANA_AI)		+= habanalabs/
obj-$(CONFIG_UACCE)		+= uacce/
obj-$(CONFIG_XILINX_SDFEC)	+= xilinx_sdfec.o
obj-$(CONFIG_HISI_HIKEY_USB)	+= hisi_hikey_usb.o
obj-$(CONFIG_HI6421V600_IRQ)	+= hi6421v600-irq.o

obj-$(CONFIG_MODS) += mods/
obj-$(CONFIG_NVS) += nvs/
obj-$(CONFIG_NVS_AON_SHUB) += nvs-aonsh/
obj-$(CONFIG_TEGRA_PROFILER) += tegra-profiler/

obj-$(CONFIG_NVS_DFSH) += nvs-dfsh/
obj-$(CONFIG_BLUEDROID_PM)      += bluedroid_pm.o
obj-$(CONFIG_SENSORS_NCT1008)   += nct1008.o
obj-$(CONFIG_SENSORS_PEX9749)   += pex9749.o
obj-$(CONFIG_TEGRA_CPC)         += tegra_cpc.o
obj-$(CONFIG_THERM_EST)         += therm_est.o
obj-$(CONFIG_FAN_THERM_EST)     += therm_fan_est.o
obj-$(CONFIG_EQOS_APE_HWDEP) += eqos_ape/
obj-$(CONFIG_TEGRA_ACSL)        += nv_acsl/
obj-$(CONFIG_TEGRA_SKIN)        += tegra-skin.o
obj-$(CONFIG_TEGRA186_AHC) += tegra186-ahc/
obj-$(CONFIG_EVENTLIB)          += eventlib/
obj-$(CONFIG_NVSCIC2C_PCIE)     += nvscic2c-pcie/
obj-$(CONFIG_NVSCIIPC)          += nvsciipc/
obj-$(CONFIG_TEGRA_PCIE_DMA_TEST)       += tegra-pcie-dma-test.o

ifdef CONFIG_ARCH_TEGRA_19x_SOC

obj-$(CONFIG_TEGRA_PCIE_EP_MEM) += tegra-pcie-ep-mem.o

endif

