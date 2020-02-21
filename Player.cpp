#include <iostream>
#include "Player.hpp"

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
			(*it)->print();
		}
	}
}

void Player::printArena(){
	list<Personality*>::iterator it;
	if(army.size()!=0){
		for(it=army.begin();it!=army.end();it++){
			(*it)->print();
		}
	}
}

void Player::printHoldings(){
	list<Holding*>::iterator it;
	if(holdings.size()!=0){
		for(it=holdings.begin();it!=holdings.end();it++){
			(*it)->print();
		}
	}
}