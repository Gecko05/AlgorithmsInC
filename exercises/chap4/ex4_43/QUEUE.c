#include <stdlib.h>
#include "QUEUE.h"
#include <stdio.h>
#include <string.h>

// DEQUE INTERFACE
typedef struct node* link;
struct node{
    Item item;
    link next;
};

static link head;
static int max;
static int count;
static int *exist;

void QUEUEerror()
{
    printf("Operation not available\n");
}

void QUEUEinit(int maxN)
{
    max = maxN;
    exist = malloc(sizeof(int) * max);
    memset(exist, 0, max);
    head = malloc(sizeof(*head));
    head->next = NULL;
    link t = head;
    for(int i = 0; i < maxN; i++){
        link x = malloc(sizeof(*t));
        x->next = t->next;
        t->next = x;
        t = x;
    }
    count = 0;
}

int QUEUEempty()
{
    return (count == 0);
}

link findLink(int c){
    link t = head;
    for (int i = 0; i < c; i++){
        t = t->next;
    }
    return t;
}
// Place at the determined position
void QUEUEinsert(Item item, int pos)
{
    if (pos > count){
        return;
    }
    link x = findLink(pos);
    x->item = item;
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
    link x;
    if (exist[pos] == 1){
        x = findLink(pos);
    }
    Item item = x->item;
    exist[pos] = 0;
    count = count - 1;
    return item;
}
