#include "Item.h"
#include "list.h"

int main(int argc, char *argv[]){
    void *list = buildList();
    printList(list);
    deleteFinalElement(list, NULL);
    printList(list);
    deleteFinalElement(list, NULL);
    printList(list);
    return 0;
}