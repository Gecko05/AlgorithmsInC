#include "Item.h"
#include "list.h"


typedef struct node *link;
struct node;

struct node{
    link next;
    Item item;
};

link head;
void *g;

void *reverseList(void *l){
    link x = (link)l;
    if (x->next == NULL){
        g = l;
        return x;
    }
    else{
        link n = reverseList(x->next);
        n->next = x;
        x->next = NULL;
        return x;
    }
}

void *deleteFinalElement(void *l){
    link x = ((link)l);
    void *p;
    if (x->next == NULL){
        free(x);
        return NULL;
    }
    else{
        p = deleteFinalElement((void *)x->next);
        x->next = p;
        return l;
    }
}

void *buildList(){
    head = NULL;
    for (int i = 0;i < 5; i++){
        link x = malloc(sizeof(*x));
        x->next = head;
        x->item = i;
        head = x;
    }
    return (void *)head;
}

void printList(void *l){
    if (l == NULL){
        return;
    }
    else{
        printf("item: %i\n", ((link)l)->item);
        return printList((void*)((link)l)->next);
    }
}