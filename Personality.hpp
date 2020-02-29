#pragma once
#include <iostream>
#include "Card.hpp"
#include <list>
#include "Follower.hpp"
#include "Item.hpp"
#include <vector>

#define maxGreenCards 3

class Personality:public BlackCard{
	protected:
		int isRevealed;
		int isDead;
		int attack;
		int defence;
		int honour;
		std::list<GreenCard*> gl;
	public:
		Personality(std::string n,personality p);
		type getType();
		void equip(GreenCard* g,bool a);
		void print();
		int getHonour();
		bool canEquip();
		bool HonouredEnough(GreenCard *card);
		int getattack();
		int getdefence();
		std::vector<Follower*> getfollowers();
		std::vector<Item*> getitems();
		void setdead();
		void setalive();
		void printfollowers();
		void printitems();
		int isdead();
		void unequipdeadfol();
		void undo();
		std::list<GreenCard*>& getgl();
		void removebrokenitem();
		void reducehonour();
};
