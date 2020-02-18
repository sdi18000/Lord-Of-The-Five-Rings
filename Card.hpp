#pragma once
#include <iostream>
enum type{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};
enum personality{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION}; 
enum holding{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD}; 
enum follower{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum item{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};

class Card{
	protected:
		int cost;
		std::string name;
		int isTapped;
		type t;
	public:
		virtual type getType(void);
		Card(std::string n,type t,int c);
};



class GreenCard:public Card{
	public:
		GreenCard(std::string n,type t,int c);
};

class BlackCard:public Card{
	public:
		BlackCard(std::string n,type t,int c);
};

class Stronghold:public BlackCard{
	protected:
			int StartingHonour;
			int InitialDefence;
			int money;
	public:
		Stronghold(std::string n,holding h);
};