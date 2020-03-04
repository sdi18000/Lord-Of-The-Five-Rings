#include "Card.hpp"
#include <iostream>
#include "Follower.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Item.hpp"
#include "Stronghold.hpp"
#include <ctime>

using namespace std;

Card::Card(string n,type t,int c){
	if(t==FOLLOWER){
		switch(c){
			case(0):
				
				cost=0;
				break;
			case(1):
				
				cost=0;
				break;
			case(2):
				
				cost=5;
				break;
			case(3):
				
				cost=3;
				break;
			case(4):
				
				cost=3;
				break;
			case(5):
				
				cost=8;
				break;	
		}
	}else if(t==ITEM){
		switch(c){
			case(0):
				
				cost=0;
				break;
			case(1):
				
				cost=0;
				break;
			case(2):
				
				cost=2;
				break;
			case(3):
				
				cost=4;
				break;
			case(4):
				
				cost=8;
				break;	
		}
	}else if(t==PERSONALITY){
		switch(c){
			case(0):
				
				cost=5;
				break;
			case(1):
				
				cost=5;
				break;
			case(2):
				
				cost=15;
				break;
			case(3):
				
				cost=15;
				break;
			case(4):
				
				cost=30;
				break;	
		}
	}else if(t==HOLDING){	
		switch(c){
			case(0):
				
				cost=2;
				break;
			case(1):
				
				cost=2;
				break;
			case(2):
				
				cost=3;
				break;
			case(3):
				
				cost=5;
				break;
			case(4):
				
				cost=7;
				break;
			case(5):
				
				cost=12;
				break;	
			case(6):
				
				cost=0;
		}
	}
	isTapped=0;
	name=n;
	cout << "card has a cost of " << cost << endl; 
}
		
GreenCard::GreenCard(string n,type t,int c):Card(n,t,c){
	upgraded = false;
}
	
	
BlackCard::BlackCard(string n,type t,int c):Card(n,t,c){
	isRevealed = 0;
}

void GreenCard::upgrade(){
	upgraded = true;
}

void Card::tap(){
	isTapped = 1;
}
		
void Card::untap(){
	isTapped = 0;
}

int Card::istapped(){
	if(isTapped==1) return 1;
	return 0;
}

int Card::getCost(){
	return cost;
}

int GreenCard::getbonusattack(){
	if(upgraded==true)  return(attackBonus+effectBonus);
	return(attackBonus);
}

int GreenCard::getbonusdefence(){
	if(upgraded==true)  return(defenceBonus+effectBonus);
	return(defenceBonus);
}		
		
int GreenCard::getEffectCost(){
	return effectCost;
}

int GreenCard ::getMinHonour(){
	return minimumHonour;
}

void Personality::setdead(){
	isDead=1;
}

void Personality::setalive(){
	isDead=0;
}

void BlackCard::reveal(){
	isRevealed = 1;
}

string Card::getName(){
	return name;
}

int BlackCard::isrevealed(){
	return isRevealed;
}