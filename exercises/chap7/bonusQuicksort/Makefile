CC = gcc
CFLAGS = -g -Wall
OBJS = main.o 

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main
