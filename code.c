#include "peg.h"
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"

typedef struct {
	peg_t *pegs[CODE_LENGTH]; // array of pointer to pegs
} code_t;

// Miru :)
code_t* code_create_random(void) {
	code_t* code = malloc(sizeof(code_t));
	if(!code) return NULL;

	for ( int i = 0; i < CODE_LENGTH; i ++ ) {
		int color = rand() % NUM_COLORS;
		code->pegs[i] = peg_create(color);
	}

	printf("Generating secret code...\n"); 

	return code;
}

// Miru :)
code_t* code_create_manual(void) {
	code_t* code = malloc(sizeof(code_t));
	char* codePrint[CODE_LENGTH];
	if (!code) return NULL;

	printf("Enter %d colors: ", CODE_LENGTH);
	printf("%s0 = RED, %s1 = ORANGE, %s2 = YELLOW, %s3 = GREEN, %s4 = BLUE, %s5 = PURPLE, %s6 = PINK, %s7 = BLACK.\n", 
		COLOR_RED, COLOR_ORANGE, COLOR_YELLOW, COLOR_GREEN, COLOR_BLUE, COLOR_PURPLE, COLOR_PINK, COLOR_BLACK);
	
	for ( int i = 0; i < CODE_LENGTH; i ++ ) {
		int color;
		while(1) {
			printf("Color of peg %d should be: ", i + 1);
			
			if ( scanf("%d", &color) != 1 ) { // checks if input is a number
				while (getchar() != '\n'); // if user types a character it clears input
				printf("Please enter a valid number! :(\n");
				continue; // skipping the rest of the loop
			}
			switch(color) {
			case 0:
				codePrint[i] = COLOR_RED;	break;
			case 1:
				codePrint[i] = COLOR_ORANGE;	break;
			case 2:
				codePrint[i] = COLOR_YELLOW;	break;
			case 3:
				codePrint[i] = COLOR_GREEN;	break;
			case 4:
				codePrint[i] = COLOR_BLUE;	break;
			case 5:	
				codePrint[i] = COLOR_PURPLE;	break;
			case 6:
				codePrint[i] = COLOR_PINK;	break;
			case 7:
				codePrint[i] = COLOR_BLACK;	break;
			}

			if ( color >= 0 && color < NUM_COLORS) break;
			printf("Hmm... the number you entered isn't right. :/ \n"); // in case the number entered isn't in the set range
		}
		
		code->pegs[i] = peg_create(color);
	}

	printf("\nThe code you created is: %s%s0 %s0 %s0 %s0 %s \n", BOLD, codePrint[0], codePrint[1], codePrint[2], codePrint[3], RESET);
	return code;
}

// Miru :)
void code_free(code_t* code) {
	if (!code) return; // safety check :P

	for ( int i = 0; i < CODE_LENGTH; i ++ ) { // freeing each peg
		peg_free(code->pegs[i]);
	}

	free(code); // freeing the struct

}

// Miru :)
void code_compare(const code_t* secret, const code_t* guess, int* total_match, int* partial_match) {

	*total_match = 0;
	*partial_match = 0;

	// to prevent recounting pegs
	bool secret_used[CODE_LENGTH] = {false};
	bool guess_used[CODE_LENGTH] = {false};

	// exact matches
	for ( int i = 0; i < CODE_LENGTH; i ++ ) {
		if ( peg_equals(secret->pegs[i], guess->pegs[i])) {
			(*total_match)++;
			secret_used[i] = true;
			guess_used[i] = true;
		}
	}

	// partial matches
	for ( int i = 0; i < CODE_LENGTH; i ++ ) {
		if ( guess_used[i] ) continue; // skip exact matches
		
	for ( int j = 0; j < CODE_LENGTH; j ++ ) {
		if ( secret_used[j] ) continue;

	// color match
if ( peg_equals(secret->pegs[j], guess->pegs[i])) {
	(*partial_match)++;
	secret_used[j] = true;
	break;
			}
		}
	}
}

// Miru :)
peg_t* get_peg(const code_t* code, int index) {
	if (!code) return NULL; // safety check

	if (index < 0 || index >= CODE_LENGTH) return NULL; // safety check 2

	return code->pegs[index];
}