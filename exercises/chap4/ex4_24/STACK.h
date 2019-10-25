#ifndef STACK_H
#define STACK_H
#include "Item.h"

void STACKSinit();

void STACK1push(Item item);
void STACK2push(Item item);

Item STACK1pop();
Item STACK2pop();

void destroySTACKS();

void STACKSprint();

#endif // STACK_H
