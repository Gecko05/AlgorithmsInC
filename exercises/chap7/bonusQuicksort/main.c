// Quicksort Program 7.1 and 7.2 merged WIP
#include "Item.h"
#include "stdlib.h"
#include "stdio.h"

#define exch(a, b) 

int less(Item a, Item b)
{
    return a < b;
}

// Partioning for quicksort

int partition(Item a[], int l, int r)
{
    int i = l-1;
    int j = r;
    Item v = a[r];

    for (;;){
        while (less(a[++i], v));
        while (less(v, a[--j])){
            if (j == l){
                break;
            }
        }
        if (i >= j){
            break;
        }
        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

void quicksort(Item a[], int l, int r){
    int i;
    if (r <= l){
        return;
    }
    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

int main(int argc, char *argv[])
{
    int N = 10;
    Item *s = malloc(sizeof(*s) * N);
    for (int i = 0; i < N; i++){
        s[i] = i;
    }
    free(s);
}