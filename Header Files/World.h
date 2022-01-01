#pragma once
#include "Cell.h"
#include "Organism.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>

class World {
private:	
	int width = 100, height = 20, turnCounter = 0;
	void heapify(int i);
	void buildHeap();
	void removeHeapHead();	
	void removeFromQueue(int index);	
	void printFrameAndControls();	
	Cell** board;
	std::vector<Organism*> organisms;
	std::vector<Organism*> turnQueue;
	std::vector<std::string> announcements;
	std::map<int, int> directionX;
	std::map<int, int> directionY;
	std::map<int, std::string> nameMap;
	std::map<int, char> symbolMap;
	enum Direction {
		North, West, East, South
	};
public:
	friend void save(World& world);
	friend void load(std::string name, World& world);
	World();
	enum OrganismType {
		wolf = 1, sheep, fox, turtle, antelope, cyberSheep, grass, sowThistle, guarana, belladonna, sosnowsky, human
	};	
	void printAnnouncements();
	void addAnnouncement(std::string givenAnnouncement);
	void clearBox(int x, int y, int height, int width);	
	void clear();
	void setTurnCounter(int value);
	World& operator++ ();	
	void drawWorld();	
	void makeTurn();
	void addOrganism(Organism& newOrg);
	void removeOrganism(Organism& newOrg);
	bool validMove(int x, int y);
	bool checkCell(int x, int y);
	void moveOrganism(int x, int y, int newX, int newY);
	void setCursorPosition(int x, int y);
	void setConsole();
	Organism& getCreature(int x, int y);
	int worldScan(int id, std::vector<Organism*>* foundObjects);
	int getWidth();
	int getHeight();	
	int getTurnCounter();
	int getDirX(int direction);
	int getDirY(int direction);
	char getOrganismSymbol(int orgId);
	std::string getOrganismName(int orgId);
};