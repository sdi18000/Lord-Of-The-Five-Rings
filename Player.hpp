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
	std::list<Personality*> army;
	std::list<Holding *> holdings;
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
	void printMoney();
	void printHonour();
	std::list<GreenCard *> getHand();
	std::list<Personality *> getArmy();
	void pay(int amount);
	bool affords(Card *c);
	bool affords(int cost);
	void buy(Card *c);
	void receive(int amount);
	int getHonour();
	Stronghold *getStronghold();
	void removeFromHand(GreenCard *card);
};