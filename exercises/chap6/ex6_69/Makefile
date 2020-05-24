CC = gcc
CFLAGS = -g -Wall
OBJS = LIST.o main.o
DEPS = Item.h LIST.h

all: main

main: $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS) 

%.o: %.c $(DEPS)
	$(CC) $(CLFAGS) -c -o $@ $<

clean:
	rm *.o main