#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Poker client
#define randMax 38
char cards[39];

void fillCards(){
    int c = 0;
    // Spades
    for (int i = 1; i < 14; i ++){
        cards[c] = i;
        c = c + 1;
    }
    // Hearts
    for (int i = 21; i < 34; i ++){
        cards[c] = i;
        c = c + 1;
    }
    // Diamonds
    for (int i = 41; i < 54; i ++){
        cards[c] = i;
        c = c + 1;
    }
    // Clubs
    for (int i = 61; i < 74; i ++){
        cards[c] = i;
        c = c + 1;
    }
}

void pickHand(){
    for (int i = 0; i < 5; i++){
       int r = rand()%randMax;
       QUEUEinsert(cards[r], i);
    }
}

void printHand(){
    printf("Hand:");
    for (int i = 0; i < 5; i++){
        int card = QUEUEdelete(i);
        printf(" %i", card);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Invalid number of arguments\n");
        return -1;
    }
    fillCards();
    srand(time(NULL));
    QUEUEinit(4);
    char *num = argv[1];
    int n = atoi(num);
    for (int i = 0; i < n; i++){
        pickHand();
        printHand();
    }
    QUEUEdestroy();
}