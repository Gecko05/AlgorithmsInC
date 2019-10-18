#ifndef STACK_H
#define STACK_H
#include "Item.h"

void STACKSinit(int maxN);
void destroyStacks();
// Stacks Array
static Item *stacks;
static int index1;
static int index2;
static int maxN;

static void pushIntoStack(Item item, int num){
  if (index2 <= 0 || index1 >= maxN * 2){
    return;
  }
  if (index2 - index1 <= 1){
    if (num == 1){
      stacks[index1++] = item;
      index2--;
    }
    else if (num == 2){
      stacks[index2++] = item;
      index1--;
    }
  }
  else{
    if (num == 1){
      stacks[index1++] = item;
    }
    else if (num == 2){
      stacks[index2++] = item;
    }
  }
}

static Item popFromStack(int num){
    if (num == 1){
        return stacks[--index1];
    }
    else if (num == 2){
        return stacks[--index2];
    }
}

struct Stack{
  const struct stack_vtable_ *vtable_;
}Stack;

struct stack_vtable_{
  const void *(*push)(Item item);
  const Item (*pop)();
}

static inline const *stack_push(struct Stack *stack, Item item){
  return stack->vtable_->push(item);
}

static inline const Item stack_pop(struct Stack *stack){
  return stack->vtable_->pop();
}

static const void *STACK1_push(Item item){
  // Send 1 because the first stack is being used
  pushIntoStack(item,1);
}

static const Item STACK1_pop(){
  // Send 1 because the first stack is being used
  popFromStack(1);
}

static const void *STACK2_push(Item item){
  // Send 1 because the first stack is being used
  pushIntoStack(item,2);
}

static const Item STACK2_pop(){
  // Send 1 because the first stack is being used
  popFromStack(2);
}

extern const struct stack_vtable_ STACK1[], STACK2[];

#endif // STACK_H
