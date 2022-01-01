#include "Guarana.h"
void Guarana::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	*newOrganism = (new Guarana(x,y,age,world));	
}
bool Guarana::collisionDefence(int attackerX, int attackerY)
{
	Organism* temp = &(world->getCreature(attackerX, attackerY));
	temp->setStrength(temp->getStrength() + 3);
	return true;
}