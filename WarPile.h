#include "Card.h"
#include "Player.h"
#include "CardPile.h"
#include "Lost.h"
#include <iostream>
#include <vector>
#ifndef WarPile_h
#define WarPile_h

class WarPile: public CardPile
{
	public:
		WarPile();
		void warWinner(Player &);
		int warPlay(Player &);
		void transferLost(Lost &);
	private:
		int c;
};
#endif
