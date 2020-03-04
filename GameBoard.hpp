#pragma once
#include <iostream>
#include "Player.hpp"
#include <vector>

class GameBoard{
	private:
		std::vector<Player*> players;
	public:
		GameBoard(int n);
		~GameBoard();
		void printGameStatistics();
		std::vector<Player *>& getPlayers();
		void printPlayers();	
};