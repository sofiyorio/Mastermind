# Design of Mastermind
**Group members**: Sofía Yorio (588409), Miruna Stancu (587662)


## Game overview
Mastermind is a code-breaking game where the code-maker chooses a hidden sequence of coloured pegs. Each turn, the code-breaker submits a guess: a sequence of the same length using the same colour set. The game provides feedback with two numbers: (1) the count of pegs that are the correct colour in the correct position, and (2) the count of pegs that are the correct colour but in the wrong position.

The game ends when the code is guessed correctly or when the maximum number of attempts is reached. The program will then prompt the player if they want to try another round.

The program supports two modes:
- Player vs Computer, where the computer generates a random secret code.
- Player vs Player, where one player manually enters the secret code while the other player looks away.

## Design components

The following "entities" will be ussed to represent the game state (a high-level description is given first, followed by a more detailed description of each data structure in C code):

-  `Peg`: Represents a single peg with a color. 
-  `Code`: Represents a sequence of pegs. Used for both secret code and guesses. Provides comparison logic (exact matches, color-only matches).
-  `Attempt`: Represents one guess together with the feedback.
-  `Player`: Represents a player and whether the player is human or computer-controlled.
-  `Game`: Manages the overall game state, including the secret code, attempts, game mode, and win/lose detection.

> Additionally, a graphical user interface (GUI) module may be added to handle user input and visual display. This module would be responsible solely for presentation and interaction, and would not affect the core game logic.


### Data Structures and enumerations


#### Peg

In the "Peg" module, two structures are defined.

One is an enumeration representing the colors of each peg:

```c
typedef enum {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	PINK,
	BLACK
} color_t;
```

The other one is the peg represented by the following structure:

```c
typedef struct {
	color_t color; // color of the peg
} peg_t;
```

#### Code

A code is represented by the following structure:

```c
#define CODE_LENGTH 4 // the fixed length of the code

typedef struct {
	peg_t *pegs[CODE_LENGTH]; // array of pointer to pegs
} code_t;
```

A code represents a fixed-length ordered sequence of pegs, used for both the secret code and the guesses. By using an array, the position of each peg corresponds to the index of said peg in the array which will be used to compare codes to find matches. As "peg_t" is opaque, the array is of pointers to pegs instead of just pegs.

  

#### Attempt

An attempt is represented by the following structure:

```c
typedef struct {
	code_t *guess; // pointer to the guess made by the player
	int partial_match; // correct color but wrong position
	int total_match; // correct color and correct position
} attempt_t;

```

The feedback values are stored as integers, matching the standard Mastermind rules and simplifying display logic for a graphical interface.


#### Player

A player is represented by the following structure:

```c
#define MAX_CHAR 50

typedef  struct {
	char name[MAX_CHAR]; // player's name
	bool is_computer; // necessary for Player Vs Computer games
} player_t;

```

#### Game

The "Game" structure hold an structure and an enumeration.

```c
typedef enum {
    GAME_PVC,// Player Vs Computer
    GAME_PVP // Player vs Player
} mode_t;
```

In Player vs Player mode, the program will prompt Player 1 to look away while Player 2 inputs the code. If GUI is implemented, this will be used to hide the code from the screen. If not, a library such as termios will be used to prevent the echo of characters to display the secret code in the terminal.

```c
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
```
  

## Interaction between components

At the highest level, the `main` function would look like this:

```c
int  main() {
	printf("Welcome to Mastermind");
	int play = 1;
	int gamemode;
	
	// mode selection
	printf("Choose game mode:\n");  
	printf("1. Player vs Computer\n");
	printf("2. Player vs Player\n");
	scanf("%d", &gamemode);

	player_t player1;
	player_t player2;
	players_creation(gamemode, &player1, &player2);
	
// run until player decides to stop playing
	while (play) {
	game_t* game = game_create(gamemode, &player1, &player2);
	
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
```
  

## Header files

  
### peg.h

```c
#ifndef  PEG_H
#define  PEG_H

#include  <stdbool.h>

// opaque peg structure
typedef  struct  peg_t  peg_t;

// function prototypes
peg_t* peg_create(int color);
void peg_free(peg_t* peg);

bool peg_equals(const peg_t* a, const peg_t* b);
#endif // PEG_H

```


### code.h

```c
#ifndef CODE_H
#define CODE_H
#include "peg.h"

// opaque player structure
typedef struct code_t code_t;

// function prototypes
code_t* code_create_random(void);
code_t* code_create_manual(void);
void  code_free(code_t* code);

void code_compare(const code_t* secret,const code_t* guess, 
					int* total_match, int* partial_match);

peg_t*  get_peg(const code_t* code, int index);
#endif // CODE_H
```

  

### attempt.h

```c
#ifndef ATTEMPT_H
#define ATTEMPT_H
#include "code.h"

// opaque player structure
typedef struct attempt_t attempt_t;

// function prototypes
attempt_t* attempt_create(code_t* guess);
void attempt_free(attempt_t* attempt);

void attempt_evaluate(attempt_t* attempt, const code_t* secret);
#endif // ATTEMPT_H

```


### player.h

```c
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
```


### game.h

```c
#ifndef GAME_H
#define GAME_H
#include "player.h"

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
```