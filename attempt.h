#ifndef ATTEMPT_H
#define ATTEMPT_H

#include "code.h"

// Opaque player structure
typedef struct attempt_t attempt_t;

// Function prototypes

/// @brief Creates a new attempt structure.
/// @param guess The guess of the attempt to create.
/// @return A pointer to the newly created attempt.
attempt_t* attempt_create(code_t* guess);

/// @brief Frees the memory allocated for a given attempt.
/// @param attempt The attempt to free.
void attempt_free(attempt_t* attempt);

/// @brief Evaluates if two given attempts have any partial or total matches.
/// @param attempt The codebreaker attempt.
/// @param secret The codemaker secret code.
void attempt_evaluate(attempt_t* attempt, const code_t* secret);

/// @brief A getter function for an attempt's total match member.
/// @param player The player which total matches to get.
/// @return The player's total matches as an int.
int attempt_get_total_match(const attempt_t* attempt);

/// @brief A getter function for an attempt's partial match member.
/// @param player The player which partial matches to get.
/// @return The player's partial matches as an int.
int attempt_get_partial_match(const attempt_t* attempt);
#endif // ATTEMPT_H