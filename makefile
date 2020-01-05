SHELL:=/bin/bash

default: all

# ==========================
# 	Kompilacja ./src
# ==========================
CC = gcc
CFLAGS = -Wall

TARGET = RISCV.out

BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ==========================
# 	Kompilacja ./tests
# ==========================
TESTS_DIR = ./tests
TESTS_MAKE = make -sC $(TESTS_DIR)

MKDIR = $(shell [[ -d $(1) ]] || mkdir -p $(1))


all: $(OBJS)
	$(call MKDIR,$(@D))
	$(CC) $(OBJS) -o $(BIN_DIR)/$(TARGET)
	$(TESTS_MAKE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning: ${BIN_DIR} ${OBJ_DIR} ${TESTS_DIR}"
	@rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*.out
	@$(TESTS_MAKE) clean

