#ifndef STACK_H
#define STACK_H
#include "Item.h"

void STACKinit(void *stack, Item maxN);
Item STACKpop(void *stack, int i);
Item STACKlook(void *stack, int pos);
void STACKpush(void *stack, Item item);
int STACKempty(void *stack);
void STACKdestroy(void *stack);

#endif
