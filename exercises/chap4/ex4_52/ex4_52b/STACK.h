#ifndef STACK_H
#define STACK_H
#include "Item.h"
#include <stdio.h>

void QUEUEinit(int maxN);
Item QUEUEget(void);
void QUEUEput(Item item);
int QUEUEempty(void);

#endif
