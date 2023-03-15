#ifndef _BOOT_H
#define _BOOT_H

#define NS16650_BASE_ADDRESS 0x10000000

#define NS16650_IER_ERBFI   0

#define NS16650_IIR_PENDING 0
#define NS16650_IIR_ID      1

#define NS16650_FCR_ENABLE  0

#define NS16650_LCR_WLS     0

#include <stdint.h>

typedef struct {
    union {
        volatile const uint8_t rbr;
        volatile uint8_t thr;
    };
    volatile uint8_t ier;
    union {
        volatile const uint8_t iir;
        volatile uint8_t fcr;
    };
    volatile uint8_t lcr;
    volatile uint8_t mcr;
    volatile uint8_t lsr;
} NS16650_t;

#define NS16650 ((NS16650_t *) NS16650_BASE_ADDRESS)

void uart_init();
void uart_putchar(int ch);
void uart_puts(const char* str);
int uart_getchar();

#define UART_DEBUG_PRINT(string) uart_puts(__FILE__ " " string);

#endif
