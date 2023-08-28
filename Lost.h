#include "Card.h"
#include "Player.h"
#include "CardPile.h"
#include <iostream>
#include <vector>
#ifndef Lost_h
#define Lost_h
class Lost : public CardPile
{
	public:
		Lost();
		void lostWinner(Player &);
	private:
		int l;
};
#endif
