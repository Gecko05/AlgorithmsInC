#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

stack_p op_stack;
stack_p int_stack;

Item eval_op(){
char a = STACKpop(op_stack);
    if (a == '+'){
        Item _a = STACKpop(int_stack);
        Item _b = STACKpop(int_stack);
        Item _c = _a + _b;
        STACKpush(int_stack, _c);
    }
    if (a == '*'){
        STACKpush(int_stack, STACKpop(int_stack)*STACKpop(int_stack));
    }
    if (a == '-'){
        Item _a = STACKpop(int_stack);
        Item _b = STACKpop(int_stack);
        Item _c = _b - _a;
        STACKpush(int_stack, _c);
    }
    if (a == '/'){
        Item _a = STACKpop(int_stack);
        Item _b = STACKpop(int_stack);
        Item _c = _b / _a;
        STACKpush(int_stack, _c);
    }
}

void main(int argc, char *argv[]){
    char *a = argv[1];
    int N = strlen(a);
    op_stack = STACKinit(N);
    int_stack = STACKinit(N);
    for (int i = 0; i < N; i++){
        if (a[i] == ')'){
            eval_op();
        }
        if ((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/') || (a[i] == '$')){
            STACKpush(op_stack, a[i]);
        }
        if ((a[i] >= '0') && (a[i] <= '9')){
            STACKpush(int_stack, a[i] - '0');
        }
    }
    while (!STACKempty(op_stack) && !STACKempty(int_stack)){
        eval_op();
    }
    printf("\nResult: %i\n", STACKpop(int_stack));
}