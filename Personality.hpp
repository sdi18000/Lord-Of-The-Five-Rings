#pragma once
#include <iostream>
#include "Card.hpp"
#include <list>

#define maxGreenCards 3

class Personality:public BlackCard{
	protected:
		int isRevealed;
		int isDead;
		int attack;
		int defence;
		int honour;
		std::list<GreenCard*> gl;
		std::list<bool> b;
	public:
		Personality(std::string n,personality p);
		type getType();
		void equip(GreenCard* g,bool a);
		void print();
		int getHonour();
		bool canEquip();
		bool HonouredEnough(GreenCard *card);
};
