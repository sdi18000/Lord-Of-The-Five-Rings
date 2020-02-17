#include <iostream>

enum personality{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION}; 
enum holding{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD}; 
enum follower{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum item{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};
enum cardType{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};

class Card{
	protected:
		int cost;
		std::string name;
		int isTapped;
	public:
		Card(std::string n,int c);
};



class GreenCard:public Card{
	public:
		GreenCard(std::string n,int c);

};

class BlackCard:public Card{
	public:
		BlackCard(std::string n,int c);
};



class Stronghold:public BlackCard{
	protected:
			int StartingHonour;
			int IntitialDefense;
			int money;
	public:
		Stronghold(std::string n,holding h);
};
