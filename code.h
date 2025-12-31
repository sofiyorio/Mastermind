#ifndef CODE_H
#define CODE_H
#include "peg.h"

// opaque player structure
typedef struct code_t code_t;

// function prototypes
code_t* code_create_random(void);
code_t* code_create_manual(void);
void  code_free(code_t* code);

void code_compare(const code_t* secret,const code_t* guess, 
					int* total_match, int* partial_match);

peg_t*  get_peg(const code_t* code, int index);
#endif // CODE_H