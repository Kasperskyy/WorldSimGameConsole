#include "Wolf.h"
void Wolf::spawnInstance(Organism** newOrganism,int x, int y,int age,World& world)
{
	*newOrganism = (new Wolf(x,y,age,world));		
}