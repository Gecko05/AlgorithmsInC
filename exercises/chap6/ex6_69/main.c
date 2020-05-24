// Linked list version of shell sort
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "LIST.h"

int main(int argc, char *argv[]){
    int N = 20;
    link list1 = init(N);
    show(list1);
    list1 = shellsort(list1, 0, N);
    show(list1);
    destroyList(list1);
    return 0;
}

