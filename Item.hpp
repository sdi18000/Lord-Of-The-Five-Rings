#pragma once
#include <iostream>
#include "Card.hpp"

class Item:public GreenCard{
	protected:
		std::string cardText;
		int durability;
	public:
		Item(std::string n,item i);
		type getType();
		void print();
};
