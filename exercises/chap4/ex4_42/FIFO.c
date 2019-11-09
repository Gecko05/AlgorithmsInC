#include <stdlib.h>
#include "FIFO.h"
#include <stdio.h>
#include <string.h>

// DEQUE INTERFACE
static int max;
static int *exist;
static Item *queue;
static int count;

void QUEUEerror()
{
    printf("Operation not available\n");
}

void QUEUEinit(int maxN)
{
    max = maxN;
    queue = malloc(sizeof(Item) * maxN);
    exist = malloc(sizeof(int) * maxN);
    memset(exist, 0, maxN);
    count = 0;
}

int QUEUEempty()
{
    return (count == 0);
}
// Place at the determined position
void QUEUEinsert(Item item, int pos)
{
    queue[pos] = item;
    exist[pos] = 1;
    count = count + 1;
}
// Get the first item in the queue
Item QUEUEdelete(int pos)
{
    if (QUEUEempty()){
        QUEUEerror();
        return 0;
    }
    if (exist[pos] == 1){
        Item item = queue[pos];
        count = count - 1;
        exist[pos] = 0;
        return item;
    }
}
