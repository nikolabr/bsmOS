#include "uart.h"
#include "csr.h"

#define UART_DEBUG_PRINT(string) uart_puts(__FILE__ " " string);

void kinit(void) {
    uart_init();

    uint64_t status = sstatus_csrr();
    
    UART_DEBUG_PRINT("UART terminal initialized"); 
    
    while (1) {

    };
}
