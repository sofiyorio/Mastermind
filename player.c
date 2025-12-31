#include  <stdbool.h>

#define MAX_CHAR 50

typedef  struct {
	char name[MAX_CHAR]; // player's name
	bool is_computer; // necessary for Player Vs Computer games
} player_t;