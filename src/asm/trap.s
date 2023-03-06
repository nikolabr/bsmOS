.option norvc

.section .text
.global asm_trap_vector
.align 4

# TODO : add actual trap vector
asm_trap_vector:
    mret
