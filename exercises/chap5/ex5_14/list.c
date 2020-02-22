#include "Item.h"
#include "list.h"


typedef struct node *link;
struct node;

struct node{
    link next;
    Item item;
};

link head;

static void deleteNode(link x, link p){
    if (p && x){
        p->next = x->next;
        free(x);
    }
}

void deleteFinalElement(void *l, void *p){
    link x = ((link)l);
    if (x->next == NULL){
        return deleteNode(x, (link)p);
    }
    else{
        return deleteFinalElement((void *)x->next, l);
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