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
	holdingType = h;
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
		case(6):
		
		isRevealed=0;
		harvestValue=5;
		upperHolding=NULL;
		subHolding=NULL;
		break;
	}
		cout << "Made a " << name << endl;
}

type Follower::getType(){
	return FOLLOWER;
} 
type Item::getType(){
	return ITEM;
} 
type Personality::getType(){
	return PERSONALITY;
} 
type Holding::getType(){
	return HOLDING;
} 

int Holding::getHarvestValue(void){
	return harvestValue;
}

//holding chain
void Holding::connect(Holding* sh,Holding* uh){
	if(sh!=NULL){
		subHolding=sh;
		sh->upperHolding = this;
	}
	if(uh!=NULL){
		upperHolding=uh;
		uh->subHolding = this;
	}
	updateHarvest();
	if(subHolding != NULL) subHolding->updateHarvest();
	if(upperHolding != NULL) upperHolding->updateHarvest();
}

void Holding::updateHarvest(void){
	switch(holdingType){
		case(MINE):
			if(upperHolding != NULL){
				harvestValue += 2;
			}
			break;
		case(GOLD_MINE):
			if(subHolding != NULL && upperHolding != NULL){
				harvestValue += 2*harvestValue;
			}else if(subHolding != NULL){
				harvestValue += 4;
			}else{
				harvestValue += 5;
			}
			break;
		case(CRYSTAL_MINE):
			if(subHolding != NULL){
				if(subHolding->subHolding != NULL){
					harvestValue *= 3;
				}else{
					harvestValue *= 2;
				}
			}
			break;
	}
}

void Personality::equip(GreenCard* g,bool a){
			gl.push_back(g);
			b.push_back(a);
}

void Card::tap(){
	isTapped = 1;
}
		
void Card::untap(){
	isTapped = 0;
}
void Holding::print(){
	cout << "Holding: " << name << " with " << harvestValue << " harvest value and " << cost << " cost\n\n";
	if(holdingType==MINE){
		if(upperHolding!=NULL){
			cout << " and is connected with " << upperHolding->name << " with harvest value " << upperHolding->harvestValue << " and " << upperHolding->cost << "cost\n";
		}
	}else if(holdingType==GOLD_MINE){
		if(subHolding != NULL && upperHolding != NULL){
				cout << " and is connected with " << subHolding->name << " with harvest value " << subHolding->harvestValue << " and "<< subHolding->cost << " cost " << " and "<< upperHolding->name << " with harvest value " << upperHolding->harvestValue << " and "<< upperHolding->cost << " cost\n";              
		}else if(subHolding != NULL){
				cout << " and is connected with " << subHolding->name << " with harvest value " << subHolding->harvestValue << " and " << subHolding->cost << "cost\n";
		}else if(upperHolding != NULL){
				cout << " and is connected with " << upperHolding->name << " with harvest value " << upperHolding->harvestValue << " and " << upperHolding->cost << "cost\n";
		}
	}else if(holdingType==CRYSTAL_MINE){
		if(subHolding != NULL){
				cout << " and is connected with " << subHolding->name << " with harvest value " << subHolding->harvestValue << " and " << subHolding->cost << "cost\n";
		}
	}
}

void Personality::print(){
	cout << "Personality: " << name << " with " << attack << " attack, "<< defence << " defence, "<< honour << " honour and "<< cost << " cost\n";
	cout << "Its followers and items are: ";
	list <GreenCard*>::iterator it;
	if(gl.size()!=0){
		for(it=gl.begin();it!=gl.end();it++){
			(*it)->print();
		}
	}
	cout << endl << endl;
}

void Follower::print(){
	cout << "Follower: "<< name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost and " << cost << " cost\n\n";
}

void Item::print(){
	cout << "Item: " << name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost, " << durability << " durability and " << cost << " cost\n\n";
}


void BlackCard::reveal(){
	isRevealed = 1;
}

string Card::getName(){
	return name;
}