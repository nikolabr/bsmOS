#ifndef _UTIL_H
#define _UTIL_H

#define DEBUG_ASSERT(val)   \
  if (!val) {		    \
    __asm__("ebreak");	    \
  }			    \
    
#endif
