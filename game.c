#include "player.h"
#include "code.h"
#include "attempt.h"

typedef enum {
    GAME_PVC,// Player Vs Computer
    GAME_PVP // Player vs Player
} mode_t;

#define MAX_ATTEMPTS 10

typedef struct {
    player_t *player1; // Pointer to Player 1 (Code Breaker)
    player_t *player2; // Pointer to Player 2 (Code Maker)
    mode_t gamemode; // Gamemode: PVC or PVP
    
    code_t *secret; // Pointer to secret code
    attempt_t *attempts[MAX_ATTEMPTS]; // Array of attempts
    int attempt_count; // keeps track of how many attempts
    
    bool is_won; // keeps track if game is won
} game_t;