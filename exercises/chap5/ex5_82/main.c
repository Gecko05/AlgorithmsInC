#include <stdlib.h>
#include <stdio.h>
#include "DEQUE.h"

#define N 10
// Non recursive implementation of inorder traversal

typedef struct node* link;

struct node{
    link l;
    link r;
    int item;
};

void traverse(link h, void (*visit)(link))
{
    QUEUEinit();
    QUEUEpush((void*)h);
    while (!QUEUEempty())
    {   
        if (h->l != NULL) QUEUEpush((void*)h->l);
        (*visit)(h = (link)QUEUEpop());
        if (h->r != NULL) QUEUEpush((void*)h->r);
    }
}

void printNode(link node)
{
    printf("Node: %i\n", node->item);
}

int main(int argc, char *argv[])
{
    link f = malloc(sizeof(*f));
    f->item = 0;
    link r1 = f;
    for (int i = 1; i <= 6; i++){
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
    traverse(r1, printNode);
    QUEUEdestroy();
}