#include "player.h"
#include "code.h"
#include "attempt.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ATTEMPTS 10
#define CODE_LENGTH 4

typedef enum {
    GAME_PVC,// Player Vs Computer
    GAME_PVP // Player vs Player
} gamemode_t;

typedef struct {
    player_t *player1; // Pointer to Player 1 (Code Breaker)
    player_t *player2; // Pointer to Player 2 (Code Maker)
    gamemode_t gamemode; // Gamemode: PVC or PVP
    
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

    // set game mode
    if ( mode == 0 ) {
        game->gamemode = GAME_PVC;
    }
    else {
        game->gamemode = GAME_PVP;
    }

    game->attempt_count = 0;
    game->is_won = false;
    
    for ( int i = 0; i < MAX_ATTEMPTS; i ++ )
        game->attempts[i] = NULL;

    if ( game->gamemode == GAME_PVC ) {
        game->secret = code_create_random();
    }

    else {
        game->secret = code_create_manual();
    }

    return game;
}

// Miru :)
void game_free(game_t* game) {

    if(!game) return; //safetyy - to prevent crash

    // free all attempts
    for ( int i = 0; i < game->attempt_count; i ++ ) {
        if ( game->attempts[i]) {
            attempt_free(game->attempts[i]);
        }
    }

    // freeing secret code
    if(game->secret) {
        code_free(game->secret);
    }

    // free game struct
    free(game);

}

// Miru :)
void game_add_attempt(game_t* game, code_t* guess) {
    if (!game || !guess) return; // safety c heck

    if (game->attempt_count >= MAX_ATTEMPTS) return; // no attempt left

    // create attempt
    attempt_t* attempt = attempt_create(guess);
    if (!attempt) return;

    attempt_evaluate(attempt, game->secret);

    // store attempt
    game->attempts[game->attempt_count] = attempt;
    game->attempt_count++;

    // used extra getter function
    if (attempt_get_total_match(attempt) == CODE_LENGTH) {
        game->is_won = true;
    }
    
}

// Miru :)
bool game_is_over(const game_t* game) {
    if (!game) return true; // safety check :P

    // player guessed code or game is over
    return game->is_won || game->attempt_count >= MAX_ATTEMPTS;

}

// Miru :)
bool game_is_won(const game_t* game) {
    if (!game) return false; // safetyyy - if game doesn't exist it cannot be won

    return game->is_won;
}

// Miru :)
int game_attempts_left(const game_t* game) {
    if (!game) return 0; // safety
    
    // total allowed -(minus) how many have been used
    return MAX_ATTEMPTS - game->attempt_count;
}