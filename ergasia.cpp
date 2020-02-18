#include <iostream>
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"

using namespace std;


int main(){
//	DeckBuilder d;
//	d.createFateDeck();
//	d.createDynastyDeck();
// Personality f("yolo",ATTACKER);
// BlackCard* d=&f;
// Personality* p1;
// Holding* h1;
// TypeConverter* t=new TypeConverter();
// t->getCorrectType(d,&p1,&h1);
// cout << h1 << " and " << p1 << endl;
	Holding *mine = new Holding("My mine", MINE);
	Holding *goldmine = new Holding("Gold", GOLD_MINE);
	Holding *crystalmine = new Holding("Crystal", CRYSTAL_MINE);
	cout << "Mine harvest: " << mine->getHarvestValue() << endl;
	cout << "Gold Mine harvest: " << goldmine->getHarvestValue() << endl;
	cout << "Crystal Mine harvest: " << crystalmine->getHarvestValue() << endl;
    goldmine->connect(mine, crystalmine);
	cout << "Mine harvest: " << mine->getHarvestValue() << endl;
	cout << "Gold Mine harvest: " << goldmine->getHarvestValue() << endl;
	cout << "Crystal Mine harvest: " << crystalmine->getHarvestValue() << endl;
};
