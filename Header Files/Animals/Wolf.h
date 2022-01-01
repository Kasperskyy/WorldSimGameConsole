#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:		
	Wolf(int x, int y, int age,World& world) :Animal(x, y,age, world)
	{
		symbol = 'w';
		strength = 9;
		initiative = 5;
		id = World::wolf;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age,World& world);
};

