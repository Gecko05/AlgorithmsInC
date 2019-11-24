#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "STACK.h"

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
{   
    link x = head;
    while (x != tail){
        if (x->item == item){
            return;
        }
        x = x->next;
    }
    if (head == NULL){
        tail = NEW(item,head);
        head = tail;
        return;
    }
    tail->next = NEW(item, tail->next);
    tail = tail->next;
}

Item QUEUEget()
{
    if (QUEUEempty()){
        QUEUEerror();
        return -1;
    }
    Item item = head->item;
    link t = head->next;
    free(head);
    head = t;
    return item;
}
