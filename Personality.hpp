#pragma once
#include <iostream>
#include "Card.hpp"

class Personality:public BlackCard{
	protected:
		int isRevealed;
		int isDead;
		int attack;
		int defence;
		int honour;
	public:
		Personality(std::string n,personality p);
};
