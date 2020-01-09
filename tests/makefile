SHELL:=/bin/bash

# ==========================
# 	Generator rejestru
# ==========================

BIN_DIR = ../bin
REG_GEN = reg_gen

# ==========================
# 	Kompilacja *.s
# ==========================

MPATH 	 =	/mnt/d/Risc-v/bin
GAS		 =	${MPATH}/riscv64-unknown-elf-as.exe
GLD		 =	${MPATH}/riscv64-unknown-elf-ld.exe
GOBJDUMP =	${MPATH}/riscv64-unknown-elf-objdump.exe
GOBJCOPY =	${MPATH}/riscv64-unknown-elf-objcopy.exe
GREADELF =	${MPATH}/riscv64-unknown-elf-readelf.exe

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

%.o: %.s linker.ld
	@echo "> Making: $@ "
	${GAS} $< -o $@
	${GLD} ${LD_OPTIONS} -T linker.ld $@ -o $(TARGET)
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


	






