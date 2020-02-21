#pragma once
#include <list>
#include "Card.hpp"
#include "Holding.hpp"
#include "Stronghold.hpp"
#include "Personality.hpp"
#include "DeckBuilder.hpp"
#include <string>

#define maxCards 6
#define minCards 4

class Player{
protected:
	DeckBuilder *deck;
	std::list<BlackCard *> provinces;
	std::list<GreenCard *> hand;
	std::list<Holding *> holdings;
	std::list<Personality*> army;
	int numOfProvinces;
	int money;
public:
	Player(std::string n,int i);
	void printstats();
	void untapEverything();
	void drawFateCard();
	void revealProvinces();
	void printHand();
	void printProvinces();
	void printArena();
	void printHoldings();
};
