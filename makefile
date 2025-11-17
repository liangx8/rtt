
OBJ_DIR=obj

ARCH=arm-none-eabi-

F421LIBS=f421
MCUS=f421 e230

CC=${ARCH}gcc
AS=${ARCH}as
OBJCOPY=${ARCH}objcopy
OBJDUMP=${ARCH}objdump
SIZE=${ARCH}size

ST_FLASH=st-flash
OUTPUT_FORMAT=ihex
ifeq (${MCU}X,X)
	MCU=f421
endif

SOURCE:=$(wildcard src/*.[cS])
SOURCE+=$(wildcard rtt/*.[cS])

ELF=main.elf
HEX=main.hex
BIN=main.bin
DISA_LIST=main.lst

ifeq (${OPTC}X,X)
	OPTC=-O2
endif
include ${MCU}/mcu.mk
CFLAGS:=-Iinc
CFLAGS+= ${PORT} ${CPUFREQ} ${OPTC} -Wall
CFLAGS+=-Werror
CFLAGS+=${CFLAGS_MCU}
#CFLAGS+=-Wundef -Wl,--gc-sections
#CFLAGS+=-Wextra -specs=nano.specs -MMD -MP
SOURCE+=$(SOURCE_MCU)

# -nostdlib会导致一些编译错误。缺省的内置函数如果不能用简单的方法实现时，会调用标准函数。如memset
# 连接的时候加 -mthumb让连接器在连接的时候，一些标准函数使用 thumb标准库
LFLAGS=-T ${LINKER_SCRIPTS}
LFLAGS+=${PORT}
LFLAGS+=-nostartfiles
LFLAGS+=-nostdlib
LFLAGS+=--specs=nosys.specs
LFLAGS+=-Wl,--print-memory-usage
LFLAGS+=-lnosys


#把.c .S后缀改成.o
OBJS=${addsuffix .o,$(basename ${SOURCE})}


all:${HEX}
#	@echo ${CSOURCE}
#	@echo ${ASOURCE}
#	@echo ${OBJS_WITHPATH}
#	@echo ${OBJS}
${BIN}:${ELF}
	${OBJCOPY} -O binary $< $@
${HEX}:${ELF}
	${OBJCOPY} -O ihex $< $@

${ELF}:${OBJS}
	${CC} -o $@ ${LFLAGS} ${OBJS}
	${SIZE} $@
	${OBJDUMP} -D $@ > main.lst



######################################################################
## 以下的是需要把全部程序文件放在同一个目录下面
#${OBJ_DIR}/%.o:%.c
#	${CC} ${CFLAGS} -c $< -o $@
#${OBJ_DIR}/%.o:%.s
#	${AS} ${PORT} -c $< -o $@
#
######################################################################
.c.o:
	$(CC) -c $< ${CFLAGS} -o $@
.S.o:
	${AS} ${PORT} -g $< -o $@
disa:${DISA_LIST}
${DISA_LIST}:${HEX}
	${OBJDUMP} -mcpu=cortex-m4 -b ihex -M force-thumb -EL -D $< > $@

clean:
	rm -rf ${ELF} ${HEX} ${DISA_LIST} ${BIN} *.hex
	find -name \*~ -or -name \*.o -exec rm \{} \;

burn:${HEX}
	${ST_FLASH} erase
	${ST_FLASH} --format ${OUTPUT_FORMAT} write $<
reset_mcu:
	${ST_FLASH} reset
