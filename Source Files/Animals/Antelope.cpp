#include "Antelope.h"
void Antelope::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Antelope(x,y,age,world));	
}
bool Antelope::action()
{	
	int newX = x, newY = y;
	std::vector<int> possibleMovements;
	if (getValidAdjacentCells(x, y, false, &possibleMovements))
	{
		changeCoordinates(&newX, &newY, possibleMovements);		
	}
	else
		return true;
	possibleMovements.clear();
	if (getValidAdjacentCells(newX, newY, false, &possibleMovements))
	{
		changeCoordinates(&newX, &newY, possibleMovements);
		if (world->checkCell(newX, newY)||(x==newX&&y==newY))
		{
			world->moveOrganism(x, y, newX, newY);
			x = newX;
			y = newY;
			return true;
		}
		else
		{
			int escapes = rand() % 2;
			possibleMovements.clear();
			if (escapes&& getValidAdjacentCells(newX, newY, true, &possibleMovements))
			{			
				changeCoordinates(&newX, &newY, possibleMovements);
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
bool Antelope::collisionDefence(int attackerX, int attackerY)
{
	Organism* opponent = &world->getCreature(attackerX, attackerY);
	std::vector<int> possibleMovements;
	int escapes = rand() % 2,newX=x,newY=y;
	if (escapes && getValidAdjacentCells(newX, newY, true, &possibleMovements))
	{
		changeCoordinates(&newX, &newY, possibleMovements);
		world->moveOrganism(x, y, newX, newY);
		world->moveOrganism(attackerX, attackerY, x, y);
		opponent->setX(x);
		opponent->setY(y);
		x = newX;
		y = newY;
		return false;
	}
	else
		return true;
}