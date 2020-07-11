CC = gcc
CFLAGS = -g -Wall
OBJS = main.o DEQUE.o
DEPS = DEQUE.h Item.h

all: main

main: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main
