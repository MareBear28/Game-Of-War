#include <iostream>
#ifndef Card_h
#define Card_h
class Card
{

public:
    enum suit { S, H, D, C };
    enum value { A = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, T, J, Q, K };
    Card();
    Card(value, suit);
    void operator=(Card);
    void setCard(value, suit);
    int getValue();
    char getSuit();
    void showCard();
private:
    suit s; //suit
    value r; //ran
};
#endif