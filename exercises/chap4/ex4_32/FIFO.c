#include <stdlib.h>
#include "Item.h"

// FIFO queue arrya implementation with error call
static Item *q;
static int N;
static int head;
static int tail;

void QUEUEerror(){
    printf("Operation not available");
}

void QUEUEinit(int maxN){
    q = malloc((maxN+1)*sizeof(Item));
    N = maxN + 1;
    head = N;
    tail = 0;
}

int QUEUEempty(){
    return head % N == tail;
}

int QUEUEput(Item item){
    if ((tail + 1) % N == head){
        QUEUEerror();
        return;
    }
    q[tail++] = item;
    tail = tail % N;
}

Item QUEUEget(){
    if (QUEUEempty()){
        QUEUEerror();
        return;
    }
    head = head % N;
    return q[head++];
}