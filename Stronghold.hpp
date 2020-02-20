#pragma once
#include <iostream>
#include "Holding.hpp"

#define minHonour 3
#define maxHonour 6

class Stronghold:public Holding{
	protected:
		int StartingHonour;
		int InitialDefence;
	public:
		Stronghold(std::string n,holding h);
};