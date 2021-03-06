// Bubble sort for linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
typedef struct node *link;
struct node{
    link next;
    Item item;
};

link bubbleSort(link h){
    link y = h;
    link p_y = h;
    int m = 1;
    if (h == NULL || h->next == NULL || h->next->next == NULL){
        return h;
    }
    while (m == 1){
        y = h->next;
        // Inner loop
        p_y = h;
        m = 0;
        while (y != NULL){
            if (y->next != NULL && y->next->item < y->item){
                // Exchange nodes
                link n_y = y->next->next;
                y->next->next = y;
                link t = y->next;
                y->next = n_y;
                // Change the next of the previous node
                p_y->next = t;
                // Set p_y to previous node
                p_y = t;
                // Set m to notify a movement was done
                m = 1;
            }
            else{
                // Just go through the list
                p_y = y;
                y = y->next;
            }
        }
    }
    return h;
}

int main(int argc, char *argv[])
{
    time_t t;
    srand((unsigned) time(&t));
    // Initialize the unordered random list
    link head = malloc(sizeof(*head));
    head->next = NULL;
    link x = head;
    for (int i = 0; i < 10; i++){
        link t = malloc(sizeof(t));
        t->item = rand() % 10;
        t->next = NULL;
        x->next = t;
        x = t;
    }
    x = head->next;
    // Print the list
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
    // Sort
    head = bubbleSort(head);
    x = head->next;
    while(x != NULL){
        link t = x;
        printf("%i ", x->item);
        x = x->next;
        free(t);
    }
    printf("\n");
}