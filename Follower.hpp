#pragma once
#include <iostream>
#include "Card.hpp"

class Follower:public GreenCard{
	protected:
		int attackBonus;
		int defenceBonus;
		int minimumHonour;
		std::string cardText;
		int effectBonus;
		int effectCost;
	public:
		Follower(std::string n,follower f);
		type getType();
		void print();
};
