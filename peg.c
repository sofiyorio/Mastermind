#include  <stdbool.h>
#include <stdlib.h>
#include "peg.h"

typedef enum {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	PINK,
	BLACK
} color_t;

struct peg_t {
	color_t color; // color of the peg
};

// Sof
// peg_create: Int -> peg_t*
peg_t *peg_create(int color) {
    peg_t* peg = (peg_t*) malloc(sizeof(peg_t));
	if (peg == NULL) {
        return NULL;
    }
    peg->color = (color_t)color;

    return peg;
}

// Sof
// peg_free: peg_t* -> None
void peg_free(peg_t* peg) {
    free(peg);
}

// Sof
// peg_equals: peg_t* peg_t* -> Bool
bool peg_equals(const peg_t* a, const peg_t* b) {
    bool equal = (a->color == b->color);
    return equal;
}