CC = gcc
CFLAGS = -Wall -Wextra -O0 -g
LIST_DIR = ../../list
INC = -I ${LIST_DIR}/src

all: main
	./main
main: main.o
	$(CC) ${CFLAGS} -o $@ main.o

main.o: main.c
	$(CC) ${CFLAGS} ${INC} -c $<

clean:
	rm -rf main *.o
