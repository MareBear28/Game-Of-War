#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card()
{
    r = A;
    s = S;
}

Card::Card(value rank, suit su)
{
    r = value(rank);
    s = suit(su);
}

void Card::operator=(Card c) 
{
    r = c.r;
    s = c.s;
}

void Card::setCard(value rank, suit su)
{
    r = value(rank);
    s = suit(su);
}

int Card::getValue()
{
    int i;
    i = r;
    return i;
}

char Card::getSuit()
{
    switch (s)
    {
    case(S):
        return 'S';
    case(H):
        return 'H';
    case(D):
        return 'D';
    case(C):
        return 'C';
    }
}

void Card::showCard()
{
    char su = getSuit();
    if (this->r == J)
    {
        cout << 'J' << su;
    }
    else if (this->r == Q)
    {
        cout << 'Q' << su;
    }
    else if (this->r == K)
    {
        cout << 'K' << su;
    }
    else if (this->r == A)
    {
        cout << 'A' << su;
    }
    else
    {
        cout << this->r << su;
    }
}