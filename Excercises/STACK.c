#include "STACK.h"
#include "Item.h"
#include <stdlib.h>

void STACKinit(Item maxN)
{
  max_n = maxN;
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int STACKempty()
{
  return !N;
}

void STACKpush(Item item)
{
  if(max_n > N)
    s[N++] = item;
}

Item STACKpop()
{
  if(N != 0)
    N--;
    return s[N];
}
