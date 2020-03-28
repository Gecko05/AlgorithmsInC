#include <stdlib.h>
#include "DEQUE.h"

// DEQUE INTERFACE

typedef struct QUEUEnode *link;
struct QUEUEnode{
    Item item;
    link next;
    link prev;
};

Item empty = 0;
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
        return empty;
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

Item QUEUEpop()
{
  if (QUEUEempty()){
    QUEUEerror();
    return empty;
  }
  Item item = tail->item;
  link t = tail->prev;
  if (t != NULL){
    t->next = tail->next;
  }
  else{
      head = NULL;
  }
  free(tail);
  tail = t;
  return item;
}

Item QUEUEget()
{
    if (QUEUEempty()){
        QUEUEerror();
        return empty;
    }
    Item item = head->item;
    link t = head->next;
    if (t != NULL){
        t->prev = head->prev;
    }
    free(head);
    head = t;
    return item;
}

void QUEUEdestroy()
{
    link x = head;
    while (!QUEUEempty()){
        x = x->next;
        free(head);
        head = x;
    }
}