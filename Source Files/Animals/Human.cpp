#include "Human.h"
#define A_UP 72
#define A_DOWN 80
#define A_LEFT  75
#define A_RIGHT 77
#define SPACE 32
#define ARROW_KEYS 224
#define NUM_KEY_5 53
void Human::spawnInstance(Organism** newOrganism, int x, int y,int age, World& world)
{
	//Only one instance of human on the map at any time, included for potential expansion
	*newOrganism = (new Human(x,y,age,world));	
}
void Human::useAbility()
{
	coolDown = 10;
	strength +=5;
	activatedAbility = true;
}
void Human::decreaseCoolDown()
{
	if (coolDown>5)
		strength--;
	coolDown--;
}
void Human::setCoolDown(int val)
{
	coolDown = val;
}
void Human::drawStats()
{
	world->clearBox(0, 15, 5, 25);
	world->setCursorPosition(0, 15);
	std::cout <<"Your Turn."<<std::endl<< "Your Strength: " << strength << std::endl << "Potion cooldown " << std::endl<< "(0 = available) : "<< coolDown;
}
bool Human::action()
{		
	world->printAnnouncements();
	if (coolDown != 0)
		decreaseCoolDown();
	drawStats();
	int newX = x, newY = y;
	int input = 0;
	bool moved = false;		
		while (input != SPACE&&!moved)
		{	
			input = _getch();
			switch (input)
			{
			case SPACE:
				newX = x;
				newY = y;
				moved = true;
				break;
			case NUM_KEY_5:
				if (coolDown == 0)
				{
					useAbility();
					drawStats();
				}
				break;			
			case ARROW_KEYS:
				input = _getch();
				switch (input)
				{
				case A_UP:
					newY--;
					moved = true;
					break;
				case A_DOWN:
					newY++;
					moved = true;
					break;
				case A_LEFT:
					newX--;
					moved = true;
					break;
				case A_RIGHT:
					newX++;
					moved = true;
					break;
				}
				break;
			}
			if (newX < 0 || newX >= world->getWidth() || newY < 0 || newY >= world->getHeight())
			{
				moved = false;
				newX = x;
				newY = y;
			}
		}		
	if ((newX == x) && (newY == y))
		return true;
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
	return true;
}
int Human::getCoolDown()
{
	return coolDown;
}