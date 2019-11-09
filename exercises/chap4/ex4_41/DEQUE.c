#include <stdlib.h>
#include "DEQUE.h"
#include "stdio.h"

// DEQUE INTERFACE

static Item *deque;
static int max;
static int head = 0;
static int tail;

void QUEUEerror(){
    printf("Operation not available\n");
}

void QUEUEinit(int maxN){
    tail = -1;
    max = maxN;
    deque = malloc(maxN * sizeof(Item));
}

int QUEUEempty(){
    return(tail == -1);
}
// Place at the end of the dequeue
void QUEUEput(Item item)
{
    if (tail == -1){
        deque[0] = item;
        tail = 0;
    }
    else if (tail < max - 1){
        deque[++tail] = item;
    }
    else{
        QUEUEerror();
    }
}
// Place at the beginning of the dequeue
void QUEUEpush(Item item)
{
    if (tail == -1){
        deque[0] = item;
        tail = 0;
    }
    else if (tail < max - 1){
        for (int i = max - 2;i >= 0; i--){
            deque[i + 1] = deque[i];
        }
        deque[head] = item;
        tail = tail + 1;
    }
    else{
        QUEUEerror();
    }
}

Item QUEUEpop()
{
    if (tail == -1){
        QUEUEerror();
        return 0;
    }
    Item item = deque[tail--];
    return item;
}

Item QUEUEget()
{
    if (tail == -1){
        QUEUEerror();
        return 0;
    }
    Item item = deque[head];
    for (int i = 1; i < max; i++){
        deque[i - 1] = deque[i];
    }
    tail -= 1;
    return item;
}

void QUEUEdestroy(){
    free(deque);
}