#pragma once
#include "Plant.h"
class Guarana :	public Plant
{
public:
	Guarana(int x, int y,int age, World& world) :Plant(x, y,age, world)
	{
		symbol = '[';
		strength = 0;
		initiative = 0;
		id = World::guarana;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);	
	bool collisionDefence(int attackerX, int attackerY);
};

