#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int x, int  y,int age, World& world):Animal(x,y,age,world)
	{
		symbol = 'a';
		strength = 4;
		initiative = 4;
		id = World::antelope;		
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age,World& world);
	bool action();
	bool collisionDefence(int attackerX, int attackerY);	
};


