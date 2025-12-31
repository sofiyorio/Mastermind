#include "code.h"

typedef struct {
	code_t *guess; // pointer to the guess made by the player
	int partial_match; // correct color but wrong position
	int total_match; // correct color and correct position
} attempt_t;
