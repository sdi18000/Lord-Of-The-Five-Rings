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

int Player::getoverallattack(){
	int at=0;
	list<Personality*>::iterator it;
	for(it=attackarmy.begin();it!=attackarmy.end();it++){
		at+=(*it)->getattack();
	}
	return at;
}

int Player::getoveralldefence(){
	int def=0;
	list<Personality*>::iterator it;
	for(it=army.begin();it!=army.end();it++){
		if((*it)->istapped()==0)
			def+=(*it)->getdefence();
	}
	return def;
}

void Player::setenemy(Player* p){
	enemy=p;
}

void Player::setenemynum(int i){
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
 
int Player::attack(Player& p2){
	int target;
	string selection;
	bool finished=false;
	while(!finished){
		cout << "Please select the enemy province you want to attack:\n";
		p2.printProvinces();
		cin >> selection;
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
	if(getoverallattack()-p2.getoveralldefence()-5>5){
		int i=0;
		list<BlackCard*>::iterator it1;
		for(it1=(p2.provinces).begin();it1!=(p2.provinces).end();){
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
		for(it=(p2.army).begin();it!=(p2.army).end();){
			if((*it)->istapped()==0){
				delete *it;
				it = (p2.army).erase(it);
			}else{
				++it;
			}
		}
		attackarmy.clear();
	}else if(getoverallattack()-p2.getoveralldefence()>0){
		select(getoverallattack()-p2.getoveralldefence());
		list<Personality*>::iterator it;
		for(it = (p2.army).begin(); it != (p2.army).end();){
			if((*it)->istapped() == 0){
				delete *it;
				it = (p2.army).erase(it);
			}else{
				++it;
			}
		}
		reducearmyhonour();
		for(it=army.begin();it!=army.end();it++){
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
			(*it)->removebrokenitem();	
		}
		attackarmy.clear();
	}else if(getoverallattack()-p2.getoveralldefence()==0){
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
		
	}else{	
		p2.select2(p2.getoveralldefence()-getoverallattack());
		list<Personality*>::iterator it;
		for(it=army.begin();it!=army.end();){
			if((*it)->istapped()==0){
				delete *it;
				it = army.erase(it);
			}else{
				++it;
			}
		}
		p2.reducearmyhonour();
		attackarmy.clear();		
	}
}

void Player::select(int dif){
	cout << "Please select personalities/followers to lose with overall attack >= than " << dif << endl;
	cout << "[n] for nth personality, [n-m] for mth follower of nth personality" << endl;
	bool finished=false;
	int oa = 0;
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
					oa+=(*it)->getattack();
					continue;
				}
				vector <Follower*> copy=(*it)->getfollowers();
				vector <Follower*>::iterator it3;
				for(it3=copy.begin();it3!=copy.end();it3++){
					if((*it3)->isdead()==1){
						oa+=(*it3)->getbonusattack();
					}
				}
			}
			if(oa>=dif){
				finished=true;
				removedeadper();
				for(it2=army.begin();it2!=army.end();it2++){
					(*it2)->unequipdeadfol();
				}		
			}else{
				cout << "Not enough overall attack points,please select again from the beginning:\n";
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
			per.at(index)->setdead();
		}
	}
}

void Player::select2(int dif){
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

void Player::removedeadper(){
	list<Personality *>::iterator it;
	for(it = army.begin(); it != army.end();){
		if((*it)->isdead()==1){
			delete *it;
			it = army.erase(it);
		}else{
			++it;
		}
	}
}

int Player::tapHoldings(){
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
			cout << hold->getName() << " selected" << endl;
			cout << '(' << ++cards_selected << '/' << holdings.size() << ')' << endl; 
			hold->tap();
			income += hold->getHarvestValue();
		}
	}
	return income;
}

int Player::chooseProvince(int money){
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
					provinces.remove(prov);
					drawDynastyCard();
					TypeConverter *conv = new TypeConverter();
					Personality **per = new Personality *;
					Holding **hold = new Holding *;
					conv->getCorrectType(prov, per, hold);
					if(*per){
						army.push_back(*per);
					}else if(*hold){
						list<Holding *>::iterator h;
						for(h = holdings.begin(); h != holdings.end(); h++){
							(*hold)->connect(*h);
						}
						holdings.push_back(*hold);
					}
					delete(conv);
					delete(per);
					delete(hold);
					return prov->getCost();
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
void Player::discardSurplusFateCards(){
	if(hand.size() > maxCards){
		vector<GreenCard *> vect;
		list<GreenCard *>::iterator it;
		for (it = hand.begin(); it != hand.end(); it++)
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
			cout << selected_card->getName() << " will be discarded" << endl;
			hand.remove(selected_card);
			delete selected_card;
			finished = true;
		}
	}
}

int Player::getMoney(){
	return money;
}

void Player::reducearmyhonour(){
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

void Player::drawDynastyCard(){
	cout << "Drawing Dynasty Card" << endl << endl;
	provinces.push_back(deck->drawDynastyCard());
}