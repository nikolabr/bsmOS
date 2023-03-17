#ifndef _UTIL_H
#define _UTIL_H

void debug_assert(int val) {
  if (!val) {
    __asm__("sbrk");
  }
}
    
#endif
