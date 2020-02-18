#include "Card.hpp"
#include <iostream>
#include "Follower.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Item.hpp"

using namespace std;

Card::Card(string n,type t,int c){
	this->t = t;
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

type Card::getType(void){
	return t;
}
		
GreenCard::GreenCard(string n,type t,int c):Card(n,t,c){
}
	
	
BlackCard::BlackCard(string n,type t,int c):Card(n,t,c){
	
}

Follower::Follower(string n,follower f):GreenCard(n,FOLLOWER,f){
	switch(f){
		case(0):
			
			attackBonus=2;
			defenceBonus=0;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
	
		case(1):
	
			attackBonus=0;
			defenceBonus=2;
			minimumHonour=1;
			effectBonus=1;
			effectCost=2;
			cardText="A card\n";
			break;
		
		case(2):
			
			attackBonus=3;
			defenceBonus=3;
			minimumHonour=2;
			effectBonus=2;
			effectCost=3;
			cardText="A card\n";
			break;
		
		case(3):
			
			attackBonus=4;
			defenceBonus=2;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(4):
		
			attackBonus=2;
			defenceBonus=4;
			minimumHonour=3;
			effectBonus=3;
			effectCost=4;
			cardText="A card\n";
			break;
		
		case(5):
			
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

Personality::Personality(string n,personality p):BlackCard(n,PERSONALITY,p){
	switch(p){
		case(0):
			
			isRevealed=0;
			isDead=0;
			attack=3;
			defence=2;
			honour=2;
			break;
		
		case(1):
			
			isRevealed=0;
			isDead=0;
			attack=2;
			defence=3;
			honour=2;
			break;
		
		case(2):
			
			isRevealed=0;
			isDead=0;
			attack=10;
			defence=5;
			honour=8;
			break;
		
		case(3):
			
			isRevealed=0;
			isDead=0;
			attack=5;
			defence=10;
			honour=8;
			break;
		
		case(4):
			
			isRevealed=0;
			isDead=0;
			attack=20;
			defence=20;
			honour=12;
			break;
	}
		cout << "Made a " << name << endl;
		
}

Holding::Holding(string n,holding h):BlackCard(n,HOLDING,h){
	switch(h){
		case(0):
			
			isRevealed=0;
			harvestValue=2;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(1):
			
			isRevealed=0;
			harvestValue=2;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(2):
			
			isRevealed=0;
			harvestValue=4;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(3):
			
			isRevealed=0;
			harvestValue=3;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(4):
			
			isRevealed=0;
			harvestValue=5;
			upperHolding=NULL;
			subHolding=NULL;
			break;
		
		case(5):
			
			isRevealed=0;
			harvestValue=6;
			upperHolding=NULL;
			subHolding=NULL;
			break;
	}
		cout << "Made a " << name << endl;
}

Stronghold::Stronghold(string n,holding h):BlackCard(n,HOLDING,h){
		StartingHonour=5;
		InitialDefence=5;
		money=5;
}
