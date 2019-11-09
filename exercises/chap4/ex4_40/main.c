#include "FIFO.h"
#include "stdio.h"
// General test for FIFO QUEUE

int main(){
    QUEUEinit(7);
    for (int i = 0; i < 5; i++){
        QUEUEput(i);
    }
    for (int i = 0; i < 5; i++){
        printf("Item is: %i\n",QUEUEget());
    }
    QUEUEget();
}