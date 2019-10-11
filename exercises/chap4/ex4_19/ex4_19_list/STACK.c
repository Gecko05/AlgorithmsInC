#include "STACK.h"
#include <stdlib.h>

typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };
static link head;

link NEW(Item item, link next){
  link x = malloc(sizeof(*x));
  x->item = item;
  x->next = next;
  return x;
}

void STACKinit(int maxN)
{
  head = NULL;
}

int STACKcount()
{
  int c = 0;
  link x = head;
  while(head != NULL){
    c = c + 1;
    x = x->next;
  }
  return c;
}

void STACKpush(Item item)
{
  head = NEW(item, head);
}

Item STACKpop()
{
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}
