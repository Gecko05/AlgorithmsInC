#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

char get_infix(void *stack, int pos){
    if (STACKempty(&stack)){
        return 0;
    }
    char n = STACKpop(&stack, pos);
    if (n >= '0' && n <= '9'){
        return n;
    }
    else if (n == '*' || n == '/' || n == '*' || n == '-' || n == '+'){
        printf("(");
        printf("%c", get_infix(stack, 0));
        printf(" %c ", n);
        printf("%c", get_infix(stack, -1));
        printf(")");
    }
    return 0;
}

void main(int argc, char *argv[])
{
    char *a = argv[1];
    char N = strlen(a);
    void *stack;
    STACKinit(&stack, N);
    for (int i = 0; i < N; i++){
        if (a[i] == '*' || a[i] == '/' || a[i] == '*' || a[i] == '-' || a[i] == '+'){
            STACKpush(&stack, a[i]);
        }
        if (a[i] >= '0' && a[i] <= '9'){
            STACKpush(&stack, a[i]);
        }
    }
    get_infix(stack, 0);

    STACKdestroy(&stack);
    stack = NULL;
    printf("\n");
}


/*
char get_infix(char *a, int i){
    if (i < 0){
        return 0;
    }
    if (a[i] == '*' || a[i] == '/' || a[i]  == '+' || a[i] == '-'){
        int i0 = (a[i - 1] != ' ') ? i - 1 : i - 2;
        int i1 = (a[i0 - 1] != ' ') ? i0 - 1: i0 - 2;
        if (i0 >= 0 && i1 >= 0){
            printf("(");
            printf("%c ", get_infix(a, i0));
            printf("%c ", a[i]);
            printf("%c", get_infix(a, i1));
            printf(") ");
        }
        else{
            return 0;
        }
    }
    else if (a[i] >= '0' && a[i] <= '9'){
        return a[i];
    }
}*/
