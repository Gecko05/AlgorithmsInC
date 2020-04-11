#include "sort.h"
// This file is swappable for any sort function that accepts
// three arguments: Item array, starting pos, and ending pos
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

// Bubble sort
void sort(Item a[], int l, int r)
{
    int i, j;
    int x = 0;
    for (i = l; i < r; i++){
        for (j = r; j > i; j--){
            compexch(a[j-1], a[j]);
            x = 1;
        }
        if (x == 0){
            break;
        }
    }
}