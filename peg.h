#ifndef  PEG_H
#define  PEG_H

#include  <stdbool.h>

// Opaque peg structure
typedef  struct  peg_t  peg_t;

// Function prototypes

/// @brief Creates a new peg structure.
/// @param color The color of the peg to create.
/// @return A pointer to the newly created peg.
peg_t* peg_create(int color);

/// @brief Frees the memory allocated for a given peg.
/// @param peg The peg to free.
void peg_free(peg_t* peg);

/// @brief Evaluates if two given pegs have the same color.
/// @param a The first peg.
/// @param b The second peg.
/// @return True if peg a and b have the same color, false otherwise.
bool peg_equals(const peg_t* a, const peg_t* b);

#endif // PEG_H