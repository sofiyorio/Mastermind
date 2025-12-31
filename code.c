#include "peg.h"

#define CODE_LENGTH 4 // the fixed length of the code

typedef struct {
	peg_t *pegs[CODE_LENGTH]; // array of pointer to pegs
} code_t;