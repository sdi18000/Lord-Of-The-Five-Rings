#pragma once
#include <iostream>
#include "Holding.hpp"



class Stronghold:public Holding{
	protected:
		int StartingHonour;
		int InitialDefence;
	public:
		Stronghold(std::string n,holding h,int i);
		int getHonour();
};
