#pragma once
#include "Plant.h"
class Belladonna : public Plant
{
public:
	Belladonna(int x, int y,int age, World& world) :Plant(x, y,age, world)
	{
		sowChance *= 2;
		symbol = '!';
		strength = 99;
		initiative = 0;
		id = World::belladonna;
	}
	void spawnInstance(Organism** newOrganism, int x, int y, int age,World& world);	
	bool collisionDefence(int attackerX, int attackerY);
};



