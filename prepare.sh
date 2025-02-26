#!/bin/sh
DST=f421
rm -rf ${DST}
mkdir -p ${DST}/cmsis/cm4/device_support/startup/gcc/linker
mkdir -p ${DST}/cmsis/cm4/core_support/
mkdir    ${DST}/drivers
F421LIB=${HOME}/libs/libraries

cp ${F421LIB}/cmsis/cm4/device_support/* ${DST}/cmsis/cm4/device_support
cp ${F421LIB}/cmsis/cm4/device_support/startup/gcc/* ${DST}/cmsis/cm4/device_support/startup/gcc -r
cp ${F421LIB}/cmsis/cm4/core_support/* ${DST}/cmsis/cm4/core_support
cp ${F421LIB}/drivers/* ${DST}/drivers -r

