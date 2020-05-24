#include "LIST.h"

link bubbleSort(link h){
    link y;
    link p_y;
    int m = 1;

    if (h == NULL || h->next == NULL || h->next->next == NULL){
        return h;
    }
    while (m == 1){
        y = h->next;
        // Inner loop
        p_y = h;
        m = 0;
        while (y != NULL){
            if (y->next != NULL && y->next->item < y->item){
                // Exchange nodes
                link n_y = y->next->next;
                y->next->next = y;
                link t = y->next;
                y->next = n_y;
                // Change the next of the previous node
                p_y->next = t;
                // Set p_y to previous node
                p_y = t;
                // Set m to notify a movement was done
                m = 1;
            }
            else{
                // Just go through the list
                p_y = y;
                y = y->next;
            }
        }
    }
    return h;
}

link NEW(Item item, link next){
    link x = malloc(sizeof(*x));
    x->item = item;
    x->next = next;
    return x;
}

link init(int N){
    link h = malloc(sizeof(*h));
    h->next = NULL;
    link x = h;
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < N; i++){
        link t = malloc(sizeof(*h));
        t->item = rand() % 10;
        t->next = NULL;
        x->next = t;
        x = x->next;
    }
    return h;
}

void show(link h){
    for (h = h; h != NULL; h = h->next)
    {
        printf(" %i", h->item);
    }
    printf("\n");
}

link sort(link h){
    return bubbleSort(h);
}

void destroyList(link h){
    while (h != NULL){
        link x = h;
        h = h->next;
        free(x);   
    }
}