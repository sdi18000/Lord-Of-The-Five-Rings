#include "Card.hpp"
#include <iostream>
#include "Follower.hpp"

using namespace std;

Follower::Follower(string n,follower f):GreenCard(n,FOLLOWER,f){
	switch(f){
		case(0):
			isDead=0;
			attackBonus=2;
			defenceBonus=0;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
	
		case(1):
			isDead=0;
			attackBonus=0;
			defenceBonus=2;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
		
		case(2):
			isDead=0;
			attackBonus=3;
			defenceBonus=3;
			minimumHonour=2;
			effectBonus=2;
			effectCost=3;
			cardText="A card\n";
			break;
		
		case(3):
			isDead=0;
			attackBonus=4;
			defenceBonus=2;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(4):
			isDead=0;
			attackBonus=2;
			defenceBonus=4;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(5):
			isDead=0;
			attackBonus=8;
			defenceBonus=8;
			minimumHonour=6;
			effectBonus=3;
			effectCost=8;
			cardText="A card\n";
			break;
	}
	cout << "Made a " << name << endl;
}

type Follower::getType(){
	return FOLLOWER;
}

int Follower::isdead(){
	if(isDead==1) return 1;
	return 0;
}

void Follower::setdead(){
	isDead=1;
}

void Follower::setalive(){
	isDead=0;
}

void Follower::print(){
	if(upgraded == true){
		cout << "Upgraded ";
	}
	cout << "Follower: "<< name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "
	<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost and " 
	<< cost << " cost\n\n";
}

int Follower::isbroken(){
	return 0;
}
void Follower::reducedurability(){
	return;
}