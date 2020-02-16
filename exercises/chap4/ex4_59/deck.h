#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct deck *Deck;
typedef struct card *Card;

typedef enum suit{
    CLUBS,
    HEARTS,
    DIAMONDS,
    SPADES
}Suit;

Deck Deck_new();
void Deck_shuffle(Deck d);
Card Deck_getCard(Deck d);
void Deck_addCard(Deck d, Card c);
int Deck_getCount(Deck d);
void Deck_destroy(Deck d);

Suit Card_getSuit(Card c);
int Card_getNum(Card c);

#endif // DECK_H