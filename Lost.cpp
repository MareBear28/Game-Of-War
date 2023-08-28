#include "Lost.h"
#include "Card.h"
#include "Player.h"
#include "CardPile.h"
#include <iostream>
#include <vector>

Lost::Lost() 
{
	l = 0;
}

void Lost::lostWinner(Player & p) 
{
	for (Card c : pile)
	{
		p.add(c);
	}
	this->pile.clear();
}