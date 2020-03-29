#include <stdlib.h>
#include <stdio.h>
#include "TREE.h"

#define N 6

int countLeaves(link x)
{
    if (x == NULL){
        return 0;
    }
    if (x->l == NULL && x->r == NULL){
        return 1;
    }
    int n = countLeaves(x->l);
    n += countLeaves(x->r);
    return n;
}

int main(int argc, char *argv[]){
    link root = newTree(N);
    int c = countLeaves(root);
    printf("Leaves in binary tree: %i\n", c);
}