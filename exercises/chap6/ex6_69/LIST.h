#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Item.h"

typedef struct node* link;

struct node{
    Item item;
    link next;
};

link NEW(Item item, link next);
link init(int N);
void show(link h);
link sort(link h);
void destroyList(link h);

// Sorting algorithms

// Use step 1 and start 0 for standard bubble sort
link bubbleSort(link h, int step, int start);

link shellsort(link a, int l, int r);

#endif // LIST_H