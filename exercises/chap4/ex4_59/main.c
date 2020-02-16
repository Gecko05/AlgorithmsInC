#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

int main(){
    Deck myDeck = Deck_new();
    int c = Deck_getCount(myDeck);
    Card myCard;
    for (int i = 0; i < c; i++){
        myCard = Deck_getCard(myDeck);
        printf("Card num %i suite %i\n", Card_getNum(myCard), Card_getSuit(myCard));
    }
    Deck_destroy(myDeck);
}