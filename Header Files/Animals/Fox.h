#pragma once
#include "Animal.h"
class Fox :	public Animal
{
public:
	Fox(int x, int y, int age,World& world) :Animal(x, y,age, world)
	{
		symbol = 'f';
		strength = 3;
		initiative = 7;
		id = World::fox;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);
	bool action();
	void sniff(std::vector<int>* possibleMovements);
};

