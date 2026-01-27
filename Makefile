# Prefer clang, then gcc, then cc
ifeq ($(shell which clang >/dev/null 2>&1 && echo pos),pos)
    CC = clang
else ifeq ($(shell which gcc >/dev/null 2>&1 && echo pos),pos)
    CC = gcc
else
    CC = cc
endif

BUILD_DIR = build
# Default to a dummy value. CLI will set this.
EXERCISE ?= exercises/00_intro/00_start.c
TARGET = $(BUILD_DIR)/current_exercise
INC_DIR = include
SOURCES = $(shell find exercises solutions -name '*.c')

# Compiler info
COMPILER_INFO := $(shell $(CC) --version 2>/dev/null | tr '[:upper:]' '[:lower:]')

# Base Flags
# -I c-lings/include: Allow exercises to find "clings.h"
# -g: Debug info (essential for helpful sanitizer output)
# -fsanitize=address,undefined: The "Borrow Checker" simulation
CFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -Wformat=2 -Wundef \
         -g -fsanitize=address,undefined \
         -I include

# Linker Flags
# Sanitizers must be linked too
LDFLAGS = -fsanitize=address,undefined

# Compiler-specific flags
ifneq (,$(findstring clang,$(COMPILER_INFO)))
    CFLAGS += -Wconversion -Wimplicit-fallthrough -Wno-unused-command-line-argument -fcolor-diagnostics
else ifneq (,$(findstring gcc,$(COMPILER_INFO)))
    CFLAGS += -Wconversion -Wlogical-op -Wduplicated-cond -Wduplicated-branches -fdiagnostics-color=always
endif

.PHONY: run clean prepare fmt

all: run

prepare:
	@mkdir -p $(BUILD_DIR)

$(TARGET): prepare $(EXERCISE)
	@$(CC) $(CFLAGS) "$(EXERCISE)" -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	@$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

fmt:
	clang-format -i --style=file --fallback-style=LLVM $(SOURCES) $(wildcard $(INC_DIR)/*.h)
