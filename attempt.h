#ifndef ATTEMPT_H
#define ATTEMPT_H

#include "code.h"

// opaque player structure
typedef struct attempt_t attempt_t;

// function prototypes
attempt_t* attempt_create(code_t* guess);
void attempt_free(attempt_t* attempt);

void attempt_evaluate(attempt_t* attempt, const code_t* secret);
#endif // ATTEMPT_H