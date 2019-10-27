#include <stdlib.h>
#include "Item.h"

typedef struct QUEUEnode *link;
struct QUEUEnode{
    Item item;
    link next;
};

static link head;
static link tail;

link NEW(Item item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

void QUEUEerror(){
    printf("Operation not available\n");
}

void QUEUEinit(int maxN){
    head = NULL;
}

int QUEUEempty(){
    return head == NULL;
}

void QUEUEput(Item item)
{   if (head == NULL){
        tail = NEW(item,head);
        head = tail;
        return;
    }
    else{
        QUEUEerror();
        return;
    }
    tail->next = NEW(item, tail->next);
    tail = tail->next;
}

Item QUEUEget()
{
    if (QUEUEempty()){
        QUEUEerror();
        return;
    }
    Item item = head->item;
    link t = head->next;
    free(head);
    head = t;
    return item;
}