#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

Item eval_op(){
    char a = STACK2pop();
    if (a == '+'){
        Item _a = STACK1pop();
        Item _b = STACK1pop();
        Item _c = _a + _b;
        STACK1push(_c);
    }
    if (a == '*'){
        STACK1push(STACK1pop()*STACK1pop());
    }
    if (a == '-'){
        Item _a = STACK1pop();
        Item _b = STACK1pop();
        Item _c = _b - _a;
        STACK1push(_c);
    }
    if (a == '/'){
        Item _a = STACK1pop();
        Item _b = STACK1pop();
        Item _c = _b / _a;
        STACK1push(_c);
    }
}

void main(int argc, char *argv[]){
    char *a = argv[1];
    int N = strlen(a);
    STACKSinit(N);
    for (int i = 0; i < N; i++){
        if (a[i] == ')'){
            eval_op();
        }
        if ((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/') || (a[i] == '$')){
            STACK2push(a[i]);
        }
        if ((a[i] >= '0') && (a[i] <= '9')){
            STACK1push(a[i] - '0');
        }
    }
    while (!STACK2empty() && !STACK1empty()){
        eval_op();
    }
    printf("\nResult: %i\n", STACK1pop());
}