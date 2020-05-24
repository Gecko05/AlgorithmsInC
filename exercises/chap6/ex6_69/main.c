// Linked list version of shell sort
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "LIST.h"

// Shellsort
/*
void shellsort(Item a[], int l, int r)
{
    int i;
    int j;
    int h;

    for (h = 1; h <= (r-l)/9; h = 3*h+1);

    for (h = h ; h > 0; h /= 3){
        for (i = l + h; i <= r; i++){
            int j = i;

            Item v = a[i];
            while (j >= l+h && less(v, a[j-h])){
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = v;
        }
    }
}*/

int main(int argc, char *argv[]){
    return 0;
}

