#include <iostream>
#include "GameManager.hpp"

using namespace std;

GameManager::GameManager(int n){
	gb = new GameBoard(n);
}

void GameManager::startingPhase(){
	vector<Player *> players = gb->getPlayers();
	vector<Player *>::iterator it;
	for(it = players.begin(); it != players.end(); it++){
		(*it)->untapEverything();
		(*it)->drawFateCard();
		(*it)->revealProvinces();
	}
}

void GameManager::equipPhase(){

}

void GameManager::battlePhase(){

}

void GameManager::economyPhase(){

}