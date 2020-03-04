#include "GameBoard.hpp"
#include "Player.hpp"

class GameManager{
protected:
	GameBoard *gb;
public:
	GameManager(int n);
	~GameManager();
	void startingPhase();
	void equipPhase();
	void battlePhase();
	void economyPhase();
	void lastPhase();
	Player *checkWinningCondition();
	GameBoard *getBoard();
};