#include "Card.hpp"
#include <iostream>
#include "Follower.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Item.hpp"

using namespace std;

Card::Card(string n,int c){
			name=n;
			cost=c;
			isTapped=0;
}
		
GreenCard::GreenCard(string n, cardType t, int c):Card(n,c){
}
	
	
BlackCard::BlackCard(string n, cardType t, int c):Card(n,c){
}

Follower::Follower(string n,follower f){
	switch(f){
		case(0):
			GreenCard(n, FOLLOWER, 0);
			attackBonus=2;
			defenceBonus=0;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
	
		case(1):
			GreenCard(n, FOLLOWER, 0);
			attackBonus=0;
			defenceBonus=2;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
		
		case(2):
			GreenCard(n, FOLLOWER, 5);
			attackBonus=3;
			defenceBonus=3;
			minimumHonour=2;
			effectBonus=2;
			effectCost=3;
			cardText="A card\n";
			break;
		
		case(3):
			GreenCard(n, FOLLOWER, 3);
			attackBonus=4;
			defenceBonus=2;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(4):
			GreenCard(n, FOLLOWER, 3);
			attackBonus=2;
			defenceBonus=4;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(5):
			GreenCard(n, FOLLOWER, 8);
			attackBonus=8;
			defenceBonus=8;
			minimumHonour=6;
			effectBonus=3;
			effectCost=8;
			cardText="A card\n";
			break;
	}
		cout << "Made a" << name << endl;
}

Item::Item(string n,item i){
	switch(i){
		case(0):
			GreenCard(n, ITEM, 0);
			attackBonus=2;
			defenceBonus=0;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			durability=3;
			cardText="A card\n";
			break;
		
		case(1):
			GreenCard(n, ITEM, 0);
			attackBonus=0;
			defenceBonus=2;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			durability=3;
			cardText="A card\n";
			break;
		
		case(2):
			GreenCard(n, ITEM, 2);
			attackBonus=2;
			defenceBonus=2;
			minimumHonour=2;
			effectBonus=3;
			effectCost=4;
			durability=5;
			cardText="A card\n";
			break;
		
		case(3):
			GreenCard(n, ITEM, 4);
			attackBonus=3;
			defenceBonus=3;
			minimumHonour=3;
			effectBonus=2;
			effectCost=2;
			durability=4;
			cardText="A card\n";
			break;
		
		case(4):
			GreenCard(n, ITEM, 8);
			attackBonus=5;
			defenceBonus=5;
			minimumHonour=3;
			effectBonus=3;
			effectCost=3;
			durability=8;
			cardText="A card\n";
			break;
	}
		cout << "Made a" << name << endl;	
}

Personality::Personality(string n,personality p){
	switch(p){
		case(0):
			BlackCard(n, PERSONALITY, 5);
			isRevealed=0;
			isDead=0;
			attack=3;
			defence=2;
			honour=2;
			break;
		
		case(1):
			BlackCard(n, PERSONALITY, 5);
			isRevealed=0;
			isDead=0;
			attack=2;
			defence=3;
			honour=2;
			break;
		
		case(2):
			BlackCard(n, PERSONALITY, 15);
			isRevealed=0;
			isDead=0;
			attack=10;
			defence=5;
			honour=8;
			break;
		
		case(3):
			BlackCard(n, PERSONALITY, 15);
			isRevealed=0;
			isDead=0;
			attack=5;
			defence=10;
			honour=8;
			break;
		
		case(4):
			BlackCard(n, PERSONALITY, 30);
			isRevealed=0;
			isDead=0;
			attack=20;
			defence=20;
			honour=12;
			break;
	}
		cout << "Made a" << name << endl;
		
}

Holding::Holding(string n,holding h){
	switch(h){
		case(0):
			BlackCard(n, HOLDING, 2);
			isRevealed=0;
			harvestValue=2;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(1):
			BlackCard(n, HOLDING, 2);
			isRevealed=0;switch(f){
			harvestValue=2;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(2):
			BlackCard(n, HOLDING, 3);
			isRevealed=0;
			harvestValue=4;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(3):
			BlackCard(n, HOLDING, 5);
			isRevealed=0;
			harvestValue=3;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(4):
			BlackCard(n, HOLDING, 7);
			isRevealed=0;
			harvestValue=5;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(5):
			BlackCard(n, HOLDING, 12);
			isRevealed=0;
			harvestValue=6;
			upperHolding=NULL;
			subHolding=NULL;
			break;
	}
		cout << "Made a" << name << endl;
}

Stronghold::Stronghold(string n,holding h){
	if(h==0){
		BlackCard(n, HOLDING, 0);
		StartingHonour=5;
		InitialDefense=5;
		money=5;
	}
}
