#pragma once
#include "Organism.h"
class Animal :	public Organism
{
public:	
	Animal(int x,int  y,int age, World& world) : Organism(x, y,age, world)
	{
		isAnimal = true;
	}
	virtual bool action();
	
};
