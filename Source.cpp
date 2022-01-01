#include "World.h"
#include <time.h>
#include <iostream>
#include "Sheep.h"
#include "Wolf.h"
#include "Fox.h"
#include "Antelope.h"
#include "CyberSheep.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Belladonna.h"
#include "Guarana.h"
#include "Sosnowsky.h"
#include "Human.h"
#include "Turtle.h"
#include <fstream>
using namespace std;
void save(World& world);
void load(string name, World& world);
int main()
{	
	srand(time(NULL));
	World earth;		
	earth.setConsole();	
	char input=' ';
	load("default.txt", earth);
	earth.drawWorld();
	while (input!='q')
	{
		input = _getch();
		switch (input)
		{
		case '\r':
		case '\n':
			++earth;
			earth.makeTurn();
			break;
		case 'q':
			earth.clear();
			system("CLS");
			break;
		case 's':
			save(earth);
			break;
		case 'r':
			load("default.txt",earth);
			earth.drawWorld();			
			break;
		case 'l':
			load("save.txt",earth);
			earth.drawWorld();			
			break;
		}
	}
	return 0;
}


void save(World& world)
{
	ofstream file;
	file.open("save.txt");
	file << world.organisms.size()<<" ";
	file << world.turnCounter<<'\n';
	for (Organism* v : world.organisms)
	{
		file << v->getId() << " ";
		file << v->getX() << " ";
		file << v->getY() << " ";
		file << v->getAge() << " ";
		file << v->getStrength() << " ";
		if (v->getId()== World::human)
			file << ((Human*)v)->getCoolDown();
		file << '\n';
	}
	file.close();
}
void load(std::string name,World& world)
{
	world.clear();
	ifstream file;
	Organism* temp;
	file.open(name);
	int orgCount, type, x, y, age, strength, coolDown, turnCounter;
	file >> orgCount;
	file >> turnCounter;
	world.setTurnCounter(turnCounter);
	for (int i = 0; i < orgCount; i++)
	{
		file >> type;
		file >> x;
		file >> y;
		file >> age;
		file >> strength;
		switch (type)
		{
		case World::wolf:		
			temp= new Wolf(x, y, age, world);
			((Wolf*)temp)->setStrength(strength);
			break;
		case World::sheep:
			temp = new Sheep(x, y, age, world);
			((Sheep*)temp)->setStrength(strength);
			break;
		case World::fox:
			temp = new Fox(x, y, age, world);
			((Fox*)temp)->setStrength(strength);
			break;
		case World::turtle:
			temp = new Turtle(x, y, age, world);
			((Turtle*)temp)->setStrength(strength);
			break;
		case World::antelope:
			temp = new Antelope(x, y, age, world);
			((Antelope*)temp)->setStrength(strength);
			break;
		case World::cyberSheep:
			temp = new CyberSheep(x, y, age, world);
			((CyberSheep*)temp)->setStrength(strength);
			break;
		case World::grass:
			temp = new Grass(x, y, age, world);
			((Grass*)temp)->setStrength(strength);
			break;
		case World::sowThistle:
			temp = new SowThistle(x, y, age, world);
			((SowThistle*)temp)->setStrength(strength);
			break;
		case World::guarana:
			temp = new Guarana(x, y, age, world);
			((Guarana*)temp)->setStrength(strength);
			break;
		case World::belladonna:
			temp = new Belladonna(x, y, age, world);
			((Belladonna*)temp)->setStrength(strength);
			break;
		case World::sosnowsky:
			temp = new Sosnowsky(x, y, age, world);
			((Sosnowsky*)temp)->setStrength(strength);
			break;
		case World::human:
			temp = new Human(x, y, age, world);
			file >> coolDown;
			((Human*)temp)->setCoolDown(coolDown);
			((Human*)temp)->setStrength(strength);
			break;
		}
	}
	file.close();
}