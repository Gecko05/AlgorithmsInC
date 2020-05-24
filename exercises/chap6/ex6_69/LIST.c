#include "LIST.h"

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
    //return bubbleSort(h);
    return NULL;
}

void destroyList(link h){
    while (h != NULL){
        link x = h;
        h = h->next;
        free(x);   
    }
}

// Return the input link if the list doesn't have more elements ??
link getNextNode(link x, int step)
{
    link t = x;
    for (int i = 0; i < step; i++){
        if (x == NULL){
            return x;
            //return t;
        }
        x = x->next;
    }
    return x;
}

link getPrevNode(link s, link x){
    link n;
    while (s != x){
        n = s;
        s = s->next;
    }
    return n;
}

// Modified version of bubble sort to use in shellsort
link bubbleSort(link h, int step){
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
            link cy = getNextNode(y, step);
            Item iy = cy->item;
            if (cy != NULL && iy < y->item){
                // Exchange nodes
                link p_y = getPrevNode(h, y);
                link p_cy = getPrevNode(h, cy);
                p_y->next = cy;
                y->next = cy->next;
                p_cy->next = y;
                cy->next = y->next;
                y = cy;
                // Set m to notify a movement was done
                m = 1;
            }
            else{
                // Just go through the list accoding the step
                p_y = y;
                link w = y;
                y = getNextNode(y, step);
            }
        }
    }
    return h;
}