#include <iostream>
#include "Player.hpp"
#include <cstring>
#include "TypeConverter.hpp"

using namespace std;

Player::Player(string n,int i){
	deck = new DeckBuilder();
	deck->createFateDeck();
	deck->createDynastyDeck();

	deck->deckShuffler(deck->getFateDeck());
	deck->deckShuffler(deck->getDynastyDeck());

	Holding *stronghold = new Stronghold(n,STRONGHOLD,i);
	holdings.push_back(stronghold);

	numOfProvinces = 4;

	for (int i = 0; i < minCards; i++){
		hand.push_back((deck->getFateDeck())->front());
		deck->getFateDeck()->pop_front();
	}
	for (int i = 0; i < minCards; i++){
		provinces.push_back((deck->getDynastyDeck())->front());
		deck->getDynastyDeck()->pop_front();
	}
	enemynum=1000;
	enemy=NULL;
	money=5;
	
}

Player::~Player(){
	list<BlackCard *>::iterator it;
	for(it = provinces.begin(); it != provinces.end(); it++){
		delete *it;
	}
	provinces.clear();

	list<GreenCard *>::iterator it2;
	for(it2 = hand.begin(); it2 != hand.end(); it2++){
		delete *it2;
	}
	hand.clear();

	list<Personality*>::iterator it3;
	for(it3 = army.begin(); it3 != army.end(); it3++){
		delete *it3;
	}
	army.clear();

	for(it3 = attackarmy.begin(); it3 != attackarmy.end(); it3++){
		delete *it3;
	}
	attackarmy.clear();

	list<Holding *>::iterator it4;
	for(it4 = holdings.begin(); it4 != holdings.end(); it4++){
		delete *it4;
	}
	holdings.clear();

	delete(deck);
}

void Player::printstats(){
	cout << " has " << hand.size() << " cards in their hand, " << numOfProvinces << " provinces, " << holdings.size() <<" holdings, " <<  army.size()  << " soldiers and " << money << " gold\n"; 
}

void Player::untapEverything(){
	cout << "Untapping everything" << endl << endl;
	list<Holding *>::iterator it;
	for(it = holdings.begin(); it != holdings.end(); it++){
		(*it)->untap();
	}

	list<Personality *>::iterator it2;
	for(it2 = army.begin(); it2 != army.end(); it2++){
		(*it2)->untap();
	}
}

void Player::drawFateCard(){
	cout << "Drawing Fate Card" << endl << endl;
	hand.push_back(deck->drawFateCard());
}

void Player::revealProvinces(){
	cout << "Revealing Provinces" << endl << endl;
	list<BlackCard *>::iterator it;
	for(it = provinces.begin(); it != provinces.end(); it++){
		(*it)->reveal();
	}
}

void Player::printHand(){
	cout << "Your Hand:" << endl << endl;
	list<GreenCard*>::iterator it;
	if(hand.size()!=0){
		for(it=hand.begin();it!=hand.end();it++){
			(*it)->print();
		}
	}
}

void Player::printProvinces(){
	cout << "Your Provinces:" << endl << endl;
	list<BlackCard*>::iterator it;
	if(provinces.size()!=0){
		for(it=provinces.begin();it!=provinces.end();it++){
			if((*it)->isrevealed()) (*it)->print();
		}
	}
}

void Player::printArena(){
	cout << "Your Army:" << endl << endl;
	list<Personality*>::iterator it;
	if(army.size()!=0){
		for(it=army.begin();it!=army.end();it++){
			(*it)->print();
		}
	}
}

void Player::printHoldings(){
	cout << "Your Holdings:" << endl << endl;
	list<Holding*>::iterator it;
	if(holdings.size()!=0){
		for(it=holdings.begin();it!=holdings.end();it++){
			(*it)->print();
		}
	}
}

void Player::printMoney(){
	cout << "You have " << money << " gold" << endl;
}

void Player::printHonour(){
	cout << "You have " << getHonour() << " honour" << endl;
}

list<GreenCard *>& Player::getHand(){
	return hand;
}

list<Personality *>& Player::getArmy(){
	return army;
}

