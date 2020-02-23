#pragma once
#include <iostream>
#include "Card.hpp"

class Follower:public GreenCard{
	protected:
		std::string cardText;
	public:
		Follower(std::string n,follower f);
		type getType();
		void print();
};
