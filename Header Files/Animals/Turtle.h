#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(int x, int y, int age,World& world):Animal(x,y,age,world)
	{
		symbol = 't';
		strength = 2;
		initiative = 1;
		id = World::turtle;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);
	bool collisionDefence(int attackerX, int attackerY);	
	bool action();
	
};
