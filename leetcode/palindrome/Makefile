CC = gcc
CFLAGS = -Wall -Wextra -O0 -g

all: main
	./main
main: main.c
	$(CC) ${CFLAGS} main.c -o main
clean:
	rm -rf main *.o *.dSYM
