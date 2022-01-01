#include "Animal.h"
bool Animal::action()
{		
	int newX=x, newY=y;
	std::vector<int> possibleMovements;
	if (getValidAdjacentCells(x, y,false,&possibleMovements))
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
	return true;
}
