#ifndef STACK_H
#define STACK_H
#include "Item.h"

void STACKinit(int maxN);
Item STACKpop(void);
void STACKpush(Item item);
int STACKempty(void);

#endif
