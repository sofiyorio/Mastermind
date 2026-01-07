#include "code.h"
#include <stdlib.h>

typedef struct {
	code_t *guess; // pointer to the guess made by the player
	int partial_match; // correct color but wrong position
	int total_match; // correct color and correct position
} attempt_t;


// Miru :)
attempt_t* attempt_create(code_t* guess) {
	if(!guess) return NULL; // safety check

	attempt_t* attempt = malloc(sizeof(attempt_t));
	if(!attempt) return NULL; 

	attempt->guess = guess; // store guess
	attempt->total_match = 0; // initialize counters
	attempt->partial_match = 0;

	return attempt;
}

// Miru :)
void attempt_free(attempt_t* attempt) {
	if (!attempt) return; //safety check

	// freeing guess
	if (attempt->guess) {
		code_free(attempt->guess);
	}

	free(attempt); // freeing struct
}

// Miru :)
void attempt_evaluate(attempt_t* attempt, const code_t* secret) {
	if (!attempt || !secret) return; // safety check

	code_compare(secret, attempt->guess, &attempt->total_match, &attempt->partial_match);

}

// Miru :) ++ extra function, needed getter function
// needed to get total match, and keep struct opaque
int attempt_get_total_match(const attempt_t* attempt) {
	if (!attempt) return 0; //safety
	return attempt->total_match;
}