#include "Grass.h"
void Grass::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Grass(x,y,age,world));	
}
