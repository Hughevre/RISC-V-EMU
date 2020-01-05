#!/bin/bash
BIN_PATH=${1}

MPATH="/mnt/d/Risc-v/bin"

GAS="${MPATH}/riscv64-unknown-elf-as.exe"
GLD="${MPATH}/riscv64-unknown-elf-ld.exe"
GOBJDUMP="${MPATH}/riscv64-unknown-elf-objdump.exe"
GOBJCOPY="${MPATH}/riscv64-unknown-elf-objcopy.exe"
GREADELF="${MPATH}/riscv64-unknown-elf-readelf.exe"

LD_OPTIONS="-nostartfiles"

${GAS} main.s -o main.o
${GLD} ${LD_OPTIONS} -Tlinker.ld main.o -o test
${GOBJDUMP} -DxS test > test.lst
${GREADELF} -a test >test_elf.lst
${GOBJCOPY} -j ".text" -O binary test ${BIN_PATH}/file_code.bin
${GOBJCOPY} -j ".data" -O binary test ${BIN_PATH}/file_data_in.bin
# TODO: Stan rejestrów (file_reg_in.bin)
