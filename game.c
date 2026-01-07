#include "player.h"
#include "code.h"
#include "attempt.h"
#include <stdlib.h>

#define MAX_ATTEMPTS 10

typedef enum {
    GAME_PVC,// Player Vs Computer
    GAME_PVP // Player vs Player
} mode_t;

typedef struct {
    player_t *player1; // Pointer to Player 1 (Code Breaker)
    player_t *player2; // Pointer to Player 2 (Code Maker)
    mode_t gamemode; // Gamemode: PVC or PVP
    
    code_t *secret; // Pointer to secret code
    attempt_t *attempts[MAX_ATTEMPTS]; // Array of attempts
    int attempt_count; // keeps track of how many attempts
    
    bool is_won; // keeps track if game is won
} game_t;

// Miru :) 
game_t* game_create(int mode, player_t *player1, player_t *player2) {
    game_t* game = malloc(sizeof(game_t));
    if (!game) return NULL;

    game->player1 = player1;
    game->player2 = player2;

    game->gamemode = (mode == 0)
}