#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

void main(int argc, char *argv[])
{
    struct Stack stack1 = { STACK1 };
    struct Stack stack2 = { STACK2 };
    int N = 10;
    Item a = 2;
    STACKSinit(N);
    stack_push(&stack1, a);
    Item b = stack_pop(&stack1);
    printf("Item: %i\n", (int)b);
    destroyStacks();
    printf("Success\n");
}
