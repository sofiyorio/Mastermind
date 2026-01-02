#include <stdio.h>
#include "player.h"
#include "code.h"
#include "attempt.h"
#include "game.h"

int  main() {
	printf("Welcome to Mastermind");
	int play = 1;
	int gamemode;
	
	// mode selection
	printf("Choose game mode:\n");  
	printf("1. Player vs Computer\n");
	printf("2. Player vs Player\n");
	scanf("%d", &gamemode);

	player_t *player1;
	player_t *player2;
	players_creation(gamemode, player1, player2);
	
// run until player decides to stop playing
	while (play) {
	game_t* game = game_create(gamemode, player1, player2);
	
	// main game loop: run until game is over
        while (!game_is_over(game)) {
            code_t* guess = code_create_manual();
            game_add_attempt(game, guess);
        }
        
        if (game_is_won(game)) {
            printf("Code broken!\n");
        } else {
            printf("Code not broken.\n");
        }
        game_free(game);
        
        printf("Play another round? (1 = yes, 0 = no): ");
        scanf("%d", &play);
    }
    return 0;
}