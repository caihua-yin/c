CC = gcc
CFLAGS = -Wall -Wextra -O0 -g
HASHMAP_DIR = ../../hashmap.c
INC = -I ${HASHMAP_DIR}

all: main
	./main
main: main.o libhashmap.so
	$(CC) ${CFLAGS} -o $@ main.o -L ${HASHMAP_DIR}/shared -lhashmap

main.o: main.c
	$(CC) ${CFLAGS} ${INC} -c $<

libhashmap.so:
	make -C ${HASHMAP_DIR} libhashmap.so
	mkdir -p shared
	cp ${HASHMAP_DIR}/shared/libhashmap.so shared/

clean:
	rm -rf main *.o shared/
	make -C ${HASHMAP_DIR} clean
