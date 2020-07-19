CC = gcc
CFLAGS = -Iinclude -c -Wall -Wextra -pedantic -Werror -Wmissing-prototypes

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

.PHONY: all clean

%.o: %.c
	@echo "  CC  $@"
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f src/*.o *.out