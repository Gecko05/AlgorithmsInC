#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

void main(int argc, char *argv[])
{
    int N = 6;
    Item a = 2;
    STACKSinit(N);
    for (int i = 0; i < 5; i++){
        STACK1push(i);
        STACK2push(4-i);
    }
    STACKSprint();
    for (int i = 0; i < 3; i++){
        STACK1push(i);
    }
    STACKSprint();
    for (int i = 0; i < 3; i++){
        STACK1push(i);
    }
    STACKSprint();
    for (int i = 0; i < 11; i++){
        STACK2push(i);
    }
    STACKSprint();
    destroySTACKS();
    printf("Success\n");
}
