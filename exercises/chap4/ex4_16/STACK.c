#include "STACK.h"
#include <stdlib.h>

static int max_n;
static int N;

stack_p STACKinit(Item maxN)
{
  max_n = maxN;
  Item *s = malloc(maxN * sizeof(Item));
  N = 0;
  stack_p sp = malloc(sizeof(*sp));
  sp->s = s;
  sp->N = N;
  return sp;
}

int STACKempty(stack_p stack)
{
  return !stack->N;
}

void STACKpush(stack_p stack, Item item)
{
  if(max_n > stack->N)
    stack->s[stack->N++] = item;
}

Item STACKpop(stack_p stack)
{
  if(stack->N != 0)
    stack->N--;
    return stack->s[stack->N];
}

void STACKdestroy(stack_p stack){
  free(stack);
}
