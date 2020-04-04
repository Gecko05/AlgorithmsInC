#include "sort.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

void sort(Item a[], int l, int r)
{
    int i;
    int j;
    for (i = l+1; i <=r; i++){
        for (j = i; j > l; j--){
            compexch(a[j-1], a[j]);
        }
    }
}