#pragma once
#include "World.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

class World;
class Organism {
protected:	
	int x, y, initiative, strength, age = 0;
	int breedChance = 1;//100% default success rate
	bool isAnimal;
	char symbol;
	World* world;	
	int id;
public:	
	Organism(int x, int y,int age, World& world);	
	virtual bool action() = 0;
	virtual char draw();
	virtual void multiply();
	virtual void spawnInstance(Organism** newOrganism, int x, int y,int age, World& world) = 0;
	virtual bool collisionDefence(int attackerX, int attackerY);
	virtual bool collisionOffence(int defenderX, int defenderY);
	void changeCoordinates(int* x, int* y, std::vector<int>cells);
	void operator++();
	int getAge();
	int getInit();
	int getStrength();
	int getX();
	int getY();
	int getId();
	bool getValidAdjacentCells(int x, int y, bool reqEmpty, std::vector<int>* cells);
	void setX(int x);
	void setY(int y);	
	void setStrength(int strength);	
	bool isAnimalCheck();		
	
};


