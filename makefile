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
TESTS_MAKE = make -sC $(TESTS_DIR)

MKDIR = $(shell [[ -d $(1) ]] || mkdir -p $(1))


$(BIN_DIR)/$(TARGET): $(OBJS)
	$(call MKDIR,$(@D))
	$(CC) $(CFLAGS) $^ -o $@
	$(TESTS_MAKE)


-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -MMD $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning: ${BIN_DIR} ${OBJ_DIR} ${TESTS_DIR}"
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BIN_DIR)
	@$(TESTS_MAKE) clean

