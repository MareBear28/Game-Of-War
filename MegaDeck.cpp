#include "MegaDeck.h"
#include "Card.h"
#include "CardPile.h"
#include <iostream>
#include <vector>
using namespace std;

MegaDeck::MegaDeck(int n) 
{
    decks = n;
    for (int x = 0; x < n; x++) 
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                Card c(Card::value(j + 1), Card::suit(i));
                add(c);
            }
        }
    }
}

void MegaDeck::refresh() 
{   int num = 0;
    for (int x = 0; x < decks; x++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                pile[num].setCard(Card::value(j + 1), Card::suit(i));
                num++;
            }
        }
    }
}

void MegaDeck::showDeck()
{
    for (int i = 0; i < 52; i++)
    {
        pile[i].showCard();
        cout << ",";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }

}
