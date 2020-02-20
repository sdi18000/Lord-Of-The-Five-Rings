#pragma once
#include <list>
#include "Card.hpp"
#include "Holding.hpp"
#include "Stronghold.hpp"
#include "Personality.hpp"
#include "DeckBuilder.hpp"
#include <string>

#define maxCards 6
#define minCards 4

class Player{
protected:
	DeckBuilder *deck;
	std::list<GreenCard *> hand;
	std::list<Holding *> holdings;
	std::list<Personality *> army;
	int numOfProvinces;
public:
	Player(std::string n);
};