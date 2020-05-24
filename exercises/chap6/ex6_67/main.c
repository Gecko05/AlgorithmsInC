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

link insertion_list(link a)
{
    link b = malloc(sizeof(*b));
    link t;
    link x;
    link u;
    b->next = NULL;

    for (t = a->next; t != NULL; t = u){
        // Securing the next node in the first list before line 35
        u = t->next;
        // Iterate on the second list to find the end node
        for (x = b; x->next != NULL; x = x->next){
            // Break the loop if we found a place
            // to insert a smaller node than the next
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