CC = gcc
CFLAGS = -Wall -Wextra -O0 -g
LIST_DIR = ../../list
INC = -I ${LIST_DIR}/src

all: main
	./main
main: main.o liblist.so
	$(CC) ${CFLAGS} -o $@ main.o -L ${LIST_DIR}/build -llist

main.o: main.c
	$(CC) ${CFLAGS} ${INC} -c $<

liblist.so:
	make -C ${LIST_DIR} all

clean:
	rm -rf main *.o
	make -C ${LIST_DIR} clean
