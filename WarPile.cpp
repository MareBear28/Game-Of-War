#include "WarPile.h"
#include "Card.h"
#include "Player.h"
#include "CardPile.h"
#include "Lost.h"
#include <iostream>
#include <vector>

WarPile::WarPile() 
{
	c = 0;
}

void WarPile::warWinner(Player & p) 
{
	for (Card c : pile) 
	{
		p.add(c);
	}
	this->pile.clear();
}

int WarPile::warPlay(Player & p)
{
	Card c;
	p.played();
	for (int i = 0; i < 4; i++) 
	{
		if (p.isEmpty()) 
		{
			p.lost();
			return 0;
		}
		else 
		{
			c = p.remove();
			this->add(c);
		}
	}
	return c.getValue();
}

void WarPile::transferLost(Lost & l)
{
	for (Card c : this->pile)
	{
		l.add(c);
	}
	this->pile.clear();
}