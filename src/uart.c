#include "uart.h"

void uart_init() 
{
  // Set first two bits in LCR to define mode to 8 bits
  NS16650->lcr &= 0xFC;
  NS16650->lcr |= (1 << NS16650_LCR_WLS);

  // Enable FIFOs
  NS16650->fcr |= (1 << NS16650_FCR_ENABLE);

  // Enable interrupts
  NS16650->ier |= (1 << NS16650_IER_ERBFI);
}

void uart_putchar(int ch)
{
  NS16650->thr = ch;
}

void uart_puts(const char* str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
      uart_putchar(str[i]);
  }
  uart_putchar('\n');
}

int uart_getchar()
{
  if (NS16650->lsr & NS16650_LCR_WLS) {
    return NS16650->rbr;
  }

  return -1;
}
