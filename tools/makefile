SHELL:=/bin/bash

# ==========================
# 	Kompilacja *.s
# ==========================

MPATH 	 :=	/mnt/d/Risc-v/bin
GAS		 :=	${MPATH}/riscv64-unknown-elf-as.exe
GLD		 :=	${MPATH}/riscv64-unknown-elf-ld.exe
GOBJDUMP :=	${MPATH}/riscv64-unknown-elf-objdump.exe
GOBJCOPY :=	${MPATH}/riscv64-unknown-elf-objcopy.exe
GREADELF :=	${MPATH}/riscv64-unknown-elf-readelf.exe

ASFLAGS	:= -march=rv32i -mabi=ilp32
LDFLAGS := -nostartfiles -march=rv32i -melf32lriscv

# ==========================
# 	Generatory
# ==========================

REG_GEN := reg_gen

FILE_CODE := file_code.bin
FILE_DATA := file_data_in.bin
FILE_REG  := file_reg_in.bin

TARGET_DIR = %
TARGET := test

SRCS_DIR := ../tests/t_*
BINS_DIR := $(dir $(wildcard $(SRCS_DIR)/*.s))

BINS = $(addsuffix $(FILE_CODE), $(BINS_DIR)) \
		$(addsuffix $(FILE_DATA), $(BINS_DIR)) \
		$(addsuffix $(FILE_REG), $(BINS_DIR))

SRCS := $(wildcard $(SRCS_DIR)/*.s *.c)
OBJS := $(SRCS:.c=)
OBJS := $(OBJS:.s=.o)



.PHONY: all
all: $(OBJS) 
	@make -s inputs

%: %.c
	@echo "> Making: $(@)"
	@gcc $(@).c -o $(@)

# https://www.sifive.com/blog/all-aboard-part-1-compiler-args
%.o: %.s linker.ld
	@echo "> Making: $@"
	@${GAS} ${ASFLAGS} $< -o $@
	@${GLD} ${LDFLAGS} -T linker.ld $@ -o $(@D)/$(TARGET)
	@${GOBJDUMP} -DxS $(@D)/$(TARGET)  >  $(@D)/$(TARGET).lst
	@${GREADELF} -a	  $(@D)/$(TARGET)  >  $(@D)/$(TARGET)_elf.lst

.PHONY: inputs
inputs: $(BINS)

%$(FILE_CODE): $(TARGET_DIR)/$(TARGET)
	@echo "> Generatig code to: $(@)"
	@${GOBJCOPY} -j .text -O binary $< $(@)

%$(FILE_DATA): $(TARGET_DIR)/$(TARGET)
	@echo "> Generatig data to: $(@)"
	@${GOBJCOPY} -j .data -O binary $< $(@)

%$(FILE_REG): $(REG_GEN)
	@echo "> Generatig register to: $(@)"
	@./$< $(@)



.PHONY: clean
clean:
	@rm -rf	$(addsuffix /*.bin, $(BINS_DIR))	\
			$(SRCS_DIR)/*.o		\
			$(SRCS_DIR)/test*	\









