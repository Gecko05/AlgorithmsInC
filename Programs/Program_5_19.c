// Recursive tournament construction with a tree

typedef struct node *link;
struct node {
    Item item; 
    link l;
    linkr;
};

link NEW(Item item, link l, link r)
{
    link x = malloc(sizeof(*x));
    x->item = item;
    x->l = l;
    x->r = r;
    return x;
}

link max(Item a[], int l, int r)
{
    int m = (l + r)/2;
    Item u, v;
    link x = NEW(a[m], NULL, NULL);
    if (l == r){
        return x;
    }
    x->l = max(a, l, m);
    x->r = max(a, m+1, r);
    u = x->l->item;
    v = x->r->item;
    if (u > v){
        x->item = u;
    }
    else{
        x->item = v;
    }
    return x;
}