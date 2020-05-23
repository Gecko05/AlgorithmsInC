// List insertion sort
#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node{
    int item;
    link next;
};

struct node heada;
struct node headb;
link u;
link x;
link a = &heada;
link b;

link insertion_list(link h)
{
    link b = malloc(sizeof(*b));
    link a = h;
    link t;
    link x;
    link u;
    b->next = NULL;

    for (t = a->next; t != NULL; t = u){
        // Still figuring out why this works instead of t = t->next
        u = t->next;
        for (x = b; x->next != NULL; x = x->next){
            if (x->next->item > t->item){
                break;
            }
        }
        t->next = x->next;
        x->next = t;
    }
    return b;
}

int main(){
    link t;
    int N = 8;
    int i;
    link head_a = malloc(sizeof(*head_a));

    for (i = 0, t = head_a; i < N; i++){
        t->next = malloc(sizeof(*t));
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
    }

    link x = head_a;
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
    head_a = insertion_list(head_a);
    x = head_a;
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
}