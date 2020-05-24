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
            return NULL;
            //return t;
        }
        x = x->next;
    }
    return x;
}

link getPrevNode(link s, link x){
    link n = s;
    while (s != x && s != NULL){
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
            Item iy = 0;
            if (cy != NULL){
                iy = cy->item;
            }
            if (cy != NULL && iy < y->item){
                printf("Sorting with step %i\n", step);
                // Exchange nodes
                link p_y = getPrevNode(h, y);
                link p_cy = getPrevNode(h, cy);
                link w = y->next;

                p_y->next = cy;
                y->next = cy->next;
                if (p_cy != y){
                    p_cy->next = y;
                }
                if (cy != w){
                    cy->next = w;
                }
                else{
                    cy->next = y;
                }
                y = cy;
                // Set m to notify a movement was done
                m = 1;
            }
            else{
                // Just go through the list accoding the step
                p_y = y;
                y = getNextNode(y, step);
            }
        }
    }
    return h;
}

// Shellsort
// Still figuring out shell sort using bubble sort.
// This function works ultimately because bubbleSort(x, 1)
// properly sorts the list, which is not want we're looking for
// Need to add an inner loop to use the 4 step sort one time for
// each node on the list, need to figure this out/
// Maybe should add an offset to bubble sort.
link shellsort(link a, int l, int r)
{
    int i;
    int j;
    int h;
    link x;

    for (h = 1; h <= (r-l)/9; h = 3*h+1);

    for (h = h ; h > 0; h /= 3){
        a = bubbleSort(a, h);
        show(a);
    }
    return a;
}