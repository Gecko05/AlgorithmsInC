#include <stdlib.h>
#include <stdio.h>
#include "DEQUE.h"
#include "TREE.h"

#define N 6
// Non recursive implementation of inorder traversal

void traverse(link h, void (*visit)(link))
{
    QUEUEinit();
    do
    {   
        while (h != NULL){
            if (h->r){
                QUEUEpush((void*)h->r);
            }
            QUEUEpush((void*)h);
            h = h->l;
        }
        h = QUEUEpop();
        link rc = QUEUEpop();
        if (h->r && h->r == rc){
            QUEUEpush((void*)h);
            h = h->r;
        }
        else{
            if (rc != NULL){
                QUEUEpush(rc);
            }
            (*visit)(h);
            h = NULL;
        }
    }while (QUEUEempty() == 0);
}

void printNode(link node)
{
    printf("Node: %i\n", node->item);
}

int main(int argc, char *argv[])
{
    link r1 = newTree(N);
    traverse(r1, printNode);
    printf("Done\n");
    QUEUEdestroy();
    destroyTree(r1);
}