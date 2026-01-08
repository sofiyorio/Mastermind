#include <stdio.h>
#include "player.h"
#include "code.h"
#include "attempt.h"
#include "game.h"
#include "defines.h"


int  main() {
	printf("\n\n%sWelcome to Mastermind!%s\n\n", BOLD, RESET);
	int play = 1;
	int gamemode;
	
	// mode selection
	printf("Choose game mode:\n");  
	printf("    1. Player vs Computer\n");
	printf("    2. Player vs Player\n");
	scanf("%d", &gamemode);

    // players creation
	player_t *player1;
	player_t *player2;
	players_creation(gamemode, &player1, &player2);
	
// run until player decides to stop playing
	while (play) {
	game_t* game = game_create(gamemode, player1, player2);
	
	// main game loop: run until game is over
        while (!game_is_over(game)) {
            code_t* guess = code_create_manual();
            game_add_attempt(game, guess);
            printf("You have %d attempts left.\n\n\n", game_attempts_left(game));
        }
        
        if (game_is_won(game)) {
            printf("Code broken!\n");
            printf("Congratulations %s, you did it! \n\n", player_get_name(player2));
        } else {
            if (gamemode == 2) {
                printf("%s's code was too hard to break!\n", player_get_name(player1));
            }
            printf("Code not broken, better luck next time!\n");
        }
        game_free(game);
        
        printf("Play another round? (1 = yes, 0 = no): ");
        scanf("%d", &play);
        if (play==1 && gamemode==2) {   // Switch roles at the end of the round
            player_t* temp = player1;
            player1 = player2;
            player2 = temp;
        }
    }
    
    return 0;
}