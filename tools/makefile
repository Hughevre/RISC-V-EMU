SHELL:=/bin/bash

# ==========================
# 	Kompilacja *.s
# ==========================

# Należy stworzyć plik "MAKEVARS" z zawartością:
# MPATH = 'Twoja ścieżka'

include MAKEVARS

GAS		 :=	${MPATH}/riscv64-unknown-elf-as
GLD		 :=	${MPATH}/riscv64-unknown-elf-ld
GOBJDUMP :=	${MPATH}/riscv64-unknown-elf-objdump
GOBJCOPY :=	${MPATH}/riscv64-unknown-elf-objcopy
GREADELF :=	${MPATH}/riscv64-unknown-elf-readelf

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
BINS_DIR := $(dir $(shell find $(SRCS_DIR) -name '*.s'))

BINS = $(addsuffix $(FILE_CODE), $(BINS_DIR)) \
		$(addsuffix $(FILE_DATA), $(BINS_DIR)) \
		$(addsuffix $(FILE_REG), $(BINS_DIR))

SRCS := $(shell find $(SRCS_DIR) -name '*.s') $(wildcard *.c)
OBJS := $(SRCS:.c=)
OBJS := $(OBJS:.s=.o)

PYS := $(basename $(shell find $(SRCS_DIR) -name '*.py'))

.PHONY: start
start: $(PYS)
	@make -s all

%: %.py
	@echo "> Generating: $(@)"
	@cd $(dir $@); python3 $(<F)

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
BINS_DIR := $(sort $(dir $(shell find $(SRCS_DIR) -name '*.bin')))
clean:
	@echo "> Cleaning: ${BINS_DIR} reg_gen"
	@rm -rf	$(shell find $(BINS_DIR) -name '*.bin')		\
			$(shell find $(SRCS_DIR) -name '*.o'		\
								-o 	 -name '*debug.txt'	\
								-o	 -name 'test*')		\
			reg_gen
