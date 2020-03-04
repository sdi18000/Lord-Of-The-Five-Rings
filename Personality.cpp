#include "Card.hpp"
#include <iostream>
#include "Personality.hpp"

using namespace std;

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

Personality::~Personality(){
	list<GreenCard *>::iterator it2;
	for (it2 = gl.begin(); it2 != gl.end(); it2++){
		delete *it2;
	}
	gl.clear();
}

type Personality::getType(){
	return PERSONALITY;
}

void Personality::equip(GreenCard* g,bool a){
	if(a == true) g->upgrade();
	gl.push_back(g);
}

bool Personality::canEquip(){
	if(gl.size() < 3) return true;
	return false;
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

void Personality::unequipdeadfol(){     //removes dead followers
	list<GreenCard*>::iterator it;		
	for(it=gl.begin();it!=gl.end();){		//search equipment	
		if((*it)->getType()==ITEM){		  //if it is an item then move on
			continue;
		}
		if((*it)->isdead()==1){				//and if it is a follower destroy it
			delete *it;
			it = gl.erase(it);
		}else{
			++it;
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
}

int Personality::getdefence(){
	int def=defence;
	list<GreenCard*>::iterator it;
	if(gl.empty()) return def;
	for(it=gl.begin();it!=gl.end();it++){
		def+=(*it)->getbonusdefence();
	}
	return def;
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

bool Personality::HonouredEnough(GreenCard *card){
	if(getHonour() >= card->getMinHonour()) return true;
	return false;
}

void Personality::print(){
	cout << "Personality: " << name << " with " << attack << " attack, "<< defence << " defence, "
	<< honour << " honour and "<< cost << " cost\n";
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

void Personality::removebrokenitem(){    //removes items with 0 durability
	list<GreenCard*>::iterator it;
	for(it=gl.begin();it!=gl.end();){   //search the equipment
		if((*it)->getType()==ITEM){     //if it is an ITEM
			if((*it)->isbroken()==1){		//and it is broken then destroy it
				delete *it;
				it = gl.erase(it);
			}else{
				++it;
			}
		}	
	}
}

void Personality::reducehonour(){
	honour--;
}
