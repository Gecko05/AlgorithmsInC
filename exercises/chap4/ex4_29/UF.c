#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "UF.h"

typedef struct node{
    int item;
    int size;
}node;

node *tree;

void UFinit(int N)
{
    int i;
    tree = malloc(N*sizeof(node));
    for (i = 0; i < N; i++){
        tree[i].item = i;
        tree[i].size = 0;
    }
}

static int find(int x)
{
    int i = x;
    while (i != tree[i].item){
        tree[i] = tree[tree[i].item];
        i = tree[i].item;
        return i;
    }
}

int UFfind(int p, int q)
{
    return (find(p) == find(q));
}

void UFunion(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j){
        return;
    }
    if (tree[i].size < tree[j].size){
        tree[i].size = j;
        tree[j].size += tree[i].size;
    }
    else{
        tree[j].item = i;
        tree[i].size += tree[j].size;
    }
}

int UFfindAndUnion(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j){
        return 0;
    }
    if (tree[i].size < tree[j].size){
        tree[i].item = j;
        tree[j].size += tree[i].size;
    }
    else{
        tree[j].item = i;
        tree[i].size += tree[j].size;
    }
    return 1;
}

int getNodes(int node)
{
    int i = find(node);
    return tree[i].size - 1;
}