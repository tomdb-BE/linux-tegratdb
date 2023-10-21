# SPDX-License-Identifier: GPL-2.0
#
# Makefile for industrial I/O Magnetometer sensor drivers
#

# When adding new entries keep the list in alphabetical order
obj-$(CONFIG_AK8974)	+= ak8974.o
obj-$(CONFIG_AK8975)	+= ak8975.o
obj-$(CONFIG_BMC150_MAGN) += bmc150_magn.o
obj-$(CONFIG_BMC150_MAGN_I2C) += bmc150_magn_i2c.o
obj-$(CONFIG_BMC150_MAGN_SPI) += bmc150_magn_spi.o

obj-$(CONFIG_MAG3110)	+= mag3110.o
obj-$(CONFIG_HID_SENSOR_MAGNETOMETER_3D) += hid-sensor-magn-3d.o
obj-$(CONFIG_MMC35240)	+= mmc35240.o

obj-$(CONFIG_IIO_ST_MAGN_3AXIS) += st_magn.o
st_magn-y := st_magn_core.o
st_magn-$(CONFIG_IIO_BUFFER) += st_magn_buffer.o

obj-$(CONFIG_IIO_ST_MAGN_I2C_3AXIS) += st_magn_i2c.o
obj-$(CONFIG_IIO_ST_MAGN_SPI_3AXIS) += st_magn_spi.o

obj-$(CONFIG_NVI_AK89XX) += nvi-ak89xx.o
# Uncomment next line to enable TRACING
# CFLAGS_nvi_ak89xx.o     += -DENABLE_TRACE
#
ifneq (,$(filter $(CONFIG_NVI_AK89XX),m))
# Uncomment next line to enable TRACING
# CFLAGS_nvi_ak89xx.o     += -DCREATE_TRACE_POINTS
#
endif

ifneq (,$(filter $(CONFIG_NVI_MPU_IIO),y m))
        CFLAGS_nvi_ak89xx.o += -DAKM_NVI_MPU_SUPPORT=1
endif
ifneq (,$(filter $(CONFIG_NVI_MPU_INPUT),y m))
        CFLAGS_nvi_ak89xx.o += -DAKM_NVI_MPU_SUPPORT=1
endif
ifneq (,$(filter $(CONFIG_NVI_MPU_RELAY),y m))
        CFLAGS_nvi_ak89xx.o += -DAKM_NVI_MPU_SUPPORT=1
endif
nvi-ak89xx-objs += nvi_ak89xx.o

obj-$(CONFIG_SENSORS_HMC5843)		+= hmc5843_core.o
obj-$(CONFIG_SENSORS_HMC5843_I2C)	+= hmc5843_i2c.o
obj-$(CONFIG_SENSORS_HMC5843_SPI)	+= hmc5843_spi.o

obj-$(CONFIG_SENSORS_RM3100)		+= rm3100-core.o
obj-$(CONFIG_SENSORS_RM3100_I2C)	+= rm3100-i2c.o
obj-$(CONFIG_SENSORS_RM3100_SPI)	+= rm3100-spi.o

obj-$(CONFIG_YAMAHA_YAS530)		+= yamaha-yas530.o
