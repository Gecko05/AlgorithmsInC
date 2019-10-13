#include <stdlib.h>
#include "Item.h"
#include "stdio.h"
typedef struct STACKnode* link;
struct STACKnode{
  Item item;
  link next;
  link prev;
};
static link head;
static link tail;
void STACKerror(){
  printf("The system is not able to perform this operation\n");
  return;
}
link NEW(Item item, link next, link prev){
  link x = malloc(sizeof(*x));
  if (x == NULL){
    STACKerror();
    return NULL;
  }
  x->item = item;
  x->next = next;
  x->prev = prev;
  if (prev != NULL){
    prev->next = x;
  }
  if (next != NULL){
    next->prev = x;
  }
  return x;
}
void STACKinit(int maxN){
  head = NULL;
  tail = head;
}
int STACKempty(){
  return tail == NULL;
}
void STACKpush(Item item){
  link t = NEW(item, tail, NULL);
  if (head == NULL){
    head = t;
  }
  tail = t;
}
Item STACKpop(){
  if (STACKempty()){
    STACKerror();
    return 0;
  }
  Item item = tail->item;
  link t = tail->prev;
  if (t != NULL){
      t->next = NULL;
  }
  free(tail);
  tail = t;
  return item;
}
