#include "uart.h"
#include "csr.h"

void trap_vector() {
  UART_DEBUG_PRINT("Entered S mode trap vector");
  // Increment sepc
  sepc_csrw(sepc_csrr() + 4);
}
