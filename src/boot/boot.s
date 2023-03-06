# Disable compressed instructions
.option norvc

.section .text.init

.global _start
_start:
    
.option push
.option norelax
# Set global pointer register
	la		gp, _global_pointer
.option pop
	# Disable paging for now
	csrw satp, zero

	# Park unused harts
	# TODO: Later on, enable all harts
park_harts:
	csrr t0, mhartid
	bnez t0, idle_hart

# Set all bytes in the BSS section to zero.
	la 		a0, _bss_start
	la		a1, _bss_end
	bgeu	a0, a1, bss_clear_complete

bss_clear_loop:
	sd		zero, (a0)
	addi	a0, a0, 8
	bltu	a0, a1, bss_clear_loop
	
bss_clear_complete:
	
	# PMP must be set up before entering S mode
	# Set entirety of memory to be RWX
setup_pmp:
	li t0, 0xFFFFFFFFFFFFFF
	csrw pmpaddr0, t0
	
	# Enable R, W, X, set A to NAPOT
	csrs pmpcfg0, (0b11 << 3) | (1 << 2) | (1 << 1) | (1 << 0)

context_switch:
	la      sp, _stack_end

	# MEPC is the return address after a M mode exception
	la t0, s_kernel_init
	csrw mepc, t0

	# Set MPP to S mode
	li t1, (0b01 << 11)
	csrs mstatus, t1
	
	# Set boot trap vector in case something goes wrong
	la t2, boot_trap_vector
	csrw mtvec, t2

	mret

	.align 4
s_kernel_init:
	la a0, kinit
	jalr ra, a0, 0
	
idle_hart:
	wfi
	j idle_hart

	.align 4
boot_trap_vector:
	csrr t0, mepc
	csrr t1, mcause
	la t2, idle_hart
	csrw mepc, t2
	mret
