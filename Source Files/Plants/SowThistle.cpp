#include "SowThistle.h"
void SowThistle::spawnInstance(Organism** newOrganism, int x, int y, int age,World& world)
{
	*newOrganism = (new SowThistle(x,y,age,world));	
}
bool SowThistle::action()
{
	for (int i = 0; i < 3; i++)
	{
		int breed = rand() % sowChance;
		if (breed == 0)
			multiply();
	}
	return true;
}