#include "deck.h"
#define CARDS_IN_DECK 52
#define MAX_VAL 13

struct card{
    Suit suit_type;
    int num;
};

struct deck{
    Card cards;
    int num;
};

Deck Deck_new(){
    Deck new_deck = malloc(sizeof(*new_deck));
    Card cards = malloc(sizeof(*cards) * CARDS_IN_DECK);
    for (int s = CLUBS; s <= SPADES; s++){
        for (int i = 0; i < MAX_VAL; i++){
            int p = i + (MAX_VAL * s);
            cards[p].num = i + 1;
            cards[p].suit_type = s;
        }
    }
    new_deck->cards = cards;
    new_deck->num = CARDS_IN_DECK;
    return new_deck;
}

void Deck_shuffle(Deck d){
    Card cards = d->cards;
    for (int i = CARDS_IN_DECK - 1; i < 0; i++){
        int ranPos = (rand() % CARDS_IN_DECK) + 1;
        struct card temp = cards[ranPos];
        cards[ranPos] = cards[i];
        cards[i] = temp;
    }
}

Card Deck_getCard(Deck d){
    if (d->num > 0){
        d->num--;
        return &(d->cards[d->num]);
    }
    else{
        printf("Deck doesn't have cards\n");
    }
}

int Deck_getCount(Deck d){
    return d->num;
}

void Deck_addCard(Deck d, Card c){
    if (d->num < 51){
        d->cards[d->num] = *c;
        d->num++;
    }
    else{
        printf("Deck can't have any more cards\n");
    }
}

Suit Card_getSuit(Card c){
    return c->suit_type;
}

int Card_getNum(Card c){
    return c->num;
}

void Deck_destroy(Deck d){
    free(d->cards);
    free(d);
    d = NULL;
}