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
void Holding::connect(Holding* hold){
	if(hold->upperHolding != NULL || hold->subHolding != NULL){
		return;
	}
	holding type = hold->holdingType;
	switch(holdingType){
		case(MINE):
			if(upperHolding == NULL && type == GOLD_MINE){
				upperHolding = hold;
				hold->subHolding = this;
			}
			break;
		case(GOLD_MINE):
			if(upperHolding == NULL && type == CRYSTAL_MINE){
				upperHolding = hold;
				hold->subHolding = this;
			}
			if(subHolding == NULL && type == MINE){
				subHolding = hold;
				hold->upperHolding = this;
			}
			break;
		case(CRYSTAL_MINE):
			if(subHolding == NULL && type == GOLD_MINE){
				subHolding = hold;
				hold->upperHolding = this;
			}
			break;
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
			}else if(upperHolding!=NULL){
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

void GreenCard::upgrade(){
	upgraded = true;
}

void Personality::equip(GreenCard* g,bool a){
	if(a == true) g->upgrade();
	gl.push_back(g);
}

bool Personality::canEquip(){
	if(gl.size() < 3) return true;
	return false;
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

int Personality::getHonour(){
	return honour;
}

vector<Follower*> Personality::getfollowers(){
	vector<Follower*> copy;
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==FOLLOWER){
			copy.push_back((Follower*)(*it));
		}
	}
	return copy;
}

vector<Item*> Personality::getitems(){
	vector<Item*> copy;
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==ITEM){
			copy.push_back((Item*)(*it));
		}
	}
	return copy;
}

void Personality::printfollowers(){
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==FOLLOWER){
			(*it)->print();
			if((*it)->isdead()==1){
				cout <<" (and follower already selected)\n";
			}
		}
	}
}

void Personality::printitems(){
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==ITEM){
			(*it)->print();
		}
	}
}

int Personality::isdead(){
	if(isDead==1) return 1;
	return 0;
}

int Follower::isdead(){
	if(isDead==1) return 1;
	return 0;
}

void Personality::setdead(){
	isDead=1;
}

void Personality::setalive(){
	isDead=0;
}

void Follower::setdead(){
	isDead=1;
}

void Follower::setalive(){
	isDead=0;
}

void Personality::unequipdeadfol(){
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==ITEM){
			continue;
		}
		if((*it)->isdead()==1){
			gl.remove((*it));
		}
	}
}

void Personality::undo(){
		if(isdead()==1){
			setalive();
			return;
		}
		vector <Follower*>copy=getfollowers();
		vector <Follower*>::iterator it3;
		for(it3=copy.begin();it3!=copy.end();it3++){
			if((*it3)->isdead()==1){
				(*it3)->setalive();
			}
		}
}


int Personality::getattack(){
	int at=attack;
	list<GreenCard*>::iterator it;
	if(gl.empty()) return at;
	for(it=gl.begin();it!=gl.end();it++){
		at+=(*it)->getbonusattack();
	}
	return at;


int Personality::getdefence(){
	int def=defence;
	list<GreenCard*>::iterator it;
	if(gl.empty()) return def;
	for(it=gl.begin();it!=gl.end();it++){
		def+=(*it)->getbonusdefence();
		}
	return def;
}





bool Personality::HonouredEnough(GreenCard *card){
	if(getHonour() >= card->getMinHonour()) return true;
	return false;
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
	cout << "Its followers and items are: \n";
	list <GreenCard*>::iterator it;
	if(gl.size()!=0){
		for(it=gl.begin();it!=gl.end();it++){
			(*it)->print();
		}
	}
	cout << endl << endl;
}

list<GreenCard*>& Personality::getgl(){
	return gl;
}

void Follower::print(){
	if(upgraded == true){
		cout << "Upgraded ";
	}
	cout << "Follower: "<< name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost and " << cost << " cost\n\n";
}

void Item::print(){
	if(upgraded == true){
		cout << "Upgraded ";
	}
	cout << "Item: " << name << " with " << attackBonus << " attackbonus, "<< defenceBonus << " defencebonus, "<< minimumHonour << " minimumHonour, \n" << effectBonus << " effectbonus, " << effectCost << " effectcost, " << durability << " durability and " << cost << " cost\n\n";
}


void BlackCard::reveal(){
	isRevealed = 1;
}

string Card::getName(){
	return name;
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

void Personality::removebrokenitem(){
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();it++){
		if((*it)->getType()==ITEM){
			if((*it)->isbroken()==1){
				gl.remove((*it));
			}
		}	
	}
}

int Follower::isbroken(){
	return 0;
}
void Follower::reducedurability(){
	return;
}

int Holding::isdead(){
	return 0;
}

void Personality::reducehonour(){
	honour--;
}

int BlackCard::isrevealed(){
	return isRevealed;
}