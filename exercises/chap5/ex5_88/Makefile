CC = gcc
CFLAGS = -g -Wall
DEPS = main.c TREE.c TREE.h

all: main

main: main.o TREE.o
	$(CC) $(CFLAGS) main.o TREE.o -o main

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main