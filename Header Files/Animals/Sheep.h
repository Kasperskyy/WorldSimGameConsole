#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:	
	Sheep(int x, int y,int age, World& world) :Animal(x, y,age, world)
	{
		symbol = 's';
		strength = 4;
		initiative = 4;
		id = World::sheep;
	}
	void spawnInstance(Organism** newOrganism,int x, int y,int age,World& world);	
};

