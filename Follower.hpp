#pragma once
#include <iostream>
#include "Card.hpp"

class Follower:public GreenCard{
	protected:
		std::string cardText;
		int isDead;
	public:
		Follower(std::string n,follower f);
		type getType();
		void print();
		void setalive();
		void setdead();
		int isdead();
		int isbroken();
		void reducedurability();
};
