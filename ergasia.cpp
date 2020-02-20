#include <iostream>
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "Player.hpp"
#include "Card.hpp"
#include "GameBoard.hpp"

using namespace std;


int main(){
  GameBoard game(2);
  game.printGameStatistics();
}
