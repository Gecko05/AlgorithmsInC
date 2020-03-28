#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct node* link;

struct node{
    link l;
    link r;
    int item;
};

void destroyTree(link a);

#endif // TREE_H