#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct node* link;

struct node{
    Item item;
    link next;
};

link NEW(Item, link);
link init(int);
void show(link);
link sort(link);

#endif // LIST_H