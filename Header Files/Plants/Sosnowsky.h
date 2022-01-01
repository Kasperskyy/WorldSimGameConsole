#pragma once
#include "Plant.h"
class Sosnowsky : public Plant
{
public:
	Sosnowsky(int x, int y,int age, World& world) :Plant(x, y, age,world)
	{
		sowChance *= 2;
		symbol = '?';
		strength = 10;
		initiative = 0;
		id = World::sosnowsky;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);
	bool collisionDefence(int attackerX, int attackerY);
	bool action();
};

