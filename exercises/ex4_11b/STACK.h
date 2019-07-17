#ifndef STACK_H
#define STACK_H

#include "Item.h"
#include "stdlib.h"

static Item *s;
static int n;
void STACKinit(int maxN);

Item STACKpop(void);

void STACKpush(Item item);

int STACKempty(void); 
#endif
