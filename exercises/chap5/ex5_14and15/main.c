#include "Item.h"
#include "list.h"

int main(int argc, char *argv[]){
    void *list = buildList();
    printList(list);
    deleteFinalElement(list);
    printList(list);
    reverseList(list);
    list = g;
    printList(list);
    deleteFinalElement(list);
    printList(list);
    deleteFinalElement(list);
    printList(list);
    return 0;
}