#ifndef _CSR_H
#define _CSR_H

#include <stdint.h>

// C macros for CSR operations

uint64_t sstatus_csrr();
uint64_t sie_csrr();
uint64_t stvec_csrr();


#endif
