LINKER_SCRIPTS=${MCU}/cmsis/cm4/device_support/startup/gcc/linker/AT32F421x8_FLASH.ld
PORT=-mcpu=cortex-m4 -mthumb # -mlittle-endian
CPUFREQ=-DCPUCLK=120
CFLAGS_MCU:=-I${MCU}/cmsis/cm4/device_support
CFLAGS_MCU+=-I${MCU}/cmsis/cm4/core_support
CFLAGS_MCU+=-I${MCU}/drivers/inc
CFLAGS_MCU+=-DAT32F421C8T7

SOURCE_MCU=${MCU}/cmsis/cm4/device_support/startup/gcc/startup_at32f421.S
