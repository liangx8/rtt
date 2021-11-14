#CC=d:/p/mcu_dev/sdcc/bin/sdcc
ARCH=arm-none-eabi

CC=${ARCH}-gcc
AS=${ARCH}-as
OBJCOPY=${ARCH}-objcopy
OBJDUMP=${ARCH}-objdump
SIZE=${ARCH}-size

ST_FLASH=st-flash
OUTPUT_FORMAT=ihex

LINKER_SCRIPTS=cmsis/stm32.ld

CSOURCE=$(shell find -name \*.c -and -type f)
CSOURCE+=$(shell ls ../src/*.c)
ASOURCE=$(shell find -name \*.S -and -type f)
ASOURCE+=$(shell ls ../src/*.S)
ELF=main.elf
HEX=main.hex
BIN=main.bin
DISA_LIST=main.lst


OBJS=${CSOURCE:.c=.o} ${ASOURCE:.S=.o}

#PORT=-mcpu=cortex-m3  -mthumb # -mlittle-endian
PORT=-mcpu=cortex-m3 -mthumb # -mlittle-endian
CPUFREQ=-DCPUCLK=72000000
OPTC=-O2
CFLAGS= ${PORT} ${CPUFREQ} ${OPTC} -Wall -Wa,-mimplicit-it=always -DNDEBUG -DSTM32F103xB
CFLAGS+=-I./ -I./cmsis/include
CFLAGS+=-I../src
# -nostdlib会导致一些编译错误。缺省的内置函数如果不能用简单的方法实现时，会调用标准函数。如memset
# 连接的时候加 -mthumb让连接器在连接的时候，一些标准函数使用 thumb标准库
LFLAGS= -T ${LINKER_SCRIPTS} ${PORT} -nostartfiles -nostdlib # --specs=nosys.specs
all:${HEX}
${BIN}:${ELF}
	${OBJCOPY} -O binary $< $@
${HEX}:${ELF}
	${OBJCOPY} -O ihex $< $@
${ELF}:${OBJS}
	${CC} -o $@ ${LFLAGS} ${OBJS} 
	${SIZE} $@
	${OBJDUMP} -D $@ > main.lst
.c.o:
	${CC} ${CFLAGS} -c $< -o $@
.S.o:
	${AS} ${PORT} -g $< -o $@
disa:${DISA_LIST}
${DISA_LIST}:${HEX}
	${OBJDUMP} -marm -b ihex -M force-thumb -EL -D $< > $@

clean:
	rm -rf ${ELF} ${HEX} ${DISA_LIST} ${BIN}
	rm ../src/*.o
	find -name \*~ -or -name \*.o -exec rm \{} \;
burn:${HEX}
	${ST_FLASH} erase
	${ST_FLASH} --format ${OUTPUT_FORMAT} write $<
reset_mcu:
	${ST_FLASH} reset
