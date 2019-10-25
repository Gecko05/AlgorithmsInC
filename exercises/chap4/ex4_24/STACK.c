#include <stdlib.h>
#include "Item.h"
#include "stdio.h"
#include "STACK.h"

static Item *stacks;
static int i1;
static int i2;
static int maxN;

void STACKerror(){
  printf("The system is not able to perform this operation\n");
  return;
}

void STACKSinit(int max){
  maxN = max;
  stacks = malloc(sizeof(Item) * 2 * maxN);
  i1 = 0;
  i2 = (maxN * 2) - 1;
}

void STACK1push(Item item){
  if (i1 < (maxN * 2 - 1)){
    if (i1 >= i2){
      i2++;
    }
    stacks[i1++] = item;
  }
  else{
    STACKerror();
  }
}

void STACK2push(Item item){
  if (i2 > 0){
    if (i2 <= i1){
      i1--;
    }
    stacks[i2--] = item;
  }
  else{
    STACKerror();
  }
}

Item STACK1pop(){
  if (i1 > 0){
    return stacks[--i1];
  }
  else{
    STACKerror();
  }
}

Item STACK2pop(){
  if (i2 < (maxN * 2 - 1)){
    return stacks[++i2];
  }
  else{
    STACKerror();
  }
}

void destroySTACKS(){
  free(stacks);
  stacks = NULL;
}

void STACKSprint(){
  printf("STACK 1: ");
  for (int i = 0; i < i1; i++){
    printf("%i ", stacks[i]);
  }
  printf("\n");
  printf("STACK 2: ");
  for (int i = maxN * 2 - 1; i > i2; i--){
    printf("%i ", stacks[i]);
  }
  printf("\n");
}