list<Personality *>& Player::getattackArmy(){
	return attackarmy;
}

int Player::getoverallattack(){            //gets attack from each personality in the army and adds it to tthe overall attack
	int at=0;
	list<Personality*>::iterator it;
	for(it=attackarmy.begin();it!=attackarmy.end();it++){
		at+=(*it)->getattack();
	}
	return at;
}

int Player::getoveralldefence(){				//gets defence from each personality in the army and adds it to the overall defence
	int def=0;
	list<Personality*>::iterator it;
	for(it=army.begin();it!=army.end();it++){
		if((*it)->istapped()==0)
			def+=(*it)->getdefence();
	}
	return def;
}

void Player::setenemy(Player* p){     //sets the enemy player
	enemy=p;
}

void Player::setenemynum(int i){		//sets the number of the enemy (used for printing basically)
	enemynum=i;
}

Player* Player::getenemy(){
	return enemy;
}

int Player::getenemynum(){
	return enemynum;
}

int Player::getnumofprov(){
	return numOfProvinces;
}
 
int Player::attack(Player& p2){     //function which implements the attack of one player to player p2
	int target;
	string selection;
	bool finished=false;
	while(!finished){
		cout << "Please select the enemy province you want to attack:\n";
		p2.printProvinces();
		cin >> selection;    //selection of province
		try{
			target = stoi(selection)-1;	
			if(target+1<=0 || target+1>p2.getnumofprov()){
				cout << "Invalid input,try again\n";
				continue;
			}
		}catch(out_of_range e){
			cout << "Invalid input, try again" << endl;
			continue;
		}catch(invalid_argument){
			cout << "Invalid input, try again" << endl;
			continue;
		}
		finished=true;
	}
	if(getoverallattack()-p2.getoveralldefence()-5>5){   //if the attacker wins the battle
		int i=0;
		list<BlackCard*>::iterator it1;    
		for(it1=(p2.provinces).begin();it1!=(p2.provinces).end();){    // remove p2's selected province
			if(target==i){
				delete *it1;
				it1 = (p2.provinces).erase(it1);
				break;
				
			}else{
				++it1;
			}
			i++;
		}
		(p2.numOfProvinces)--;
		list<Personality*>::iterator it;
		for(it=(p2.army).begin();it!=(p2.army).end();){      //destroy p2's army
			if((*it)->istapped()==0){
				delete *it;
				it = (p2.army).erase(it);
			}else{
				++it;
			}
		}
		attackarmy.clear();
	}else if(getoverallattack()-p2.getoveralldefence()>0){   //if  the attacker survives
		select(getoverallattack()-p2.getoveralldefence());    //the attacker chooses which units he wants to lose
		list<Personality*>::iterator it;
		for(it = (p2.army).begin(); it != (p2.army).end();){     //destroy p2's army
			if((*it)->istapped() == 0){
				delete *it;
				it = (p2.army).erase(it);
			}else{
				++it;
			}
		}
		reducearmyhonour();    					//reduce the honour of the surviving units of the attacker's army and destroy those with 0 honour
		for(it=army.begin();it!=army.end();it++){     //and also tap followers used and reduce the durability of the items by 1
			if((*it)->istapped()==1){
				list <GreenCard*>& copy=(*it)->getgl();
				list <GreenCard*>::iterator it3;
				for(it3=copy.begin();it3!=copy.end();it3++){
					if((*it3)->getType()==FOLLOWER){
						(*it3)->tap();
					}
					if((*it3)->getType()==ITEM){
						(*it3)->reducedurability();
					}	
				}
			}
			(*it)->removebrokenitem();	  //remove items with 0 durability
		}
		attackarmy.clear();
	}else if(getoverallattack()-p2.getoveralldefence()==0){   //if it is a draw the destroy the attackers attack army and the defenders defence army
		list<Personality*>::iterator it;
		for(it=(p2.army).begin();it!=(p2.army).end();){   
			if((*it)->istapped()==0){
				delete *it;
				it = p2.army.erase(it);
			}else{
				++it;
			}
		}
		for(it=army.begin();it!=army.end();){
			if((*it)->istapped()==1){
				delete *it;
				it = army.erase(it);
			}else{
				++it;
			}
		}
		attackarmy.clear();
		(p2.attackarmy).clear();
		
	}else{														//else p2 survives and
		p2.select2(p2.getoveralldefence()-getoverallattack());    //p2 must select units to lose
		list<Personality*>::iterator it;
		for(it=army.begin();it!=army.end();){    //destroy the attacker's army
			if((*it)->istapped()==0){
				delete *it;
				it = army.erase(it);
			}else{
				++it;
			}
		}
		p2.reducearmyhonour();  //reduce the honour of p2's surviving units
		attackarmy.clear();		
	}
}

