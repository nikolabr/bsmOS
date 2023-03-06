#!/usr/bin/bash

qemu-system-riscv64 -machine virt \
 -cpu rv64 -s -S -m 128M -bios none \
 -device virtio-rng-device -device virtio-net-device -device virtio-tablet-device -device virtio-keyboard-device \
 -kernel build/kernel.elf
