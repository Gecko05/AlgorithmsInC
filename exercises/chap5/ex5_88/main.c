#include <stdlib.h>
#include <stdio.h>
#include "TREE.h"

#define N 10

// Function to compute the internal path length

int countNodes(link x, int l)
{
    if (x == NULL){
        // Node doesn't exist
        return 0;
    }
    if (x->l == NULL && x->r == NULL){
        // Node is external, no children
        return 0;
    }
    // Node is internal because it has children
    int u = countNodes(x->l, l+1);
    int v = countNodes(x->r, l+1);

    return l + u + v;
}

int main(int argc, char *argv[]){
    link root = newTree(N);
    int level = 0;
    int pathLen = countNodes(root, level);
    printf("Internal path Len: %i\n", pathLen);
    destroyTree(root);
}