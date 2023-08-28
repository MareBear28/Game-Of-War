#include <iostream>
#include <vector>
#include "Card.h"
#ifndef CardPile_h
#define CardPile_h
using namespace std;

class CardPile
{
	protected:
		vector<Card> pile;
	public:
		void add(Card);
		void shuffle();
		Card remove();
		int cardsLeft();
		bool isEmpty();
};
#endif