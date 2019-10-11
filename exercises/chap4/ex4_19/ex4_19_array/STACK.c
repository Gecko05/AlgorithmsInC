#include "STACK.h"
#include <stdlib.h>

static Item *s;
static int N;

void STACKinit(int maxN)
{
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int STACKcount()
{
  return N;
}

void STACKpush(Item item)
{
  s[N++] = item;
}

Item STACKpop()
{
  return s[--N];
}
