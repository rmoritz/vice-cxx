#ifndef UTIL_HH
#define UTIL_HH

#include "vice.hh"

// ----------------------------------------------------------------------
// MACROS
// ----------------------------------------------------------------------

#ifdef DEBUG
#define ASSERT(n)                                                       \
  if (!(n)) {                                                           \
    printf("\nFAIL: %s\n      on %s\n      at %s\n      in file %s\n      at line %d\n", \
           #n, __DATE__, __TIME__, __FILE__, __LINE__);                 \
    exit(1);                                                            \
  }
#else
#define ASSERT(n)
#endif // DEBUG

namespace vice {
  // ----------------------------------------------------------------------
  // INLINE FUNCTIONS
  // ----------------------------------------------------------------------

  inline U64 rand64() {
    return (U64) rand()
      | (U64) rand() << 15
      | (U64) rand() << 30
      | (U64) rand() << 45
      | ((U64) rand() & 0xf) << 60;
  }

  inline int fr2sq(int f, int r) {
    return (21 + f) + (r * 10);
  }

  inline int sq64(int sq120) {
    return sq120ToSq64[sq120];
  }

  inline int sq120(int sq64) {
    return sq64ToSq120[sq64];
  }

  // ----------------------------------------------------------------------
  // FUNCTIONS
  // ----------------------------------------------------------------------

  char* prSq(int);
}

#endif // !UTIL_HH
