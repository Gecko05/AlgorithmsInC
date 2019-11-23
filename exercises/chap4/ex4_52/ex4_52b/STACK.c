#include <stdlib.h>
#include "STACK.h"
#include "Item.h"

// FIFO queue array implementation with error call
static Item *q;
static int N;
static int head;
static int tail;

void QUEUEerror(){
    printf("Operation not available\n");
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

void QUEUEput(Item item){
    if ((tail + 1) % N == head){
        QUEUEerror();
        return;
    }

    int c = head;
    while (c != tail){
        if (q[c] == item){
            // Rearrange queue
            while (c != tail){
                int n = (c + 1) % N; // Next position in queue
                q[c] = q[n];
                c = n;
            }
            tail = (tail - 1) % N;
            break;
        }
        c = (c + 1) % N;
    }

    q[tail++] = item;
    tail = tail % N;
}

Item QUEUEget(){
    if (QUEUEempty()){
        QUEUEerror();
        return -1;
    }
    head = head % N;
    return q[head++];
}