#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

// Graphs with adjacency lists representation

typedef struct node* link;

struct node{
    link next;
    int item;
};

link *newGraph(int n);

void destroyGraph(link *g, int n);

#endif // GRAPH_H