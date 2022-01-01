#pragma once
#include "Animal.h"
class CyberSheep : public Animal
{
public:
	CyberSheep(int x, int y,int age,World& world):Animal(x, y,age, world)
	{
		symbol = 'X';
		strength = 11;
		initiative = 4;
		id = World::cyberSheep;
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);
	bool action();
	int cyberSniff(int x, int y, int nX, int nY);
};
