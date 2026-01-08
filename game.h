#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "code.h"

// Opaque player structure
typedef struct game_t game_t;

// Function prototypes

/// @brief Creates a new game structure.
/// @param mode The gamemode of the game to create - Plaver vs Computer | Player vs Player.
/// @param player1 The codemaker player.
/// @param player2 The codebreaker player.
/// @return A pointer to the newly created game.
game_t* game_create(int mode, player_t *player1, player_t *player2);

/// @brief Frees the memory allocated for a given game.
/// @param game The game to free.
void  game_free(game_t* game);

/// @brief Adds and evaluates a new attempt into the given game.
/// @param game The game currently being played.
/// @param guess The new code attempt by the codebreaker.
void game_add_attempt(game_t* game, code_t* guess);

/// @brief Evaluates whether a given game has broken the code or ran out of attempts.
/// @param game The game to evaluate.
/// @return True if the game has finished, false otherwise.
bool game_is_over(const game_t* game);

/// @brief A getter function for a game's is_won member.
/// @param game The game which is_won member to get.
/// @return The game's is_won member as an bool.
bool game_is_won(const game_t* game);

/// @brief Evaluates how many attempts does the codebreaker have left.
/// @param game The game currently being played.
/// @return The amount of attempts remaining.
int game_attempts_left(const game_t* game);

#endif // GAME.H