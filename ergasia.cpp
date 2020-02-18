#include <iostream>
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"

using namespace std;


int main(){
//	DeckBuilder d;
//	d.createFateDeck();
//	d.createDynastyDeck();
	Personality f("yolo",ATTACKER);
	BlackCard* d=&f;
	Personality* p1;
	Holding* h1;
	TypeConverter* t=new TypeConverter();
	t->getCorrectType(d,&p1,&h1);
	cout << h1 << " and " << p1 << endl;
};
