#include "csr.h"

#define CSRR_FUNC(csr)				\
  uint64_t csr##_csrr()			        \
  {						\
    register uint64_t result;			\
  __asm__("csrr %0, " #csr "\n\t"		\
	  : "=r" (result)			\
	  );					\
						\
  return result;				\
						\
  }						\

#define CSRW_FUNC(csr)				\
  void csr##_csrw(uint64_t val)			\
  {						\
  __asm__("csrw " #csr ", %0\n\t"		\
  : "=r" (val)					\
	  );					\
  }						\
  
#define CSRS_FUNC(csr)				\
  void csr##_csrw(uint64_t val)			\
  {						\
  __asm__("csrs " #csr ", %0\n\t"		\
  : "=r" (val)					\
	  );					\
  }						\
  
#define CSRC_FUNC(csr)				\
  void csr##_csrw(uint64_t val)			\
  {						\
  __asm__("csrc " #csr ", %0\n\t"		\
  : "=r" (val)					\
	  );					\
  }						\

CSRR_FUNC(sstatus)
CSRR_FUNC(sie)
CSRR_FUNC(stvec)

CSRW_FUNC(stvec)

CSRR_FUNC(sepc)
CSRW_FUNC(sepc)
