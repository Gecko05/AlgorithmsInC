#include "STACK.h"
#include <stdlib.h>

static Item *s;
static int N;
static int stackSize;

static void STACKerror(){
  printf("Invalid operation\n");
}

void STACKinit(int maxN)
{
  s = malloc(maxN * sizeof(Item));
  stackSize = maxN;
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
  if (N <= 0 || N >= staclSize){
    return STACKerror();
  }
  else{
    return s[--N];
  }
}
