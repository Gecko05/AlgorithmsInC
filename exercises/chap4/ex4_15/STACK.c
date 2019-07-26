#include "STACK.h"
#include <stdlib.h>

static int max_n;
static int N;
static Item *s;
void STACKinit(int maxN)
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
