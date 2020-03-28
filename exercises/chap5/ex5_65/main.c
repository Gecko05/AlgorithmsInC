#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node{
    int item;
    link r;
    link l;
};

int getLeftItem(link x){
    if (x->l){
        return x->l->item;
    }
    else{
        return -1;
    }
}

int getRightItem(link x){
    if (x->r){
        return x->r->item;
    }
    else{
        return -1;
    }
}

int areIsomorphic(link a, link b)
{
    if (a == NULL && b == NULL){
        return 1;
    }
    else if (a == NULL || b == NULL)
    {
        printf("One is empty\n");
        return 0;
    }
    int t = 0;
    int x = 0;
    if (getLeftItem(a) == getLeftItem(b))
    {
        t = areIsomorphic(a->l, b->l);
    }
    else if(getLeftItem(a) == getRightItem(b))
    {
        t = areIsomorphic(a->l, b->r);
    }
    if (getRightItem(a) == getRightItem(b))
    {
        x = areIsomorphic(a->r, b->r);
    }
    else if(getRightItem(a) == getLeftItem(b))
    {
        x = areIsomorphic(a->r, b->l);
    }
    if (a->item == b->item && x == 1 && t == 1){
        printf("a:%i b:%i l:%i r:%i\n", a->item, b->item, t, x);
        return 1;
    }
    else{
        printf("Not isomorphic\n");
        printf("a:%i b:%i l:%i r:%i\n\n", a->item, b->item, t, x);
        return 0;
    }
}

void destroyTree(link a){
    if (a == NULL){
        return;
    }
    destroyTree(a->l);
    destroyTree(a->r);
    free(a);
}

int main(int argc, char *argv[])
{
    link f = malloc(sizeof(*f));
    link g = malloc(sizeof(*g));
    f->item = 0;
    g->item = 0;
    link r1 = f;
    link r2 = g;
    for (int i = 1; i <= 6; i++){
        link t = malloc(sizeof(*t));
        link v = malloc(sizeof(*v));
        t->item = v->item = i;
        t->l = v->l = NULL;
        t->r = v->r = NULL;
        if (i % 2 == 0){
            f->l = t;
            f = f->r;
            g->r = v;
            g = g->l;
        }
        else{
            f->r = t;
            g->l = v;
        }

    }
    int res = areIsomorphic(r1, r2);
    printf("The result is: %i\n", res);
    destroyTree(r1);
    destroyTree(r2);
}