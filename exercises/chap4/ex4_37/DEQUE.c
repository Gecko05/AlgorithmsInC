#include <stdlib.h>
#include "Item.h"

typedef struct QUEUEnode *link;
struct QUEUEnode{
    Item item;
    link next;
    link prev;
};

static link head;
static link tail;

void QUEUEerror(){
    printf("Operation not available\n");
}

link NEW(Item item, link next, link prev)
{
    link x = malloc(sizeof *x);
    if (x == NULL){
        QUEUEerror();
        return;
    }
    x->item = item;
    x->next = next;
    x->prev = prev;
    return x;
}

void QUEUEinit(int maxN){
    head = NULL;
}

int QUEUEempty(){
    return head == NULL;
}
// Place at the end of the dequeue
void QUEUEput(Item item)
{
    if (head == NULL){
        tail = NEW(item,head,NULL);
        head = tail;
        return;
    }
    tail->next = NEW(item, tail->next, tail);
    tail = tail->next;
}
// Place at the beginning of the dequeue
void QUEUEpush(Item item)
{
    if (head == NULL){
        tail = NEW(item,head, NULL);
        head = tail;
        return;
    }
    head->prev = NEW(item, head, head->prev);
    head = head->prev;
}

void QUEUEpop()
{
  if (QUEUEempty()){
    QUEUEerror();
    return;
  }
  Item item = tail->item;
  link t = tail->prev;
  t->next = tail->next;
  free(tail);
  tail = t;
  return item;
}

Item QUEUEget()
{
    if (QUEUEempty()){
        QUEUEerror();
        return;
    }
    Item item = head->item;
    link t = head->next;
    t->prev = head->prev;
    free(head);
    head = t;
    return item;
}
