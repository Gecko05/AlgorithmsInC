#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"
void main(int argc, char *argv[])
{
    char *a = argv[1];
    int N = strlen(a);
    STACKinit(N);
    for (int i = 0; i < N; i++){
        if (a[i] == ')'){
            printf("%c ", STACKpop());
        }
        if ((a[i] == '+') || (a[i] == '*')){
            STACKpush(a[i]);
        }
        if ((a[i] >= '0') && (a[i] <= '9')
            && ((a[i + 1] < '0') || (a[i + 1] > '9'))){
            printf("%c ", a[i]);
        }
        else if ((a[i] >= '0') && (a[i] <= '9') 
            && (a[i + 1] >= '0') && (a[i + 1] <= '9')){
            printf("%c", a[i]);
        }
    }
    printf("\n");
}