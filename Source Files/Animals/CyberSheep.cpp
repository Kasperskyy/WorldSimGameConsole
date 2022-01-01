#include "CyberSheep.h"
void CyberSheep::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new CyberSheep(x,y,age,world));	
}
bool CyberSheep::action()
{
	int newX = x, newY = y;	
	std::vector<Organism*> sosnowskyList;
	int count = world->worldScan(World::sosnowsky, &sosnowskyList);
	if (count > 0)	{				
		int minIndex = 0,minDistance = world->getWidth() * world->getHeight(), distance = 0;
		for (int i = 0; i < count; i++)
		{
			distance = cyberSniff(x, y, sosnowskyList[i]->getX(), sosnowskyList[i]->getY());
			if (distance < minDistance)
			{
				minDistance = distance;
				minIndex = i;
			}
		}
		int targetX = sosnowskyList[minIndex]->getX();
		int targetY = sosnowskyList[minIndex]->getY();
		if (targetX < x)
			newX--;
		else if (targetX > x)
			newX++;
		else if (targetY < y)
			newY--;
		else if (targetY > y)
			newY++;
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
	else
	{		
		std::vector<int> possibleMovements;
		if (getValidAdjacentCells(x, y, false, &possibleMovements))
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
}
int CyberSheep::cyberSniff(int x, int y, int nX, int nY)
{
	return (abs(x - nX) + abs(y - nY));
}
