// Stable quicksort for lists: Work in Progress
#include <stdlib.h>
#include <stdio.h>
#include "LIST.h"
#include "Item.h"

// Sedgewick states that the partitioning for arrays is not
// stable, because any key might be moved past a large
// number of keys equal to it.

Item partition(link h, link l, link r)
{
    link t = l;
    link pt = NULL;
    link x = t;
    link px = NULL;
    for (;;){
        // Look for a big item
        while (t->item <= r->item && t != r){
            t = t->next;
        }
        x = t->next;
        // Look for a small item
        while (x->item >= r->item && x != r){
            x = x->next;
        }
        if (x == r || t == r){
            break;
        }

    }
}

void quicksort(link h, link l, link r)
{
    int i;
    if (r->item <= l->item){
        return;
    }
    i = partition(h, l, r);
    quicksort(h, l, r);
    quicksort(h, l, r);
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

int main(int argc, char *argv[]){

}