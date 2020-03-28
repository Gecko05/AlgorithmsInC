#include <stdlib.h>
#include <stdio.h>
#include "DEQUE.h"
#include "TREE.h"

#define N 6
// Non recursive implementation of inorder traversal

void traverse(link h, void (*visit)(link))
{
    QUEUEinit();
    while (h != NULL || QUEUEempty() == 0)
    {   
        while (h != NULL){
            QUEUEpush((void*)h);
            h = h->l;
        }
        (*visit)(h = (link)QUEUEget());
        h = h->r;
    }
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