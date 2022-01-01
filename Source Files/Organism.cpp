#include "Organism.h"
Organism::Organism(int x,int y,int age, World& world)
{
	this->age = age;
	this->x = x;
	this->y = y;
	this->world = &world;
	this->world->addOrganism(*this);
}
void Organism::changeCoordinates(int* x, int* y, std::vector<int>cells)
{
	int dir = rand() % cells.size();	
	*x += world->getDirX(cells[dir]);
	*y += world->getDirY(cells[dir]);
}
bool Organism::getValidAdjacentCells(int x, int y,bool reqEmpty, std::vector<int>* cells)
{	
	if (reqEmpty)
	{	
		for (int i = 0; i < 4; i++)
		{
			if(world->validMove(x+ world->getDirX(i),y+ world->getDirY(i)) && world->checkCell(x+ world->getDirX(i),y+ world->getDirY(i)))
				cells->push_back(i);
		}
	}
	else
	{	
		for (int i = 0; i < 4; i++)
		{
			if (world->validMove(x + world->getDirX(i), y + world->getDirY(i)))
				cells->push_back(i);
		}
	}
	if (cells->size() == 0)
		return false;
	else;
		return true;
}
bool Organism::collisionOffence(int defenderX, int defenderY)
{
	Organism* opponent = &world->getCreature(defenderX, defenderY);
	if (opponent->getId() == id)
	{
		multiply();
		return true;
	}
	if (opponent->collisionDefence(x, y))
	{
		std::string temp = { "Turn " + std::to_string(world->getTurnCounter()) + ". " + world->getOrganismName(id) + ((opponent->isAnimal) ? " is attacking " : " is attempting to eat ")+ world->getOrganismName(opponent->id)+ " at coordinates X: "+std::to_string(defenderX)+ ", Y: "+ std::to_string(defenderY) + ". " };
		world->addAnnouncement(temp);
		if (strength >= opponent->getStrength())
		{
			world->removeOrganism(*opponent);
			world->moveOrganism(x, y, defenderX, defenderY);
			x = defenderX;
			y = defenderY;
			return true;
		}
		else
		{
			return false;
		}
	}
	else return true;
}
bool Organism::collisionDefence(int attackerX, int attackerY)
{
	return true;
}
void Organism::multiply()
{
	if (rand() % breedChance == 0)
	{
		int newX = x, newY = y;
		newX = x;
		newY = y;
		std::vector<int> possibleMovements;
		if (getValidAdjacentCells(x, y, true, &possibleMovements))
		{			
			changeCoordinates(&newX, &newY, possibleMovements);
			Organism* newOrganism;
			std::string temp = { "Turn " + std::to_string(world->getTurnCounter()) + ". " + world->getOrganismName(id) + ((isAnimal) ? " has given birth at coordinates X: " : " has successfully grown from a seed at X:  ") + std::to_string(newX) + ", Y: " + std::to_string(newY) + "." };
			world->addAnnouncement(temp);
			spawnInstance(&newOrganism, newX, newY,0, *world);			
		}
	}
}
char Organism::draw()
{
	return symbol;
}
int Organism::getAge()
{
	return age;
}
int Organism::getInit()
{
	return initiative;
}
int Organism::getX()
{
	return x;
}
int Organism::getY()
{
	return y;
}
int Organism::getStrength()
{
	return strength;
}
void Organism::setX(int x)
{
	this->x = x;
}
void Organism::setY(int y)
{
	this->y = y;
}
int Organism::getId()
{
	return id;
}
void Organism::setStrength(int strength)
{
	this->strength = strength;
}
bool Organism::isAnimalCheck()
{
	return isAnimal;
}
void Organism::operator++()
{
	age++;
}