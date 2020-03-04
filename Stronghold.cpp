#include <iostream>
#include "Stronghold.hpp"

using namespace std;

Stronghold::Stronghold(string n,holding h,int i):Holding(n,h){
		StartingHonour=i;
		InitialDefence=5;
}

int Stronghold::getHonour(){
	return StartingHonour;
}