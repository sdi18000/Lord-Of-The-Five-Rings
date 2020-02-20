#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player(string n){
	deck = new DeckBuilder();
	deck->createFateDeck();
	deck->createDynastyDeck();

	deck->deckShuffler(deck->getFateDeck());
	deck->deckShuffler(deck->getDynastyDeck());

	Holding *stronghold = new Stronghold(n, STRONGHOLD);
	holdings.push_back(stronghold);

	numOfProvinces = 4;

	for (int i = 0; i < minCards; i++){
		hand.push_back(deck->getFateDeck()->front());
		deck->getFateDeck()->pop_front();
	}
}