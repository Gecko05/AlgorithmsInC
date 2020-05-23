CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o main
	