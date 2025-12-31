#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "code.h"

// opaque player structure
typedef struct game_t game_t;

// function prototypes
game_t* game_create(int mode, player_t *player1, player_t *player2);
void  game_free(game_t* game);

void game_add_attempt(game_t* game, code_t* guess);

bool game_is_over(const game_t* game);
bool game_is_won(const game_t* game);

int game_attempts_left(const game_t* game);
#endif // GAME.H