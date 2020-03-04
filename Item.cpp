#include "Card.hpp"
#include <iostream>
#include "Item.hpp"

using namespace std;

Item::Item(string n,item i):GreenCard(n,ITEM,i){
	switch(i){
		case(0):
			
			attackBonus=2;
			defenceBonus=0;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			durability=3;
			cardText="A card\n";
			break;
		
		case(1):
			
			attackBonus=0;
			defenceBonus=2;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			durability=3;
			cardText="A card\n";
			break;
		
		case(2):
			
			attackBonus=2;
			defenceBonus=2;
			minimumHonour=2;
			effectBonus=3;
			effectCost=4;
			durability=5;
			cardText="A card\n";
			break;
		
		case(3):
			
			attackBonus=3;
			defenceBonus=3;
			minimumHonour=3;
			effectBonus=2;
			effectCost=2;
			durability=4;
			cardText="A card\n";
			break;
		
		case(4):
			
			attackBonus=5;
			defenceBonus=5;
			minimumHonour=3;
			effectBonus=3;
			effectCost=3;
			durability=8;
			cardText="A card\n";
			break;
	}
		cout << "Made a " << name << endl;	
}

type Item::getType(){
	return ITEM;
}

void Item::print(){
	if(upgraded == true){
		cout << "Upgraded ";
	}
	cout << "Item: " << name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "
	<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost, " 
	<< durability << " durability and " << cost << " cost\n\n";
}

void Item::reducedurability(){
	durability-=1;
}

int Item::isbroken(){
	if(durability==0) return 1;
	return 0;
}

int Item::isdead(){
	return 0;
}