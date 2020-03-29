#include <stdlib.h>
#include <stdio.h>
#include "TREE.h"

#define N 6

// Function to count number of nodes which one external
// and one internal child

int countNodes(link x, int *n)
{
    if (x == NULL){
        // Node doesn't exist
        return 0;
    }
    if (x->l == NULL && x->r == NULL){
        // Node is external, no children
        return 1;
    }
    // Node is internal because it has children
    int u = countNodes(x->l, n);
    int v = countNodes(x->r, n);
    if (u + v == 3){
        *n = *n + 1;
    }
    return 2;
}

int main(int argc, char *argv[]){
    link root = newTree(N);
    int c = 0;
    (void)countNodes(root, &c);
    printf("Nodes with internal and external child: %i\n", c);
    destroyTree(root);
}