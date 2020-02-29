#include <iostream>
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "GameManager.hpp"
#include "GameBoard.hpp"

using namespace std;


int main(){
  GameManager gm(2);
  cout << endl << "Game has started" << endl << endl;
  int p=1;
  Player* winner=NULL;
  while(1){
  	  cout << "Round " << p << endl << endl;
	  gm.startingPhase();
	  gm.equipPhase();
	  gm.battlePhase();
	  gm.economyPhase();
	  gm.lastPhase();
	  winner=gm.checkWinningCondition();
	  if(winner!=NULL){
	  	cout << "Winner of the game is the player with Stronghold "<< (winner->getStronghold())->getName() << endl << endl; 
	  	cout << " All others perished in vain!! ";
	  	break;
	  }
	}
	p++;
}
