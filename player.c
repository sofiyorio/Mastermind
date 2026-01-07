#include  <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

typedef  struct {
	char* name; // player's name
	bool is_computer; // necessary for Player Vs Computer games
} player_t;

// Sof
// player_create: Const-Char* Bool -> player_t*
player_t*  player_create(const  char *name, bool is_computer) {
	player_t* player = (player_t*)malloc(sizeof(player_t));
	if (player == NULL) {
        return NULL;
    }

    char* string = (char*) malloc(1+(strlen(name))*sizeof(char));
	if (string == NULL) {
		free(player);
        return NULL;
    }
    player->name = strcpy(string, name);

	player->is_computer = is_computer;

	return player;
}

// Sof
// player_free: player_t* -> None
void  player_free(player_t  *player) {
	free(player->name);
	free(player);
}

// Sof
// player_get_name: player_t* -> Const-Char*
const char*  player_get_name(player_t  *player) {
	return player->name;
}

// Sof
// player_is_computer: player_t* -> Bool
bool  player_is_computer(player_t  *player) {
	return player->is_computer;
}

// Sof
// players_creation: Int player_t** player_t ** -> None
void  players_creation(int  mode, player_t **player1, player_t **player2) {
	char string[MAX_CHAR];
	
	switch (mode) {
	case 1:
		*player1 = player_create("Computer", true);
		printf("Input your name: ");
		scanf("%s", string);
		*player2 = player_create(string, false);
		break;
	
	case 2:
		printf("Input codemaker's name: ");
		scanf("%s", string);
		*player1 = player_create(string, false);

		printf("Input codebreaker's name: ");
		scanf("%s", string);
		*player2 = player_create(string, false);
		break;
	}
}
