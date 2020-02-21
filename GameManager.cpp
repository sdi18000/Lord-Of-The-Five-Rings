#include <iostream>
#include "GameManager.hpp"

using namespace std;

GameManager::GameManager(int n){
	gb = new GameBoard(n);
}

void GameManager::startingPhase(){
	vector<Player *> players = gb->getPlayers();
	vector<Player *>::iterator it;
	int p = 1;
	for(it = players.begin(); it != players.end(); it++){
		cout << "Player " << p << "'s turn" << endl << endl;
		(*it)->untapEverything();
		(*it)->drawFateCard();
		(*it)->revealProvinces();
		(*it)->printHand();
		(*it)->printProvinces();
		p++;
	}
}

void GameManager::equipPhase(){
	
}

void GameManager::battlePhase(){

}

void GameManager::economyPhase(){

}
