# SPDX-License-Identifier: GPL-2.0
#
# Makefile for industrial I/O temperature drivers
#

obj-$(CONFIG_IQS620AT_TEMP) += iqs620at-temp.o
obj-$(CONFIG_LTC2983) += ltc2983.o
obj-$(CONFIG_HID_SENSOR_TEMP) += hid-sensor-temperature.o
obj-$(CONFIG_MAXIM_THERMOCOUPLE) += maxim_thermocouple.o
obj-$(CONFIG_MAX31856) += max31856.o
obj-$(CONFIG_MLX90614) += mlx90614.o
obj-$(CONFIG_MLX90632) += mlx90632.o
obj-$(CONFIG_NVS_TMP1X2_IIO)    += nvs_tmp1x2.o
obj-$(CONFIG_NVS_TMP1X2_INPUT)  += nvs_tmp1x2.o
obj-$(CONFIG_NVS_TMP1X2_RELAY)  += nvs_tmp1x2.o

ifneq (,$(filter $(CONFIG_NVS_TMP1X2_IIO),y m))
CFLAGS_nvs_tmp1x2.o += -DNVS_CFG_KIF=NVS_KIF_IIO
endif

ifneq (,$(filter $(CONFIG_NVS_TMP1X2_INPUT),y m))
CFLAGS_nvs_tmp1x2.o += -DNVS_CFG_KIF=NVS_KIF_INPUT
endif

ifneq (,$(filter $(CONFIG_NVS_TMP1X2_RELAY),y m))
CFLAGS_nvs_tmp1x2.o += -DNVS_CFG_KIF=NVS_KIF_RELAY
endif

obj-$(CONFIG_TMP006) += tmp006.o
obj-$(CONFIG_TMP007) += tmp007.o
obj-$(CONFIG_TMP117) += tmp117.o
obj-$(CONFIG_TSYS01) += tsys01.o
obj-$(CONFIG_TSYS02D) += tsys02d.o
