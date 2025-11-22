
OBJ_DIR=obj

ARCH=arm-none-eabi-

CC=${ARCH}gcc
AS=${ARCH}as
OBJCOPY=${ARCH}objcopy
OBJDUMP=${ARCH}objdump
SIZE=${ARCH}size
AWK=gawk
ST_FLASH=st-flash
OUTPUT_FORMAT=ihex
ELF      =${OBJ_DIR}/${TARGET}.elf
HEX      =${OBJ_DIR}/${TARGET}.hex
BIN      =${OBJ_DIR}/${TARGET}.bin
DISA_LIST=${OBJ_DIR}/${TARGET}.lst
ifeq (${OPTC}X,X)
	OPTC=-O2
endif
CFLAGS:=-Iinc
#CFLAGS+=-Wundef -Wl,--gc-sections
#CFLAGS+=-Wextra -specs=nano.specs -MMD -MP
SOURCE:=$(wildcard src/*.[cS])
SOURCE+=$(wildcard rtt/*.[cS])

include mcu/$(TARGET)/mcu.mk
#MCU_TYPE=$(shell echo $(TARGET) | tr  '[:lower:]' '[:upper:]')
MCU_TYPE=$(shell echo $(TARGET) | ${AWK} '{print toupper($$0)}')
CFLAGS+=${PORT}
CFLAGS+=${CPUFREQ}
CFLAGS+=${OPTC}
CFLAGS+=-Wall
CFLAGS+=-Werror
CFLAGS+=-D${MCU_TYPE}=1

# -nostdlib会导致一些编译错误。缺省的内置函数如果不能用简单的方法实现时，会调用标准函数。如memset
# 连接的时候加 -mthumb让连接器在连接的时候，一些标准函数使用 thumb标准库
LFLAGS=-T${LINKER_SCRIPTS}
LFLAGS+=${PORT}
LFLAGS+=-nostartfiles
LFLAGS+=-nostdlib
LFLAGS+=--specs=nosys.specs
LFLAGS+=-Wl,--print-memory-usage
LFLAGS+=-lnosys

COMPILEARGS_TMP=cargs.tmp
#把.c .S后缀改成.o
OBJS=${addsuffix .o,$(basename ${SOURCE})}

$(file >${COMPILEARGS_TMP})
$(foreach xx, ${CFLAGS},$(file >>${COMPILEARGS_TMP},${xx}))

all:${HEX} ${BIN} ${DISA_LIST}
#	@echo ${CSOURCE}
#	@echo ${ASOURCE}
#	@echo ${OBJS_WITHPATH}
#	@echo ${OBJS}
${BIN}:${ELF}
	${OBJCOPY} -O binary $< $@
${HEX}:${ELF}
	${OBJCOPY} -O ${OUTPUT_FORMAT} $< $@
LINKARGS_TMP=largs.tmp
${ELF}:${OBJS}
	@cat ${COMPILEARGS_TMP}
	@rm ${COMPILEARGS_TMP}
	$(file >$(LINKARGS_TMP))
	$(foreach obj,$^,$(file >>$(LINKARGS_TMP),${obj}))
	$(foreach obj,${LFLAGS},$(file >>$(LINKARGS_TMP),${obj}))
	@mkdir -p ${OBJ_DIR}
	${CC} @$(LINKARGS_TMP) -o $@
	${SIZE} $@
	@rm $(LINKARGS_TMP)
	



######################################################################
## 以下的是需要把全部程序文件放在同一个目录下面
#${OBJ_DIR}/%.o:%.c
#	${CC} ${CFLAGS} -c $< -o $@
#${OBJ_DIR}/%.o:%.s
#	${AS} ${PORT} -c $< -o $@
#
######################################################################
.c.o:
	$(CC) @${COMPILEARGS_TMP} -o $@ -c $<
.S.o:
	${AS} ${PORT} -g $< -o $@
disa:${DISA_LIST}
${DISA_LIST}:${HEX}
	${OBJDUMP} -m${DIS_ARCH} -b ${OUTPUT_FORMAT} -M force-thumb -EL -D $< > $@


burn:${HEX}
	${ST_FLASH} erase
	${ST_FLASH} --format ${OUTPUT_FORMAT} write $<
reset_mcu:
	${ST_FLASH} reset
