#include <iostream>
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"

using namespace std;


int main(){
	DeckBuilder d;
	d.createFateDeck();
	d.createDynastyDeck();
	BlackCard *b = new Holding("Neckbeard nest", SOLO);
	Holding *h1;
	Personality *p1;
	TypeConverter *t = new TypeConverter();
	t->getCorrectType(b, &p1, &h1);
	cout << h1 << endl << p1 << endl;
};
