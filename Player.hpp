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
	int enemynum;
	Player* enemy;
	DeckBuilder *deck;
	std::list<BlackCard *> provinces;
	std::list<GreenCard *> hand;
	std::list<Personality*> army;
	std::list<Holding *> holdings;
	std::list<Personality*> attackarmy;
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
	std::list<GreenCard *>& getHand();
	std::list<Personality *>& getArmy();
	std::list<Personality *>& getattackArmy();
	int getoverallattack();
	int getoveralldefence();
	void setenemy(Player* p);
	void setenemynum(int i);
	Player* getenemy();
	int getenemynum();
	void pay(int amount);
	bool affords(Card *c);
	bool affords(int cost);
	void buy(Card *c);
	void receive(int amount);
	int getHonour();
	Stronghold *getStronghold();
	void removeFromHand(GreenCard *card);
	int attack(Player& p2);
	int getnumofprov();
	void removedeadper();
	void select(int i);
	int chooseProvince(int money);
	int tapHoldings();
	void discardSurplusFateCards();
	int getMoney();
	void reducearmyhonour();
	void performSeppuku(Personality*);
	void drawDynastyCard();
};
