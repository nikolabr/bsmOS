INC_DIR := ./inc
BUILD_DIR := ./build
SRC_DIRS := ./src

CC = riscv64-elf-gcc
AS = riscv64-elf-as
CFLAGS = -Wall -Wextra -pedantic -Wextra -O0 -g -std=c11
CFLAGS += -static -ffreestanding -nostdlib -fno-exceptions
CFLAGS += -march=rv64gc -mabi=lp64 -mcmodel=medany
CFLAGS += -I$(INC_DIR) 
LDFLAGS += -Tvirt.lds $(CFLAGS)

OUT = $(BUILD_DIR)/kernel.elf

# Find all sources
SRCS := $(shell find $(SRC_DIRS) -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.s.o: %.s
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
