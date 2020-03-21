#include <stdlib.h>
#include <stdio.h>

#define ITEM 2

typedef struct node* link;
struct node{
    int item;
    link r;
    link l;
};

int eq(link node)
{
    return node->item == ITEM;
}

int recursiveDeleteLeaf(link node){
    // Nothing to do here
    if (node == NULL){
        return 0;
    }
    // It's a leaf equal to the item
    if (node->l == NULL && node->r == NULL && eq(node)){
        return 1;
    }
    if (node->l != NULL && recursiveDeleteLeaf(node->l) == 1){
        node->l == NULL;
    }
    if (node->r != NULL && recursiveDeleteLeaf(node->r) == 1){
        node->r == NULL;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    link x = malloc(sizeof(*x));
    recursiveDeleteLeaf(x);
}