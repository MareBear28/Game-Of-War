#include <iostream>
#include <vector>
#include <iomanip>
#include "CardPile.h"
#include "Player.h"

using namespace std;

Player::Player() 
{
	battles = 0;
	won = 0;
	loss = false;
}

double Player::getFierce() 
{
	if (cardsLeft() == 0) 
	{
		return 0.0;
	}
	else 
	{
		double sum = 0;
		double n = pile.size();
		for (Card c : pile) 
		{
			sum += c.getValue();
		}
		return (sum / n);
	}
	
}

int Player::getBattles() 
{
	return battles;
}

int Player::getCards() 
{
	return cardsLeft();
}

int Player::getWins() 
{
	return won;
}

void Player::lost() 
{
	loss = true;
}

bool Player::getStatus() 
{
	return loss;
}
void Player::win() 
{
	this->won++;
}

void Player::played()
{
	this->battles++;
}

void Player::print() 
{
	cout << "Fierceness = " << getFierce();
	cout << "\t" << "Cards = " << getCards();
	cout << "\t" << "Battles = " << getBattles();
	cout << "\t" << "Won = " << getWins();
 }

void Player::showHand() 
{
	for (int i = 0; i < cardsLeft(); i++)
	{
		pile[i].showCard();
		cout << ",";
		if ((i + 1) % 13 == 0) {
			cout << endl;
		}
	}
}