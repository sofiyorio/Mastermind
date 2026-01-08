#ifndef  PLAYER_H
#define  PLAYER_H 

#include  <stdbool.h>
#include <stdlib.h>

// Opaque player structure
typedef struct  player_t  player_t;

// Function prototypes

/// @brief Creates a new player structure.
/// @param name The name of the player.
/// @param is_computer Whether the player is computer generated.
/// @return A pointer to the newly created player.
player_t*  player_create(const  char  *name, bool is_computer);

/// @brief Frees the memory allocated for a given player.
/// @param player The player to free.
void  player_free(player_t  *player);

/// @brief A getter function for a player's name member.
/// @param player The player which name to get.
/// @return The player's name as a const string.
const char*  player_get_name(player_t  *player);

/// @brief A getter function for a player's is_computer member.
/// @param player The player which is_computer member to get.
/// @return The player's is_computer as a boolean.
bool  player_is_computer(player_t  *player);

/// @brief Creates two players structures.
/// @param mode The gamemode - Player vs Computer | Player vs Player.
/// @param player1 The codemaker player.
/// @param player2 The codebreaker player.
void  players_creation(int  mode, player_t **player1, player_t **player2);

#endif // PLAYER_H