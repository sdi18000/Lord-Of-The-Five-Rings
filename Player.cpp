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
	if(hand.size() != maxCards)
		hand.push_back(deck->drawFateCard());
}

void Player::revealProvinces(){
	list<BlackCard *>::iterator it;
	for(it = provinces.begin(); it != provinces.end(); it++){
		(*it)->reveal();
	}
}

void Player::printHand(){

}

void Player::printProvinces(){

}