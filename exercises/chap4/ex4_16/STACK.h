#ifndef STACK_H
#define STACK_H
#include "Item.h"

typedef struct stack{
  Item *s;
  int N;
}Stack;

typedef Stack* stack_p;

stack_p STACKinit(Item maxN);
Item STACKpop(stack_p stack);
void STACKpush(stack_p stack, Item item);
int STACKempty(stack_p stack);

#endif
