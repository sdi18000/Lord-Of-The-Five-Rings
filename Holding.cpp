#include "Card.hpp"
#include <iostream>
#include "Holding.hpp"

using namespace std;

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

type Holding::getType(){
	return HOLDING;
} 

int Holding::getHarvestValue(void){
	return harvestValue;
}

//holding chain
void Holding::connect(Holding* hold){
	holding type = hold->holdingType;
	bool updated = false;
	switch(holdingType){
		case(MINE):
			if(upperHolding == NULL && type == GOLD_MINE && hold->subHolding == NULL){
				upperHolding = hold;
				hold->subHolding = this;
				updated = true;
			}
			break;
		case(GOLD_MINE):
			if(upperHolding == NULL && type == CRYSTAL_MINE && hold->subHolding == NULL){
				upperHolding = hold;
				hold->subHolding = this;
				updated = true;
			}
			if(subHolding == NULL && type == MINE && hold->upperHolding == NULL){
				subHolding = hold;
				hold->upperHolding = this;
				updated = true;
			}
			break;
		case(CRYSTAL_MINE):
			if(subHolding == NULL && type == GOLD_MINE && hold->upperHolding == NULL){
				subHolding = hold;
				hold->upperHolding = this;
				updated = true;
			}
			break;
		default:
			return;
	}
	if(updated){
		updateHarvest();
		hold->updateHarvest();
	}
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
				harvestValue = 4+2*4;
			}else if(subHolding != NULL){
				harvestValue += 4;
			}else if(upperHolding!=NULL){
				harvestValue += 5;
			}
			break;
		case(CRYSTAL_MINE):
			if(subHolding != NULL){
				if(subHolding->subHolding != NULL){
					harvestValue = 3*3;
				}else{
					harvestValue = 2*3;
				}
			}
			break;
	}
}

void Holding::print(){
	cout << "Holding: " << name << " with " << harvestValue << " harvest value and " << cost << " cost\n\n";
	if(holdingType==MINE){
		if(upperHolding!=NULL){
			cout << " and is connected with " << upperHolding->name << " with harvest value " 
			<< upperHolding->harvestValue << " and " << upperHolding->cost << " cost\n\n";
		}
	}else if(holdingType==GOLD_MINE){
		if(subHolding != NULL && upperHolding != NULL){
			cout << " and is connected with " << subHolding->name << " with harvest value " 
			<< subHolding->harvestValue << " and "<< subHolding->cost << " cost " << " and "
			<< upperHolding->name << " with harvest value " << upperHolding->harvestValue << " and "
			<< upperHolding->cost << " cost\n\n";              
		}else if(subHolding != NULL){
			cout << " and is connected with " << subHolding->name << " with harvest value " 
			<< subHolding->harvestValue << " and " << subHolding->cost << " cost\n\n";
		}else if(upperHolding != NULL){
			cout << " and is connected with " << upperHolding->name << " with harvest value " 
			<< upperHolding->harvestValue << " and " << upperHolding->cost << " cost\n\n";
		}
	}else if(holdingType==CRYSTAL_MINE){
		if(subHolding != NULL){
			cout << " and is connected with " << subHolding->name << " with harvest value " 
			<< subHolding->harvestValue << " and " << subHolding->cost << " cost\n\n";
		}
	}
}

int Holding::isdead(){
	return 0;
}