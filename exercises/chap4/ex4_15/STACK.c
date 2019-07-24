#include "STACK.h"
#include <stdlib.h>

typedef struct stack{
  Item *items;
  int N;
}stackS;

typedef stackS* stack_ptr;

void STACKinit(void *stack, Item maxN)
{
  stack_ptr s = malloc(sizeof(struct stack));
  Item *a = malloc(sizeof(Item) * maxN);
  s->items = a;
  s->N = 0;
  *((stackS**)stack) = s;
  return;
}

int STACKempty(void *stack)
{
  stack_ptr s = *((stack_ptr*)(stack));
  return (s->N == 0);
}

void STACKpush(void *stack, Item item)
{
  stack_ptr s = *((stack_ptr*)(stack));

  s->items[s->N] = item;
  s->N++;
}

Item STACKpop(void *stack, int pos)
{
  if (!STACKempty(stack) || pos <= 0){
    stack_ptr s = *((stack_ptr*)(stack));

    int p = s->N + pos - 1;
    Item r = s->items[p];
    s->N--;
    for (int i = p; i < s->N; i++){
      s->items[i] = s->items[i + 1];
    }
    return r;
  }
}

void STACKdestroy(void *stack)
{
  stack_ptr s = *((stack_ptr*)(stack));

  free(s->items);
  s->items = NULL;
  free(s);
}
