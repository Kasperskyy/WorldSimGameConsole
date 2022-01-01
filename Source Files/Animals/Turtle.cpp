#include "Turtle.h"
void Turtle::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Turtle(x,y,age,world));	
}
bool Turtle::action()
{
	int move = rand() % 4;
	if (move == 3)
	{
		int newX = x, newY = y;
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
	}
	return true;
}
bool Turtle::collisionDefence(int attackerX, int attackerY)
{
	Organism* opponent = &world->getCreature(attackerX, attackerY);
	if (opponent->getStrength() < 5)
		return false;
	else
		return true;
}
