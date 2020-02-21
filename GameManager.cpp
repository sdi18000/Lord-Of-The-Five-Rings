#include <iostream>
#include "GameManager.hpp"

using namespace std;

GameManager::GameManager(int n){
	gb = new GameBoard(n);
}

void GameManager::startingPhase(){
	cout << "Starting Phase" << endl << endl;
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
	cout << "Equip Phase" << endl << endl;
	vector<Player *> players = gb->getPlayers();
	vector<Player *>::iterator player;
	int p = 1;
	for(player = players.begin(); player != players.end(); player++){
		cout << "Player " << p << "'s turn" << endl << endl;
		(*player)->printHand();
		(*player)->printArena();

		vector<GreenCard *> vect;
		list<GreenCard *>::iterator it;
		list<GreenCard *> hand = (*player)->getHand();
		for (it = hand.begin(); it != hand.end(); it++)
			vect.push_back((*it));

		vector<Personality *> vect2;
		list<Personality *>::iterator it2;
		list<Personality *> army = (*player)->getArmy();
		for (it2 = army.begin(); it2 != army.end(); it2++)
			vect2.push_back((*it2));

		bool finished = false;
		string selection;
		while(!finished){
			cin >> selection;
			if(selection == "done"){
				finished = true;
			}else{
				GreenCard *selected_card;
				try{
					int index = stoi(selection);
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
				selected_card->print();
			}
		}
		p++;
	}
}

void GameManager::battlePhase(){
	// cout << "Equip Phase" << endl << endl;
	// vector<Player *> players = gb->getPlayers();
	// vector<Player *>::iterator it;
	// int p = 1;
	// for(it = players.begin(); it != players.end(); it++){
	// 	cout << "Player " << p << "'s turn" << endl << endl;
		
	// 	p++;
	// }
}

void GameManager::economyPhase(){
	// cout << "Equip Phase" << endl << endl;
	// vector<Player *> players = gb->getPlayers();
	// vector<Player *>::iterator it;
	// int p = 1;
	// for(it = players.begin(); it != players.end(); it++){
	// 	cout << "Player " << p << "'s turn" << endl << endl;
		
	// 	p++;
	// }
}
