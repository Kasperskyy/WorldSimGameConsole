#include "Fox.h"
void Fox::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Fox(x,y,age,world));	
}
void Fox::sniff(std::vector<int>* possibleMovements)
{	
	for (int i = 0; i < possibleMovements->size(); i++)
	{		
		int temp = possibleMovements->operator[](i);
		if (!world->checkCell(x+ world->getDirX(temp),y+ world->getDirY(temp)))
		{
			if ((world->getCreature(x+ world->getDirX(temp),y+ world->getDirY(temp)).getStrength() > strength) &&(world->getCreature(x + world->getDirX(temp), y + world->getDirY(temp)).getId()!=id))
			{
				std::swap(possibleMovements->operator[](i), possibleMovements->operator[](possibleMovements->size() - 1));
				possibleMovements->erase(possibleMovements->end() - 1);
				i--;
			}
		}		
	}
}
bool Fox::action()
{
	int newX = x, newY = y;
	std::vector<int> possibleMovements;
	if (getValidAdjacentCells(x, y, false, &possibleMovements))
	{
		sniff(&possibleMovements);
		if (possibleMovements.size() != 0)
		{
			changeCoordinates(&newX, &newY, possibleMovements);
			if (world->checkCell(newX, newY))
			{
				world->moveOrganism(x, y, newX, newY);
				x = newX;
				y = newY;
				return true;
			}
			else
			{
				return collisionOffence(newX, newY);
			}
		}
	}
	return true;
}
