#include <iostream>
#include <vector>
#include "Card.h"
#include "CardPile.h"
using namespace std;

void CardPile::add(Card c) 
{
	pile.push_back(c);
}

void CardPile::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < 1207; i++)
    {
        int y = rand() % 52;
        int z = rand() % 52;

        Card temp = pile[y];
        pile[y] = pile[z];
        pile[z] = temp;
    }
}

Card CardPile::remove() 
{
    Card c = pile[pile.size() - 1];
    pile.pop_back();
    return c;
}


int CardPile::cardsLeft() 
{
    return pile.size();
}

bool CardPile::isEmpty() 
{
    return pile.empty();
}