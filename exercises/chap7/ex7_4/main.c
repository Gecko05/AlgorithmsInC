// Stable quicksort for lists: Work in Progress, currently a mess
#include <stdlib.h>
#include <stdio.h>
#include "LIST.h"
#include "Item.h"

int getLinkLen(link h){
    int c = 0;
    while (h != NULL){
        h = h->next;
        c++;
    }
    return c;
}

link partition(link h, link *l, link *g)
{
    int vLen = getLinkLen(h);
    int m = vLen / 2;
    link y = h;
    link lm = NULL;
    link gm = NULL;
    for (int i = 0; i < m; i++){
        y = y->next;
    }
    // Fill the lesser list
    link x = h;
    int c = 0;
    while (x != NULL){ // * Something needs to be done for the "y" link ? Maybe there is a case in which y gets processed?
        if ((x->item < y->item) ||
            ((x->item == y->item) && c < m)){
            if (lm == NULL){
                lm = x;
                *l = lm; // head for the lesser list
            }
            else{
                lm->next = x;
                lm = lm->next;
            }
        }
        else if((x->item > y->item) ||
            ((x->item == y->item) && c > m)){
            if (gm == NULL){
                gm = x;
                *g = gm; // head for the greater list
            }
            else{
                gm->next = x;
                gm = gm->next;
            }
        }
        x = x->next;
        c++;
    }
    if (lm != NULL){
        lm->next = NULL;
    }
    if (gm != NULL){
        gm->next = NULL;
    }
    return y;
}

link quicksort(link h)
{
    link lesser = NULL;
    link greater = NULL;
    if (h == NULL || h->next == NULL){
        return h;
    }
    link p = partition(h, &lesser, &greater);
    printf("Lesser: ");
    show(lesser); // Good way to know if we're stuck with a circular list on either lesser or greater
    printf("Greater: ");
    show(greater);
    printf("Pivot: %i\n", p->item);
    lesser = quicksort(lesser);
    greater = quicksort(greater);
    if (lesser != NULL){
        link lx = lesser;
        while (lx->next != NULL){ // Need to look for the last element of the lesser list to do the merge
            lx = lx->next;
        }
        lx->next = p;
    }
    p->next = greater;
    printf("Merged: ");
    if (lesser != NULL){
        show(lesser);
        return lesser;
    }
    else{
        show(p);
        return p;
    }

}

int main(int argc, char *argv[]){
    link x = malloc(sizeof(*x));
    link h = init(10);
    show(h);
    h = quicksort(h);
    show(h);
    destroyList(h);
}