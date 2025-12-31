#ifndef  PEG_H
#define  PEG_H

#include  <stdbool.h>

// opaque peg structure
typedef  struct  peg_t  peg_t;

// function prototypes
peg_t* peg_create(int color);
void peg_free(peg_t* peg);

bool peg_equals(const peg_t* a, const peg_t* b);
#endif // PEG_H