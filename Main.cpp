// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#include "Player.h"
#include "Deck.h"
#include "CardPile.h"
#include "MegaDeck.h"
#include "WarPile.h"
#include "Lost.h"

bool checkWinner(vector<Player> p) 
{
	int s = p.size();
	int counter = 0;
	for (Player i : p) 
	{
		if (i.cardsLeft() == 0) 
		{
			counter++;
		}
	}
	if (counter == (s - 1)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int findWinner(vector<Player> p) 
{
	int index = 0;
	for (Player i : p)
	{
		if (i.cardsLeft() != 0)
		{
			return index;
		}
		index++;
	}
}

void printStats(int battle,vector<Player> p) 
{
	cout << "Battle " << battle << " Stats:" << endl; 
	int i = 1;
	for (Player x : p) 
	{
		cout << "\tPlayer " << i << ": ";
		x.print();
		cout << endl;
		i++;
	}
	cout << endl;

}

template <typename T = Deck>
void MegaWar(T D, vector<Player> p) 
{
	int s = D.cardsLeft();
	int num_p = p.size();
	int cardPer = s / num_p;
	int counter = 0;
	for(int i = 0; i < num_p; i++)
	{
		for (int j = 0 + counter; j < cardPer + counter; j++) 
		{
			p[i].add(D.remove());
		}
		counter += cardPer;
	}

	WarPile wp;
	Lost lp;
	vector<int> index;
	int battle = 0;
	while (!checkWinner(p))
	{
		int max = 0;
		int i = 0;
		battle++;
		for (Player & m : p)
		{
			if (m.isEmpty())
			{
				m.lost();
				i++;
				continue;
			}
			else if (!m.getStatus())
			{
				m.played();
				Card c = m.remove();
				int value = c.getValue();
				wp.add(c);
				if (value > max) 
				{
					index.clear();
					index.push_back(i);
					max = value;
				}
				else if (value == max) 
				{
					index.push_back(i);
				}
			}
			i++;
		}
		if (index.size() == 1) 
		{
			wp.warWinner(p[index[0]]);
			if (!lp.isEmpty())
			{
				lp.lostWinner(p[index[0]]);
			}
			p[index[0]].win();
			printStats(battle, p);
		}
		else 
		{
			bool winner = false;
			vector<int> war;
			int s = p.size();
			while (!winner) 
			{
				battle++;
				int loss = 0;
				int max = 0;
				for (int x: index) 
				{
					int y = wp.warPlay(p[x]);
					p[x].played();
					if (y == 0) 
					{
						loss++;
						p[x].lost();
					}
					else if (y > max) 
					{
						max = y;
						war.clear();
						war.push_back(x);
					}
				}
				if (loss == index.size()) 
				{
					wp.transferLost(lp);
					winner = true;
					printStats(battle, p);
				}
				else if (war.size() == 1) 
				{
					winner = true;
					wp.warWinner(p[war[0]]);
					p[war[0]].win();
					if (!lp.isEmpty()) 
					{
						lp.lostWinner(p[war[0]]);
					}
					printStats(battle, p);
				}
				else 
				{
					index = war;
				}
			}
		}
		index.clear();
	}
	int i = findWinner(p);
	cout << "========Mega War========"<< endl ; 
	cout << "Winner is Player " << i + 1 << "!" << endl;
}

int main()
{
	cout << "========Mega War========" << endl;

	cout << "How many players will be playing?\n";
	int numP;
	cin >> numP;
	cout << endl;
	cout << "How many decks would you like to play with? \n";
	int numD;
	cin >> numD;
	cout << endl;

	vector <Player> p(numP);
	if (numD > 1) 
	{
		MegaDeck D(numD);
		D.shuffle();
		MegaWar(D, p);
	}
	else 
	{
		Deck D;
		D.shuffle();
		MegaWar(D, p);
	}

}

