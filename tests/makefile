SHELL:=/bin/bash

# ==========================
# 	Generator rejestru
# ==========================

BIN_DIR = ../bin
REG_GEN = reg_gen

# ==========================
# 	Kompilacja *.s
# ==========================

ifeq ($(OS),WINDOWS_NT)
	PLATFORM_BIN = .exe
else
	PLATFORM_BIN = 
endif

MPATH 	 =	/home/hubert/RISC-V/bin
GAS		 =	${MPATH}/riscv64-unknown-elf-as$(PLATFORM_BIN)
GLD		 =	${MPATH}/riscv64-unknown-elf-ld
GOBJDUMP =	${MPATH}/riscv64-unknown-elf-objdump
GOBJCOPY =	${MPATH}/riscv64-unknown-elf-objcopy
GREADELF =	${MPATH}/riscv64-unknown-elf-readelf

LD_OPTIONS = -nostartfiles
TARGET = test

SRCS := $(wildcard *.s *.c)
OBJS := $(SRCS:.c=.out)
OBJS := $(OBJS:.s=.o)

.PHONY: all
all: $(OBJS) inputs

%.out: %.c
	@echo "> Making: $(REG_GEN).out"
	gcc $(REG_GEN).c -o $(REG_GEN).out

# https://www.sifive.com/blog/all-aboard-part-1-compiler-args
%.o: %.s linker.ld
	@echo "> Making: $@ "
	${GAS} $< -o $@ -march=rv32i -mabi=ilp32
	${GLD} ${LD_OPTIONS} -T linker.ld $@ -o $(TARGET) -march=rv32i -melf32lriscv
	${GOBJDUMP} -DxS $(TARGET) > $(TARGET).lst
	${GREADELF} -a $(TARGET) > $(TARGET)_elf.lst

.PHONY: inputs
inputs:
	@echo "> Generatig code to: $(BIN_DIR)/file_code.bin"
	@${GOBJCOPY} -j .text -O binary $(TARGET) ${BIN_DIR}/file_code.bin
	@echo "> Generatig data to: $(BIN_DIR)/file_data_in.bin"
	@${GOBJCOPY} -j .data -O binary $(TARGET) ${BIN_DIR}/file_data_in.bin
	@echo "> Generatig register to: $(BIN_DIR)/file_reg_in.bin"
	@./$(REG_GEN).out $(BIN_DIR)/file_reg_in.bin

.PHONY: clean
clean:
	@rm -rf	$(TARGET)*	\
			*.o		\
			*.out	\
			*.bin	\
			$(BIN_DIR)/*.bin


	






