#include "Belladonna.h"
void Belladonna::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Belladonna(x,y,age,world));	
}
bool Belladonna::collisionDefence(int attackerX, int attackerY)
{
	bool toDelete = false;
	Organism* temp = &(world->getCreature(attackerX, attackerY));
	if (temp->getStrength() > strength)
		toDelete = true;
	world->removeOrganism(*temp);
	if(toDelete)
		world->removeOrganism(*this);
	return false;
}