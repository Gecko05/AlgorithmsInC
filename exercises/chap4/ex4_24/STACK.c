#include <stdlib.h>
#include "Item.h"
#include "stdio.h"
#include "STACK.h"

const struct stack_vtable_ STACK1[] = { { STACK1_push, STACK1_pop }};

const struct stack_vtable_ STACK2[] = { { STACK2_push, STACK2_pop }};

void STACKerror(){
  printf("The system is not able to perform this operation\n");
  return;
}

void STACKSinit(int maxN){
  stacks = malloc(sizeof(Item) * 2 * maxN);
  index1 = 0;
  index2 = (maxN * 2) - 1;
}

void destroyStacks(){
  free(stacks);
  stacks = NULL;
}
