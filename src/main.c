#include "uart.h"
#include "csr.h"

extern void asm_trap_vector(void);

void kinit(void)
{
    uart_init();

    stvec_csrw((uint64_t)asm_trap_vector);

    uint64_t status = sstatus_csrr();
    
    UART_DEBUG_PRINT("UART terminal initialized"); 

}
