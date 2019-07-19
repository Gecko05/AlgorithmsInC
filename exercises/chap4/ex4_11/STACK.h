#ifndef STACK_H
#define STACK_H
#include "Item.h"

void STACKinit(Item maxN);
Item STACKpop(void);
void STACKpush(Item item);
int STACKempty(void);

#endif
