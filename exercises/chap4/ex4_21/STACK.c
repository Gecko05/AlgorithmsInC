#include "STACK.h"
#include <stdlib.h>
#include <string.h>

static Item *s;
static int *n;
static int N;
static int stackSize;
static int head;

static int NEW(Item item, int next){
  s[N++] = item;
  n[N] = next;
}

void STACKinit(int maxN)
{
  s = malloc(maxN * sizeof(Item));
  n = malloc(maxN * sizeof(int));
  memset(s, 0, maxN);
  stackSize = maxN;
  head = 0;
  N = 0;
}

int STACKempty()
{
  return N == 0;
}

void STACKpush(Item item)
{
  head = NEW(item, head);
}

Item STACKpop()
{
  Item item = s[head];
  head = n[head];
  N--;
  return item;
}
