#pragma once
#include "Plant.h"
class SowThistle : public Plant
{
public:
	SowThistle(int x, int y,int age,World& world) :Plant(x, y,age, world)
	{
		symbol = '{';
		strength = 0;
		initiative = 0;
		id = World::sowThistle;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);
	bool action();
};

