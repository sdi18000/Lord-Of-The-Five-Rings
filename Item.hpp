#pragma once
#include <iostream>
#include "Card.hpp"

class Item:public GreenCard{
	protected:
		int attackBonus;
		int defenceBonus;
		int minimumHonour;
		std::string cardText;
		int effectBonus;
		int effectCost;
		int durability;
	public:
		Item(std::string n,item i);
};
