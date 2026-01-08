#ifndef CODE_H
#define CODE_H
#include "peg.h"

// Opaque player structure
typedef struct code_t code_t;

// Function prototypes

/// @brief Creates a new code structure.
/// @return A pointer to a new code with randomly created pegs.
code_t* code_create_random(void);

/// @brief Creates a new code structure.
/// @return A pointer to a new code with user selected pegs.
code_t* code_create_manual(void);

/// @brief Frees the memory allocated for a given code.
/// @param code The code to free.
void  code_free(code_t* code);

/// @brief Compares a two codes, and updates the amount of matches they share.
/// @param secret The codemaker's ssecret code.
/// @param guess The codebreaker's attempt.
/// @param total_match A pointer to the guess's total peg matches.
/// @param partial_match A pointer to the guess's partial peg matches.
void code_compare(const code_t* secret,const code_t* guess, 
					int* total_match, int* partial_match);


/// @brief A getter function for a peg structure.
/// @param code The code where to find the peg.
/// @param index The index in the code where the peg is located.
/// @return A pointer to the peg structure.
peg_t*  get_peg(const code_t* code, int index);

#endif // CODE_H