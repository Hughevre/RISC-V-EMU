SHELL:=/bin/bash


# ==========================
# 	Generator rejestru
# ==========================

BIN_DIR = ../bin
REG_GEN = reg_gen

FILE_REG_IN = file_reg_in.bin

# ==========================
# 	Kompilacja *.s
# ==========================

SRCS := $(wildcard *.s *.c)
OBJS := $(SRCS:.c=.out)
OBJS := $(OBJS:.s=.o)

MPATH=/mnt/d/Risc-v/bin
GAS=${MPATH}/riscv64-unknown-elf-as.exe
GLD=${MPATH}/riscv64-unknown-elf-ld.exe
GOBJDUMP=${MPATH}/riscv64-unknown-elf-objdump.exe
GOBJCOPY=${MPATH}/riscv64-unknown-elf-objcopy.exe
GREADELF=${MPATH}/riscv64-unknown-elf-readelf.exe

LD_OPTIONS=-nostartfiles



all: $(OBJS)
	@echo "Generatig register to: $(BIN_DIR)/$(FILE_REG_IN)"
	@./$(REG_GEN).out $(BIN_DIR)/$(FILE_REG_IN)

%.out: %.c
	@echo "Making: $(REG_GEN).out"
	gcc $(REG_GEN).c -o $(REG_GEN).out

%.o: %.s
	@echo "Making: $@ "
	${GAS} $< -o $@
	${GLD} ${LD_OPTIONS} -Tlinker.ld $@ -o test
	${GOBJDUMP} -DxS test > test.lst
	${GREADELF} -a test >test_elf.lst
	${GOBJCOPY} -j .text -O binary test ${BIN_DIR}/file_code.bin
	${GOBJCOPY} -j .data -O binary test ${BIN_DIR}/file_data_in.bin
# TODO: Zmienić "test" na zmienną

clean:
	@rm -rf	test*	\
			*.o		\
			*.bin	\
			$(BIN_DIR)/*.bin

clean-all: clean
	@rm -rf *.out



	






