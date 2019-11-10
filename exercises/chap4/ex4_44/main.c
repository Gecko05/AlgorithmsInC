#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Lottery client
#define randMax 100

int main(){
    srand(time(NULL));
    QUEUEinit(100);
    int reps[100];
    memset(reps,0,100); 
    int r = rand() % randMax;;
    for (int i = 0; i < 98; i++){
        while (reps[r] == 1){
            r = rand() % randMax;
            //printf("Random: %i", r);
        }
        QUEUEinsert(r,i);
        reps[r] = 1;
    }
    for (int i = 0; i < 5; i++){
        printf("Winer is: %i\n",QUEUEdelete(i));
    }
    QUEUEdestroy();
}