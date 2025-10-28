
OBJ_DIR=obj

ARCH=arm-none-eabi-

F421LIBS=f421

CC=${ARCH}gcc
AS=${ARCH}as
OBJCOPY=${ARCH}objcopy
OBJDUMP=${ARCH}objdump
SIZE=${ARCH}size

ST_FLASH=st-flash
OUTPUT_FORMAT=ihex

LINKER_SCRIPTS=${F421LIBS}/cmsis/cm4/device_support/startup/gcc/linker/AT32F421x8_FLASH.ld

CSOURCE=$(shell find -name \*.c -and -type f)
ASOURCE=$(shell find -name \*.S -and -type f)
SOURCE=${CSOURCE} ${ASOURCE}
ELF=main.elf
HEX=main.hex
BIN=main.bin
DISA_LIST=main.lst

OBJS_WITHPATH=${CSOURCE:.c=.o} ${ASOURCE:.S=.o}
OBJS=${addprefix ${OBJ_DIR}/,${notdir ${OBJS_WITHPATH}}}

#PORT=-mcpu=cortex-m3  -mthumb # -mlittle-endian
PORT=-mcpu=cortex-m4 -mthumb # -mlittle-endian
CPUFREQ=-DCPUCLK=120
ifeq (${OPTC}X,X)
	OPTC=-O2
endif

CFLAGS= ${PORT} ${CPUFREQ} ${OPTC} -Wall
CFLAGS+=-Werror
#CFLAGS+=-Wundef -Wl,--gc-sections
#CFLAGS+=-Wextra -specs=nano.specs -MMD -MP
CFLAGS+=-I${F421LIBS}/cmsis/cm4/device_support
CFLAGS+=-I${F421LIBS}/cmsis/cm4/core_support
CFLAGS+=-I${F421LIBS}/drivers/inc
CFLAGS+=-Iinc
CFLAGS+=-DAT32F421C8T7


# -nostdlib会导致一些编译错误。缺省的内置函数如果不能用简单的方法实现时，会调用标准函数。如memset
# 连接的时候加 -mthumb让连接器在连接的时候，一些标准函数使用 thumb标准库
LFLAGS=-T ${LINKER_SCRIPTS}
LFLAGS+=${PORT}
LFLAGS+=-nostartfiles
LFLAGS+=-nostdlib
LFLAGS+=--specs=nosys.specs
LFLAGS+=-Wl,--print-memory-usage
LFLAGS+=-lnosys
all: mkobj ${HEX}
#	@echo ${CSOURCE}
#	@echo ${ASOURCE}
#	@echo ${OBJS_WITHPATH}
#	@echo ${OBJS}
${BIN}:${ELF}
	${OBJCOPY} -O binary $< $@
${HEX}:${ELF}
	${OBJCOPY} -O ihex $< $@
mkobj:
	@mkdir -p ${OBJ_DIR}
${ELF}:${OBJS}
	${CC} -o $@ ${LFLAGS} ${OBJS}
	${SIZE} $@
	${OBJDUMP} -D $@ > main.lst

######################################################################
## 把代码文件所在的目录映射到OBJ_DIR，

define BUILD_c
td = ${OBJ_DIR}/${shell basename -s .c ${shell basename ${1}}}.o
$${td}:${1}
	${CC} ${CFLAGS} -c $$< -o $$@
endef
define BUILD_asm
td = ${OBJ_DIR}/${shell basename -s .S ${shell basename ${1}}}.o
$${td}:${1}
	${AS} ${PORT} $$< -o $$@
endef
$(foreach prog,$(CSOURCE),$(eval $(call BUILD_c  ,$(prog))))
$(foreach pro1,$(ASOURCE),$(eval $(call BUILD_asm,$(pro1))))


######################################################################

######################################################################
## 以下的是需要把全部程序文件放在同一个目录下面
#${OBJ_DIR}/%.o:%.c
#	${CC} ${CFLAGS} -c $< -o $@
#${OBJ_DIR}/%.o:%.s
#	${AS} ${PORT} -c $< -o $@
#
######################################################################

disa:${DISA_LIST}
${DISA_LIST}:${HEX}
	${OBJDUMP} -mcpu=cortex-m4 -b ihex -M force-thumb -EL -D $< > $@

clean:
	rm -rf ${ELF} ${HEX} ${DISA_LIST} ${BIN}
#	find -name \*~ -exec rm \{} \; -or -name \*.o -exec rm \{} \;
	rm -rf obj

burn:${HEX}
	${ST_FLASH} erase
	${ST_FLASH} --format ${OUTPUT_FORMAT} write $<
reset_mcu:
	${ST_FLASH} reset
