#include "Sheep.h"
void Sheep::spawnInstance(Organism** newOrganism,int x, int y,int age,World& world)
{
	*newOrganism = (new Sheep(x,y,age,world));	
}