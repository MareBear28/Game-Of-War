#include "Card.h"
#include "CardPile.h"
#include <iostream>
#include <vector>
#ifndef MegaDeck_h
#define MegaDeck_h

class MegaDeck: public CardPile
{
	public:
		MegaDeck(int);
		void refresh();
		void showDeck();
	private:
		int decks;
};
#endif
