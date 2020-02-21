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
  gm.startingPhase();
}
