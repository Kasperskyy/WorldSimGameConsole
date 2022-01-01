#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int x, int y,int age, World& world) :Plant(x, y,age, world)
	{
		symbol = '~';
		strength = 0;
		initiative = 0;
		id = World::grass;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);	
};

