#include <iostream>
#include "GameManager.hpp"
#include <algorithm>

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
		p++;
		//(*player)->getArmy().push_back(new Personality("Hida Shozen",ATTACKER));// -for testing-

		vector<GreenCard *> vect;
		list<GreenCard *>::iterator it;
		list<GreenCard *> hand = (*player)->getHand();
		for (it = hand.begin(); it != hand.end(); it++)
			vect.push_back((*it));

		vector<Personality *> vect2;
		list<Personality *>::iterator it2;
		list<Personality *> army = (*player)->getArmy();
		if(army.empty()){
			cout << "Army is empty" << endl << endl;
			continue;
		}
		for (it2 = army.begin(); it2 != army.end(); it2++)
			vect2.push_back((*it2));

		bool finished = false;
		string selection;
		while(!finished){
			(*player)->printHand();
			(*player)->printArena();
			(*player)->printMoney();
			int refund = 0;
			cout << "Choose card from hand or 'done' to end turn" << endl;
			cin >> selection;
			if(selection == "done"){
				finished = true;
			}else{
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
				cout << "You have selected:" << endl;
				selected_card->print();
				if((*player)->affords(selected_card) == false){
					cout << "Not enough money" << endl;
					continue;
				}
				(*player)->buy(selected_card);
				refund += (selected_card->getCost());
				cout << "Choose card from army or 'cancel' to cancel" << endl;
				cin >> selection;
				if(selection == "cancel"){
					(*player)->receive(refund);
					continue;
				}else{
					Personality *per;
					try{
						int index = stoi(selection)-1;
						try{
							per = vect2.at(index);
						}catch(out_of_range e){
							(*player)->receive(refund);
							cout << "Choose a valid card" << endl;
							continue;
						}
					}catch(out_of_range e){
						(*player)->receive(refund);
						cout << "Invalid input, try again" << endl;
						continue;
					}catch(invalid_argument){
						(*player)->receive(refund);
						cout << "Invalid input, try again" << endl;
						continue;
					}
					cout << "You have selected:" << endl;
					per->print();
					if(per->canEquip() == false){
						(*player)->receive(refund);
						cout << per->getName() << " can't equip any more cards" << endl;
						continue;
					}
					if(per->HonouredEnough(selected_card) == false){
						(*player)->receive(refund);
						cout << per->getName() << " not honoured enough" << endl;
						continue;
					}
					cout << "Do you want to upgrade " + selected_card->getName() + "?" << endl;
					string choice;
					cin >> choice;
					if(choice == "Yes" || choice == "yes"){
						if((*player)->affords(selected_card->getEffectCost())){
							(*player)->pay(selected_card->getEffectCost());
							cout << "Upgraded and equipped " + selected_card->getName() << endl;
							per->equip(selected_card,1);
							(*player)->removeFromHand(selected_card);
							vect.erase(remove(vect.begin(), vect.end(), selected_card), vect.end());
						}else{
							(*player)->receive(refund);
							cout << "Not enough money for upgrade" << endl;
						}
					}else if(choice == "No" || choice == "no"){
						cout << "Equipped " + selected_card->getName() << endl;
						per->equip(selected_card,0);
						(*player)->removeFromHand(selected_card);
						vect.erase(remove(vect.begin(), vect.end(), selected_card), vect.end());
					}else{
						(*player)->receive(refund);
						cout << "Invalid input, try again" << endl;
						continue;
					}
				}
			}
		}
	}
}

void GameManager::battlePhase(){
	
}

void GameManager::economyPhase(){
	cout << "Economy Phase" << endl << endl;
	vector<Player *> players = gb->getPlayers();
	vector<Player *>::iterator player;
	int p = 1;
	for(player = players.begin(); player != players.end(); player++){
		cout << "Player " << p << "'s turn" << endl << endl;
		p++;
		int money = (*player)->getMoney();
		bool finished = false;
		while(!finished){
			(*player)->printProvinces();
			(*player)->printHoldings();
			cout << "'Buy' to buy a province, 'Tap' to tap a holding or 'done' to stop" << endl;
			cout << "You have " << money << " gold" << endl;
			string input;
			cin >> input;
			if(input == "tap" || input == "Tap"){
				money += (*player)->tapHoldings();
			}else if(input == "buy" || input == "Buy"){
				int cost = (*player)->chooseProvince(money);
				(*player)->printHoldings(); //to remove
				if(money-(*player)->getMoney() < cost){
					(*player)->pay(money-cost);
				}
				money -= cost;
			}else if(input == "done" || input == "Done"){
				finished = true;
			}else{
				cout << "Invalid input, try again" << endl;
			}
		}
	}
}

void GameManager::lastPhase(){
	cout << "Last Phase" << endl << endl;
	vector<Player *> players = gb->getPlayers();
	vector<Player *>::iterator it;
	int p = 1;
	for(it = players.begin(); it != players.end(); it++){
		cout << "Player " << p << "'s turn" << endl << endl;
		(*it)->discardSurplusFateCards();
		(*it)->printProvinces();
		(*it)->printHand();
		(*it)->printHoldings();
		(*it)->printArena();
		p++;
	}
	gb->printGameStatistics();
}