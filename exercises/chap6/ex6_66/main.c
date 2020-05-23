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

link bubbleSort(link x){
    link h = x;
    link y = h;
    link p_y = h;
    int m = 1;
    if (x == NULL || x->next == NULL){
        return h;
    }
    while (m == 1){
        y = h;
        // Inner loop
        p_y = NULL;
        m = 0;
        while (y != NULL){
            if (y->next != NULL && y->next->item < y->item){
                // Exchange nodes
                link n_y = y->next->next;
                y->next->next = y;
                link t = y->next;
                y->next = n_y;
                // Check if we're moving a head node
                if (p_y == NULL){
                    h = t;
                }
                else{
                    p_y->next = t;
                }
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
        x->item = rand() % 10;
        link t = malloc(sizeof(t));
        t->next = NULL;
        x->next = t;
        x = t;
    }
    x = head;
    // Print the list
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
    x = head;
    // Sort
    x = head = bubbleSort(x);
    while(x != NULL){
        printf("%i ", x->item);
        x = x->next;
    }
    printf("\n");
}