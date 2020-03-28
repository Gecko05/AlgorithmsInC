#include "tree.h"

void destroyTree(link a)
{
    if (a == NULL){
        return;
    }
    destroyTree(a->l);
    destroyTree(a->r);
    free(a);
}

link newTree(int size)
{
    link f = malloc(sizeof(*f));
    f->item = 0;
    link root = f;
    for (int i = 1; i <= size; i++){
        link t = malloc(sizeof(*t));
        t->item = i;
        t->l = NULL;
        t->r = NULL;
        if (i % 2 == 0){
            f->l = t;
            f = f->r;
        }
        else{
            f->r = t;
        }
    }
    return root;
}