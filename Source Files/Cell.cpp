#include "Cell.h"
Cell::Cell()
{
	currentOrg = nullptr;
}
bool Cell::occupied()
{
	if (currentOrg == nullptr)
		return false;
	else
		return true;
}
void Cell::setCell(Organism& newOrg)
{
	currentOrg = &newOrg;
}
void Cell::clearCell()
{
	currentOrg = nullptr;
}
Organism& Cell::getCell()
{
	return *currentOrg;
}
