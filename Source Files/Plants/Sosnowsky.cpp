#include "Sosnowsky.h"
bool Sosnowsky::action()
{
	std::vector<int> possibleMovements;
	if (getValidAdjacentCells(x, y, false, &possibleMovements))
	{
		for (int direction : possibleMovements)
		{
			if (!world->checkCell(x + world->getDirX(direction), y + world->getDirY(direction)))
			{
				Organism* temp = &(world->getCreature(x + world->getDirX(direction), y + world->getDirY(direction)));
				if (temp->isAnimalCheck()&&temp->getId()!=World::cyberSheep)
					world->removeOrganism(*temp);
			}
		}
	}
	int breed = rand() % sowChance;
	if (breed == 0)
		multiply();
	return true;
}
void Sosnowsky::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Sosnowsky(x,y,age,world));
}
bool Sosnowsky::collisionDefence(int attackerX, int attackerY)
{
	Organism* temp = &(world->getCreature(attackerX, attackerY));
	if (temp->getId() == World::cyberSheep)
		return true;
	else
		world->removeOrganism(*temp);
	return false;
}