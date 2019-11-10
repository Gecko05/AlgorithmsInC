#include "FIFO.h"
#include "stdio.h"
// General test for QUEUE

int main(){
    QUEUEinit(7);
    for (int i = 0; i < 5; i++){
        QUEUEinsert(i,i);
    }
    for (int i = 0; i < 5; i++){
        printf("Item is: %i\n",QUEUEdelete(i));
    }
    QUEUEdelete(5);
}