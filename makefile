SHELL:=/bin/bash

# ==========================
# 	Kompilacja ./src
# ==========================
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./build
BIN_DIR = ./bin

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Wshadow -std=c99 -I$(INC_DIR)
TARGET 	= V-RISCV

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

# ==========================
# 	Kompilacja ./tests
# ==========================
TESTS_DIR  = ./tests
MAKE	   = make
TESTS_MAKE = $(MAKE) -sC $(TESTS_DIR)

MKDIR = $(shell [[ -d $(1) ]] || mkdir -p $(1))

all: $(BIN_DIR)/$(TARGET) inputs

$(BIN_DIR)/$(TARGET): $(OBJS)
	@echo "> Making: $(TARGET)"
	$(call MKDIR,$(@D))
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(call MKDIR,$(@D))
	$(CC) -c $(CFLAGS) -MMD $< -o $@

# Generator plików wejściowych
.PHONY: inputs
inputs:
	$(TESTS_MAKE)

.PHONY: clean
clean:
	@echo "> Cleaning: ${BIN_DIR} ${OBJ_DIR} ${TESTS_DIR}"
	@rm -rf $(OBJ_DIR)/*	\
			$(BIN_DIR)/*
	@$(TESTS_MAKE) clean

.PHONY: clean-all
clean-all: clean
	@echo "> Removing dirs: ${BIN_DIR} ${OBJ_DIR}"
	@rm -rf $(OBJ_DIR)	\
			$(BIN_DIR)
	cd $(TESTS_DIR) && $(MAKE) clean
