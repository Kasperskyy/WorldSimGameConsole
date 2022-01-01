#pragma once
#include "Organism.h"
class Plant : public Organism
{
protected:
	int sowChance = 10;//1 in 10, 10%
public:
	Plant(int x, int  y,int age, World& world) : Organism(x, y,age, world)
	{
		isAnimal = false;
	}
	virtual bool action();	
	int getSowChance();
	void setSowChance(int chance);
};

