CCFLAGS = -Wall -Wextra -fsanitize=address -g -O0

CC = @gcc

program: main.c attempt.c code.c game.c peg.c player.c
	$(CC) -o $@ $^ 

clean:
	rm -f program

.PHONY: clean
