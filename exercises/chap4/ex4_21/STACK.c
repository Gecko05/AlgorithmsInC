#include <stdlib.h>
#include "Item.h"
typedef struct STACKnode* link;
struct STACKnode{
  Item item;
  link next;
}
static link head;
void STACKerror(){
  printf("The system is not able to perform this operation\n");
  return;
}
link NEW(Item item, link next){
  link x = malloc(sizeof(*x));
  if (x == NULL){
    return STACKerr();
  }
  x->item = item;
  x->next = next;
  return x;
}
void STACKinit(int maxN){
  head = NULL;
}
int STACKempty(){
  return head == NULL;
}
void STACKpush(Item item){
  head = NEW(item, head);
}
Item STACKpop(){
  if (STACKempty){
    return STACKerror();
  }
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}
