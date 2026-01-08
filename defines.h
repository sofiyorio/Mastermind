#ifndef DEFINES_H
#define DEFINES_H

#define CODE_LENGTH 4 // The fixed length of the code
#define MAX_ATTEMPTS 10 // The fixed amount of attempts

#define MAX_CHAR 50 // Maximum amount of characters for player names

#define NUM_COLORS 8 // The fixed amount of peg colors

// ANSI Color Codes
#define COLOR_RED     "\033[38;2;233;87;79m"
#define COLOR_ORANGE "\033[38;2;255;161;74m"
#define COLOR_YELLOW "\033[38;2;255;220;66m"
#define COLOR_GREEN "\033[38;2;102;222;58m"
#define COLOR_BLUE "\033[38;2;79;143;216m"
#define COLOR_PURPLE "\033[38;2;152;85;197m"
#define COLOR_PINK "\033[38;2;255;79;149m"
#define COLOR_BLACK "\033[0m"

// ANSI Formatting Codes
#define BOLD "\033[1m"
#define ITALICS "\033[3m"
#define RESET "\033[0m"

#define LINE_UP "\x1b[1F" // Moves cursor to beginning of one line up
#define DELETE "\x1b[2K" // Erases the line in terminal

#endif // DEFINES_H