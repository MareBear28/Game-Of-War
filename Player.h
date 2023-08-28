#include <iostream>
#include <vector>
#include <iomanip>
#include "CardPile.h"
#ifndef Player_h
#define Player_h
using namespace std;

class Player: public CardPile
{
private:
	int battles;
	int won;
	bool loss;
public:
	Player();
	double getFierce();
	int getBattles();
	int getCards();
	int getWins();
	void win();
	void lost();
	bool getStatus();
	void played();
	void print();
	void showHand();
};
#endif