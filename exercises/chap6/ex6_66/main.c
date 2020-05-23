// Bubble sort for linked list
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct node *link;
struct node{
    link next;
    Item item;
};

link bubbleSort(link x){
    link h = x;
    link y = h;
    link p_y = h;
    int m = 1;
    while (m == 1){
        y = h;
        // Inner loop
        p_y = NULL;
        m = 0;
        while (y != NULL){
            if (y->next != NULL && y->next->item < y->item){
                link n_y = y->next->next;
                y->next->next = y;
                link t = y->next;
                y->next = n_y;
                if (p_y == NULL){
                    h = t;
                }
                else{
                    p_y->next = t;
                }
                p_y = y;
                m = 1;
            }
            else{
                p_y = y;
                y = y->next;
            }
        }
    }
    return h;
}

int main(int argc, char *argv[])
{
    // Create the unordered list
    link head = malloc(sizeof(*head));
    head->next = NULL;
    link x = head;
    for (int i = 0; i < 10; i++){
        x->item = rand() % 10;
        link t = malloc(sizeof(t));
        t->next = NULL;
        x->next = t;
        x = t;
    }
    x = head;
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
    x = head;
    x = head = bubbleSort(x);
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
}