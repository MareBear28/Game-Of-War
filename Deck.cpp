#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
    //char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
   // char suits[4] = {'S', 'H', 'D', 'C'};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Card c(Card::value(j + 1), Card::suit(i));
            add(c);
            //deck[num].setCard(ranks[j], suits[i]);
        }
    }
}

void Deck::refreshDeck()
{
    //char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
   // char suits[4] = {'S', 'H', 'D', 'C'};
    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            pile[num].setCard(Card::value(j + 1), Card::suit(i));
            num++;
        }
    }
}

void Deck::showDeck()
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