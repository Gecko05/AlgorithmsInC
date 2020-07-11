// Quicksort Program 7.1 and 7.2 merged WIP
#include "Item.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>

#define exch(a, b) Item c = a; a = b; b = c;

int less(Item a, Item b)
{
    return a < b;
}

void show(Item *a, int n)
{
    for (int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n");
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
    static int c = 0;
    int i;
    if (r <= l){
        return;
    }
    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
    c++;
    printf("Calls %i\n", c);
}

int main(int argc, char *argv[])
{
    time_t t;
    srand((unsigned) time(&t));
    int N = 10;
    Item *s = malloc(sizeof(*s) * N);
    for (int i = 0; i < N; i++){
        //s[i] = rand() % 10;
        s[i] = i;
    }
    show(s, N);
    quicksort(s, 0, N);
    show(s, N);
    free(s);
}