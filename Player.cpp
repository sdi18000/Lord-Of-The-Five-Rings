#include <iostream>
#include "Player.hpp"
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
	money=5;
	
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

void Player::drawDynastyCard(){
	cout << "Drawing Dynasty Card" << endl << endl;
	provinces.push_back(deck->drawDynastyCard());
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
			if((*it)->revealed()){
				(*it)->print();
			}
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
			if((*it)->tapped()) cout << "[Tapped]" << endl << endl;
		}
	}
}

void Player::printMoney(){
	cout << "You have " << money << " gold" << endl;
}

int Player::getMoney(){
	return money;
}

void Player::printHonour(){
	cout << "You have " << getHonour() << " honour" << endl;
}

list<GreenCard *> &Player::getHand(){
	return hand;
}

list<Personality *> &Player::getArmy(){
	return army;
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
}

void Player::removeFromHand(GreenCard *card){
	hand.remove(card);
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
			if(hold->tapped()){
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
			finished = true;
		}
	}
}

int Player::getNumOfProvinces(){
	return numOfProvinces;
}