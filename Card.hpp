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
	public:
		Card(std::string n,type t,int c);
		virtual type getType() =0;
		virtual void print() =0;
		void tap();
		void untap();
		std::string getName();
		int getCost();
		int istapped();
		
};

class GreenCard:public Card{
	protected:
		int attackBonus;
		int defenceBonus;
		int effectBonus;
		int effectCost;
		int minimumHonour;
		bool upgraded;
	public:
		GreenCard(std::string n,type t,int c);
		void upgrade();
		int getEffectCost();
		int getMinHonour();
		int getbonusattack();
		int getbonusdefence();
		virtual int isdead()=0;
		virtual int isbroken()=0;
		virtual void reducedurability()=0;		
};

class BlackCard:public Card{
	protected:
		int isRevealed;
	public:
		BlackCard(std::string n,type t,int c);
		virtual void reveal(void);
		virtual int isdead()=0;
		int isrevealed();	
};