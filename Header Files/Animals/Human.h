#pragma once
#include "Animal.h"
#include <conio.h>
class Human : public Animal
{
private:
	//int originalStrength;//used for magic potion
	int coolDown = 0;
	bool activatedAbility = false;
	void drawStats();
	void useAbility();
	void decreaseCoolDown();
public:
	Human(int x, int y,int age, World& world) :Animal(x, y,age,world)
	{
		symbol = 'H';
		strength = 5;
		initiative = 4;
		id = World::human;		
	}
	void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world);	
	bool action();	
	void setCoolDown(int val);
	int getCoolDown();
};

