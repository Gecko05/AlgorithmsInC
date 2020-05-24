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
link bubbleSort(link h, int step);

#endif // LIST_H