void Player::select(int dif){     //the function that lets the atacker select which units to lose
	cout << "Please select personalities/followers to lose with overall attack >= than " << dif << endl;
	cout << "[n] for nth personality, [n-m] for mth follower of nth personality" << endl;
	bool finished=false;
	int oa = 0;
	list<Personality*>::iterator it2;
	vector<Personality*> per;					//we use a vector in order to make use of the vectors functions
	for(it2=army.begin();it2!=army.end();it2++){
		per.push_back(*(it2));
	}
	string selection;
	while(!finished){
		if(army.empty()){						//if the army is empty then there is nothing to be done here
			cout << "You have no army" << endl;
			finished = true;
			continue;
		}
		cout << "Your available options are:\n";  	//print available options
		for(it2=army.begin();it2!=army.end();it2++){
			(*it2)->print();
			if((*it2)->isdead()==1)
				cout << "(personality already selected)\n";
			continue;
		}
		cin >> selection;
		if(selection=="DONE" || selection=="done"){            //if the attacker is done   
			vector <Personality*>::iterator it;    
			for(it=per.begin();it!=per.end();it++){     //then calculate overall attack of sacrificed units
				if((*it)->isdead()==1){          //by adding sacrificed personalities' attack
					oa+=(*it)->getattack();
					continue;
				}
				vector <Follower*> copy=(*it)->getfollowers();   //and sacrificed followers' attack
				vector <Follower*>::iterator it3;
				for(it3=copy.begin();it3!=copy.end();it3++){
					if((*it3)->isdead()==1){
						oa+=(*it3)->getbonusattack();
					}
				}
			}
			if(oa>=dif){               //if overall attack points are enough then
				finished=true;
				removedeadper();		//remove the dead personalities from the army
				for(it2=army.begin();it2!=army.end();it2++){  //and also remove dead followers
					(*it2)->unequipdeadfol();
				}		
			}else{                              //else  undo the changes and select again which units to lose
				cout << "Not enough overall attack points,please select again from the beginning:\n";
				vector <Personality*>::iterator it;
				for(it=per.begin();it!=per.end();it++){
					(*it)->undo();
				}
				continue;
			}
		}else if(selection.length()>1){                        		//this is the case for selecting a follower of a personality
			int i,j;
			try{
				i=stoi(selection.substr(0, selection.find("-")))-1;
				j=stoi(selection.substr(selection.find("-")+1))-1;
				try{
					per.at(i);
					((per.at(i))->getfollowers()).at(j);
				}
				catch(out_of_range){
					cout << "Invalid input, try again" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			if(per.at(i)->getfollowers().at(j)->isdead()==1){
				cout << "Invalid follower, already selected, please select another one" << endl;
				continue;
			}
			per.at(i)->getfollowers().at(j)->setdead();         //if everything is ok then set that follower as dead
		}else{	                     //case for selecting a personality 
			int index;
			try{
				index =stoi(selection)-1;	
				try{
					per.at(index);
				}
				catch(out_of_range){
					cout << "Invalid input, try again" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			if(per.at(index)->isdead()==1){
				cout << "Invalid personality, already selected, please select another one" << endl;
				continue;
			}
			per.at(index)->setdead();  //if everything is ok then set that personality as dead
		}
	}
}

void Player::select2(int dif){   //same as select but it is used when the defender survives,thus calculating overall defence
	cout << "Please select personalities/followers to lose with overall defence >= than " << dif << endl;
	cout << "[n] for nth personality, [n-m] for mth follower of nth personality" << endl;
	bool finished=false;
	int od = 0;
	list<Personality*>::iterator it2;
	vector<Personality*> per;
	for(it2=army.begin();it2!=army.end();it2++){
		per.push_back(*(it2));
	}
	string selection;
	while(!finished){
		if(army.empty()){
			cout << "You have no army" << endl;
			finished = true;
			continue;
		}
		cout << "Your available options are:\n";
		for(it2=army.begin();it2!=army.end();it2++){
			(*it2)->print();
			if((*it2)->isdead()==1)
				cout << "(personality already selected)\n";
			continue;
		}
		cin >> selection;
		if(selection=="DONE" || selection=="done"){
			vector <Personality*>::iterator it;
			for(it=per.begin();it!=per.end();it++){
				if((*it)->isdead()==1){
					od+=(*it)->getdefence();
					continue;
				}
				vector <Follower*> copy=(*it)->getfollowers();
				vector <Follower*>::iterator it3;
				for(it3=copy.begin();it3!=copy.end();it3++){
					if((*it3)->isdead()==1){
						od+=(*it3)->getbonusdefence();
					}
				}
			}
			if(od>=dif){
				finished=true;
				removedeadper();
				for(it2=army.begin();it2!=army.end();it2++){
					(*it2)->unequipdeadfol();
				}		
			}else{
				cout << "Not enough overall defence points, please select again from the beginning:\n";
				vector <Personality*>::iterator it;
				for(it=per.begin();it!=per.end();it++){
					(*it)->undo();
				}
				continue;
			}
		}else if(selection.length()>1){
			int i,j;
			try{	
				i=stoi(selection.substr(0, selection.find("-")))-1;
				j=stoi(selection.substr(selection.find("-")+1))-1;
				try{
					per.at(i);
					((per.at(i))->getfollowers()).at(j);	
				}
				catch(out_of_range){
					cout << "Invalid input, try again" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			if(per.at(i)->getfollowers().at(j)->isdead()==1){
				cout << "Invalid follower, already selected, please select another one" << endl;
				continue;
			}
			per.at(i)->getfollowers().at(j)->setdead();
		}else{
			int index;
			try{
				index = stoi(selection)-1;	
				try{
					per.at(index);
				}
				catch(out_of_range){
					cout << "Invalid input, try again" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			if(per.at(index)->isdead()==1){
				cout << "Invalid personality, already selected, please select another one" << endl;
				continue;
			}
			per.at(index)->setdead();
		}
	}
}

void Player::pay(int amount){
	money -= amount;
}

bool Player::affords(Card *c){
	if(money >= c->getCost()) return true;
	return false;
}

bool Player::affords(int cost){
	if(money >= cost) return true;
	return false;
}

void Player::buy(Card *c){
	pay(c->getCost());
}

void Player::receive(int amount){
	money += amount;
}

int Player::getHonour(){
	return getStronghold()->getHonour();
}

Stronghold *Player::getStronghold(){
	Stronghold *str = (Stronghold *)(holdings.front());
	return str;
}

void Player::print(){
	cout << "Player with Stronghold: " << getStronghold()->getName() << endl;
}

void Player::removeFromHand(GreenCard *card){
	hand.remove(card);
}

void Player::removedeadper(){    //removes dead personalities
	list<Personality *>::iterator it;
	for(it = army.begin(); it != army.end();){   //search the army for dead personalities
		if((*it)->isdead()==1){   //and if they are dead ,destroy them
			delete *it;
			it = army.erase(it);
		}else{
			++it;
		}
	}
}

int Player::tapHoldings(){    //function that taps holdings
	vector<Holding *> vect;
	list<Holding *>::iterator it;
	for (it = holdings.begin(); it != holdings.end(); it++)
		vect.push_back((*it));
	bool finished = false;
	cout << "Choose cards to tap, 'done' to stop:" << endl;
	printHoldings();
	string selection;
	int income = 0;
	int cards_selected = 0;
	while(!finished){
		cin >> selection;
		if(selection == "done" || selection == "Done"){
			finished = true;
		}else{
			Holding *hold;
			try{
				int index = stoi(selection)-1;
				try{
					hold = vect.at(index);
				}catch(out_of_range e){
					cout << "Choose a valid card" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument e){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			if(hold->istapped()==1){
				cout << hold->getName() << " is already tapped" << endl;
				continue;
			}
			cout << hold->getName() << " selected" << endl;       //if everything is ok then inform theplayer about the choice he made and add harvest value to his income
			cout << '(' << ++cards_selected << '/' << holdings.size() << ')' << endl; 
			hold->tap();
			income += hold->getHarvestValue();
		}
	}
	return income;
}

int Player::chooseProvince(int money){        			//function that gives the ability to a player to choose provinces
	vector<BlackCard *> vect;
	list<BlackCard *>::iterator it;
	for (it = provinces.begin(); it != provinces.end(); it++)
		vect.push_back((*it));
	bool finished = false;
	while(!finished){
		cout << "Select Province or 'cancel':" << endl;
		printProvinces();
		string selection;
		cin >> selection;
		if(selection == "Cancel" || selection == "cancel"){
			finished = true;
		}else{
			try{
				int index = stoi(selection)-1;
				try{
					BlackCard *prov = vect.at(index);    
					if(prov->isrevealed() == 0){   
						cout << "Province is hidden, please select another one" << endl;
						continue;
					}
					if(prov->getCost() > money){
						cout << "Can't afford " << prov->getName() << endl;
						continue;
					}
					provinces.remove(prov);     					//if everything is ok  remove the prvince and replace it with a hidden one
					drawDynastyCard();                           
					TypeConverter *conv = new TypeConverter();
					Personality **per = new Personality *;
					Holding **hold = new Holding *;
					conv->getCorrectType(prov, per, hold);
					if(*per){
						army.push_back(*per);         //if it is a personality add it to the army
					}else if(*hold){                     
						list<Holding *>::iterator h;
						for(h = holdings.begin(); h != holdings.end(); h++){		//else add it to the holdings and try connecting it
							(*hold)->connect(*h);
						}
						holdings.push_back(*hold);
					}
					delete(conv);
					delete(per);
					delete(hold);
					return prov->getCost();				//return the cost of the purchased province
				}catch(out_of_range e){
					cout << "Choose a valid card" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument e){
				cout << "Invalid input, try again" << endl;
				continue;
			}
		}
	}
	return 0;
}
void Player::discardSurplusFateCards(){  			//function that lets a player discard surplus cards
	if(hand.size() > maxCards){				//if player has more cards then discard a card
		vector<GreenCard *> vect;
		list<GreenCard *>::iterator it;
		for (it = hand.begin(); it != hand.end(); it++)			//we use the array because it is more practical
			vect.push_back((*it));
		bool finished = false;
		string selection;
		while(!finished){
			printHand();
			int refund = 0;
			cout << "Choose card to discard" << endl;
			cin >> selection;
			GreenCard *selected_card;
			try{
				int index = stoi(selection)-1;
				try{
					selected_card = vect.at(index);
				}catch(out_of_range e){
					cout << "Choose a valid card" << endl;
					continue;
				}
			}catch(out_of_range e){
				cout << "Invalid input, try again" << endl;
				continue;
			}catch(invalid_argument){
				cout << "Invalid input, try again" << endl;
				continue;
			}
			cout << selected_card->getName() << " will be discarded" << endl;  //if everything is ok then remove that card
			hand.remove(selected_card);
			delete selected_card;
			finished = true;
		}
	}
}

int Player::getMoney(){
	return money;
}
  
void Player::reducearmyhonour(){    //reduces syrviving units' honour and destroys them if their honour is 0
	list <Personality*>::iterator it;
	for(it=army.begin();it!=army.end();){
		(*it)->reducehonour();
		if((*it)->getHonour()==0){
			delete *it;
			it = army.erase(it);
		}else{
			++it;
		}
	}
}

void Player::drawDynastyCard(){                  //function that fills an empty province
	cout << "Drawing Dynasty Card" << endl << endl;
	provinces.push_back(deck->drawDynastyCard());
}
