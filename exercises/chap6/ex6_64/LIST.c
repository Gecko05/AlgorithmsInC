// Linked-list-type interface definition
#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
typedef int Item;

struct node{
    Item item;
    link next;
};

link NEW(Item item, link next){
    link t = malloc(sizeof(*t));
    t->item = item;
    t->next = next;
    return t;
}

link init(int n){
    int a;
    int b;
    link h = NEW(0, sizeof(*h));
    h->next = NULL;
    link l = h;
    do{
        b = scanf("%i\n",&a);
        link x = NEW(a, NULL);
        l->next = x;
        l = x;
    } while(b != EOF);
    return h;
}

void show(link h){
    link x = h->next;
    while (x != NULL){
        printf("%i ",x->item);
        x = x->next;
    }
    printf("\n");
}

link findmax(link h){
    if (h == NULL){
        return NULL;
    }
    int maxi = h->item;
    link x = h->next;
    link maxLink = h;
    while (x != NULL){
        if (x->item > maxi){
            maxi = x->item;
            maxLink = x;
        }
        x = x->next;
    }
    return maxLink;
}

link sort(link h){
    link max, t, out = NULL;
    while (h->next != NULL)
    {
        max = findmax(h);
        t = max->next;
        max->next = t->next;
        t->next = out;
        out = t;
    }
    h->next = out;
    return h;
}