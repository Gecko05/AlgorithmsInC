// Sort driver for arrays

#include <stdlib.h>
#include "Item.h"
#include "Array.h"

int main(int argc, char *argv[]){
    int i;
    int N = atoi(argv[1]);
    int sw = atoi(argv[2]);
    Item *a = malloc(N*sizeof(Item));
    if (sw){
        randinit(a, N);
    }
    else{
        scaninit(a, %N);
    }
    sort(a, 0, N-1);
    show(a, 0, N-1);
}