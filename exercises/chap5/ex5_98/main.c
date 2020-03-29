#include <stdlib.h>
#include <stdio.h>
#include "DEQUE.h"
#include "GRAPH.h"

#define N 10

// Implementation of a stack-based depth-first search for graphs
// represented by adjacency lists

int *initVisit(int n){
    int *a = malloc(sizeof(*a) * n);
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    return a;
}

void printNode(int x){
    printf("%i  ", x);
}

// Push unvisited nodes to the stack
void pushUnvisited(link x, int *v){
    while (x != NULL){
        if (v[x->item] == 0){
            QUEUEpush(x->item);
        }
        x = x->next;
    }
}

void depthFirstSearch(link *g, int n, void (*visit)(int)){
    QUEUEinit();
    int *visited = initVisit(n);
    link t = g[0];
    pushUnvisited(t->next, visited);
    (*visit)(0);
    visited[0] = 1;
    QUEUEprint();
    while (!QUEUEempty()){
        int a = QUEUEpop();
        if (visited[a] == 0){
            (*visit)(a);
            visited[a] = 1;
            link x = g[a];
            pushUnvisited(x->next, visited);
        }
        QUEUEprint();
    }
    free(visited);
}


int main(int argc, char *argv[]){
    link *G = newGraph(N);
    depthFirstSearch(G, N, printNode);
    printf("Done\n");
    destroyGraph(G, N);
}