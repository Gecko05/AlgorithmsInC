CC = gcc
CFLAGS = -Wall -g
OBJS = LIST.o main.o
DEPS = Item.h LIST.h

all: main

main: $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

%.o: %.c $(DEPS)
	$(CC) $(CLFAGS) -c $< -o $@

clean:
	rm *.o main