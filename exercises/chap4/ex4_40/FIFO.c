#include <stdlib.h>
#include "FIFO.h"
#include "stdio.h"

// DEQUE INTERFACE

typedef struct node* link;
struct node {
    Item item;
    link next;
};

static link head;
static link tail;
static int eNum;
static int cnt = 0;

void QUEUEerror()
{
    printf("Operation not available\n");
}

void QUEUEinit(int maxN)
{
    head = malloc(sizeof(*head));
    link t = head;
    for (int i = 0;i < maxN - 1; i++){
        link x = malloc(sizeof(*x));
        t->next = x;
        t = t->next;
    }
    t->next = head;
    tail = NULL;
}

int QUEUEempty()
{
    return (tail == NULL);
}
// Place at the end of the queue
void QUEUEput(Item item)
{
    if (tail == NULL){
        tail = head->next;
        tail->item = item;
    }
    else if (tail->next != head){
        tail = tail->next;
        tail->item = item;
    }
    else{
        QUEUEerror();
    }
}
// Get the first item in the queue
Item QUEUEget()
{
    if (QUEUEempty()){
        QUEUEerror();
        return 0;
    }
    Item item = head->item;
    head = head->next;
    if (head == tail){
        tail = NULL;
    }
}
