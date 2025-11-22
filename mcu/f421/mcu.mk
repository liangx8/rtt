MCU=f421

PARENT:=mcu/$(MCU)
LINKER_SCRIPTS=${PARENT}/cmsis/cm4/device_support/startup/gcc/linker/AT32F421x8_FLASH.ld
PORT=-mcpu=cortex-m4 -mthumb # -mlittle-endian
CPUFREQ=-DCPUCLK=120
CFLAGS+=-I${PARENT}/cmsis/cm4/device_support
CFLAGS+=-I${PARENT}/cmsis/cm4/core_support
CFLAGS+=-I${PARENT}/drivers/inc
CFLAGS+=-DAT32F421C8T7
DIS_ARCH:=cortex-m4
SOURCE+=${PARENT}/cmsis/cm4/device_support/startup/gcc/startup_at32f421.S
