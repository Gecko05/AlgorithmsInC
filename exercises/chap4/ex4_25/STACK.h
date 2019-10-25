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

int STACK1empty();
int STACK2empty();

#endif // STACK_H
