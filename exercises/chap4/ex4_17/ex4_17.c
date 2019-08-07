#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

stack_p op_stack;
stack_p int_stack;
stack_p type_stack;

int vars[27];

int popVar(void){
    Item v = STACKpop(int_stack);
    int type = STACKpop(type_stack);
    return v - 'a';
}

Item popVarOrVal(void){
    Item v = STACKpop(int_stack);
    int type = STACKpop(type_stack);
    if (type == 'v'){
        int u = v - 'a';
        return vars[u];
    }
    else{
        return v;
    }
}

Item eval_op(void){
    char a = STACKpop(op_stack);
    if (a == '+'){
        Item _a = popVarOrVal();
        Item _b = popVarOrVal();
        Item _c = _a + _b;
        STACKpush(int_stack, _c);
        STACKpush(type_stack, 'i');
    }
    if (a == '*'){
        Item _a = popVarOrVal();
        Item _b = popVarOrVal();
        Item _c = _a * _b;
        STACKpush(int_stack, _c);
        STACKpush(type_stack, 'i');
    }
    if (a == '-'){
        Item _a = popVarOrVal();
        Item _b = popVarOrVal();
        Item _c = _b - _a;
        STACKpush(int_stack, _c);
        STACKpush(type_stack, 'i');
    }
    if (a == '/'){
        Item _a = popVarOrVal();
        Item _b = popVarOrVal();
        Item _c = _b / _a;
        STACKpush(int_stack, _c);
        STACKpush(type_stack, 'i');
    }
    if (a == '='){
        Item _a = popVarOrVal();
        Item _v = popVar();
        vars[_v] = _a;
    }
}

void main(int argc, char *argv[]){
    char *a = argv[1];
    int N = strlen(a);
    memset(vars, 27, 0);
    op_stack = STACKinit(N);
    int_stack = STACKinit(N);
    type_stack = STACKinit(N);
    for (int i = 0; i < N; i++){
        if (a[i] == ')'){
            eval_op();
        }
        if ((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/') || (a[i] == '$') || (a[i] == '=')){
            STACKpush(op_stack, a[i]);
        }
        if (a[i] >= '0' && a[i] <= '9'){
            STACKpush(int_stack, a[i] - '0');
            STACKpush(type_stack, 'i');
        }
        if (a[i] >= 'a' && a[i] <= 'z'){
            STACKpush(int_stack, a[i]);
            STACKpush(type_stack, 'v');
        }
    }
    while (!STACKempty(op_stack) && !STACKempty(int_stack)){
        printf("sup");
        eval_op();
    }
    printf("\nResult: %i\n", popVarOrVal());
}