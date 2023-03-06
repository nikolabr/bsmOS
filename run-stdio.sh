#!/usr/bin/bash

qemu-system-riscv64 -machine virt \
 -cpu rv64 -smp 4 -m 128M -nographic -serial 'mon:stdio' -bios none \
 -device virtio-rng-device -device virtio-net-device -device virtio-tablet-device -device virtio-keyboard-device \
 -kernel build/kernel.elf
