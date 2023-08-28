#include "Card.h"
#include "CardPile.h"
#include <iostream>
#include <vector>
#ifndef Deck_h
#define Deck_h

class Deck: public CardPile
{
    public:
        Deck();
        void refreshDeck();
        void showDeck();
};
#endif