#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    struct node* next;
};

typedef struct node* link;

link head = NULL;

int deleteByLocationl(link head, int location){
    if (head == NULL)
    {
        return 0;
    }
    link current = head;
    //if location given is 1
    if (location == 1) //there is no issue except when location 1 is deleted
    {
        head = current->next;
        free(current);
        current = head;
        return 1;
    }
    //if anything below this actually runs, it will print just fine
    for (int i = 0; current != NULL && i < location-2; i++)
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
    {
        return 0;
    }
    link current2 = current->next;
    current->next = current2->next;
    free(current2);
    return 1;
}

int main()
{
    for(int i = 8; i >= 0; i--){
        link x = malloc(sizeof(*x));
        x->item = i;
        x->next = head;
        head = x;
    }
    deleteByLocationl(head, 1);
    link node = head;
    while(node){
        printf("item: %i ", node->item);
        node = node->next;
    }
    return 0;
}
