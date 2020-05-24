// Linked list version of shell sort
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "LIST.h"

// Shellsort
/*
void shellsort(link a, int l, int r)
{
    int i;
    int j;
    int h;
    link x;

    for (h = 1; h <= (r-l)/9; h = 3*h+1);

    for (h = h ; h > 0; h /= 3){
        for (i = l + h; i <= r; i++){
            
        }
    }
}*/

int main(int argc, char *argv[]){
    int N = 20;
    link list1 = init(N);
    show(list1);
    bubbleSort(list1, 1);
    show(list1);
    destroyList(list1);
    return 0;
}

