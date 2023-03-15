#ifndef _CSR_H
#define _CSR_H

#include <stdint.h>

// C macros for CSR operations

uint64_t sstatus_csrr();
uint64_t sie_csrr();
uint64_t stvec_csrr();

void stvec_csrw(uint64_t val);

uint64_t sepc_csrr();
void sepc_csrw(uint64_t val);

#endif
