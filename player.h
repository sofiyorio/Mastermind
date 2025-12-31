#ifndef  PLAYER_H
#define  PLAYER_H 

#include  <stdbool.h>

// opaque player structure
typedef struct  player_t  player_t;

// function prototypes
player_t*  player_create(const  char  *name, bool is_computer);
void  player_free(player_t  *player);
const char*  player_get_name(player_t  *player);
bool  player_is_computer(player_t  *player);

void  players_creation(int  mode, player_t *player1, player_t *player2);

#endif // PLAYER_H