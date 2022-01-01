#include "Plant.h"
bool Plant::action()
{
	int breed = rand() % sowChance;
	if (breed == 0)
		multiply();
	return true;
}
int Plant::getSowChance()
{
	return sowChance;
}
void Plant::setSowChance(int chance)
{
	sowChance = chance;
}