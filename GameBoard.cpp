#include <iostream>
#include "GameBoard.hpp"
#include <string>

using namespace std; 

GameBoard::GameBoard(int n){
	int l=1;
	string a;
	for(int o=0;o<n;o++){
		string p="Player ";
		a=to_string(o+1);
		p=p+a;
		players.push_back(new Player(p,l));
		l++;
		
	}
	
}


void GameBoard::printGameStatistics(){
		vector<Player*>::iterator it;
		int i=1;
		for(it=players.begin();it!=players.end();it++){
			cout << "Player " << i ;
			(*it)->printstats(); 
			i++;
		}
}
