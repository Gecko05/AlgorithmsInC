#include "GRAPH.h"

static link NEW(int item, link next){
    link t = malloc(sizeof(*t));
    t->item = item;
    t->next = next;
    return t;
}

link *newGraph(int n){
    // Create array of pointers to lists
    link *graph = malloc(sizeof(*graph) * n);

    for (int i = 0; i < n; i++){
        link v = NEW(i, NULL);
        graph[i] = v;
        if (i == 0){
            link x = NEW(1, NULL);
            v->next = x;
        }
        else if (i == 1){
            link x = NEW(2, NULL);
            v->next = x;
        }
        for (int j = 0; j < n && i > 0; j++){
            link x = NEW(j, NULL);
            x->item = j;
            v->next = x;
            v = v->next;
        }
    }
    return graph;
}

void destroyList(link x){
    while (x != NULL){
        link t = x->next;
        free(x);
        x = t;
    }
}

void destroyGraph(link *g, int n){
    for (int i = 0; i < n; i++){
        destroyList(g[i]);
    }
    free(g);
}