#include "World.h"
#include "windows.h"
#define ANNOUNCEMENT_LIMIT 11
using namespace std;
World::World()
{
	directionX = {
		{North,0},
		{West,-1},
		{East,1},
		{South,0},
	};
	directionY = {
	   {North,-1},
	   {West,0},
	   {East,0},
	   {South,1}
	};
	nameMap= {
		{wolf,"Wolf"},
		{sheep,"Sheep"},
		{fox,"Fox"},
		{turtle,"Turtle"},
		{antelope,"Antelope"},
		{cyberSheep,"Cyber Sheep"},
		{grass,"Grass"},
		{sowThistle,"Sow Thistle"},
		{guarana,"Guarana"},
		{belladonna,"Belladonna"},
		{sosnowsky,"Sosnowsky's Hogweed"},
		{human,"Human"}
	};
	symbolMap= {
		{wolf,'w'},
		{sheep,'s'},
		{fox,'f'},
		{turtle,'t'},
		{antelope,'t'},
		{cyberSheep,'X'},
		{grass,'~'},
		{sowThistle,'{'},
		{guarana,'['},
		{belladonna,'!'},
		{sosnowsky,'?'},
		{human,'H'}
	};
	board = new Cell * [height];
	for (int i = 0; i < height; i++)
		board[i] = new Cell[width];	
}
void World::makeTurn()
{
	buildHeap();	
	drawWorld();		
	for (int i = 0; i < turnQueue.size();)
	{				
		turnQueue[0]->operator++();			
		if (!turnQueue[0]->action())
		{
			removeOrganism(*turnQueue[0]);
		}
		else			
			removeHeapHead();		
	}
	drawWorld();
}
void World::moveOrganism(int x, int y, int newX, int newY)
{
	Organism* temp = &board[y][x].getCell();
	board[y][x].clearCell();
	board[newY][newX].setCell(*temp);
	setCursorPosition(25 + x, y);
	cout << "-";
	setCursorPosition(25 + newX, newY);
	cout << temp->draw();
	setCursorPosition(0, 19);
}
void World::heapify(int i)
{
	int left = (i * 2) + 1, right = (i * 2) + 2, maxps;
	if (left < turnQueue.size()     &&      ((turnQueue[left]->getInit() > turnQueue[i]->getInit())    ||    ((turnQueue[left]->getInit() == turnQueue[i]->getInit()) && (turnQueue[left]->getAge() > turnQueue[i]->getAge()))))
	{
		maxps = left;
	}
	else
	{
		maxps = i;
	}
	if (right < turnQueue.size() &&      ((turnQueue[right]->getInit() > turnQueue[maxps]->getInit())   ||   ((turnQueue[right]->getInit() == turnQueue[maxps]->getInit()) && (turnQueue[right]->getAge() > turnQueue[maxps]->getAge()))))
	{
		maxps = right;
	}
	if (maxps != i)
	{
		swap(turnQueue[i], turnQueue[maxps]);
		heapify(maxps);
	}	
}
void World::addOrganism(Organism& newOrg)
{
	organisms.push_back(&newOrg);	
	board[newOrg.getY()][newOrg.getX()].setCell(newOrg);	
}
void World::removeOrganism(Organism& newOrg)
{	
	string temp = { "Turn " + to_string(turnCounter) + ". " + nameMap[newOrg.getId()] + ((newOrg.isAnimalCheck())?" has been slain at coordinates X: ":" has been consumed at coordinates X:  ") + to_string(newOrg.getX()) + ", Y: " + to_string(newOrg.getY()) + "." };
	addAnnouncement(temp);
	int index = std::distance(turnQueue.begin(), std::find(turnQueue.begin(), turnQueue.end(), &newOrg));
	if(index!=turnQueue.size())
		removeFromQueue(index);
	index = std::distance(organisms.begin(), std::find(organisms.begin(), organisms.end(), &newOrg));
	board[newOrg.getY()][newOrg.getX()].clearCell();
	delete organisms[index];	
	organisms.erase(organisms.begin() + index);	
}
void World::buildHeap()
{	
	turnQueue = organisms;	
	for (int i = (organisms.size()-1) / 2; i >= 0; i--)
	{
		heapify(i);
	}	
}
void World::removeHeapHead()
{		turnQueue[0] = turnQueue[turnQueue.size()-1];		
		turnQueue.pop_back();		
		heapify(0);	
}
void World::removeFromQueue(int index)
{		
		turnQueue[index] = turnQueue[turnQueue.size()-1];		
		turnQueue.pop_back();
		for (int i = (turnQueue.size() - 1) / 2; i >= 0; i--)
		{
			heapify(i);
		}	
}
World& World::operator++ ()
{
	turnCounter++;
	return *this;
}
void World::setTurnCounter(int value)
{
	turnCounter = value;
}
void World::clear()
{
	announcements.clear();
	for (int i=0;i<organisms.size();)
		removeOrganism(*organisms[i]);
}
int World::getTurnCounter()
{
	return turnCounter;
}
int World::getDirX(int direction)
{
	return directionX[direction];
}
int World::getDirY(int direction)
{
	return directionY[direction];
}
char World::getOrganismSymbol(int orgId)
{
	return symbolMap[orgId];
}
std::string World::getOrganismName(int orgId)
{
	return nameMap[orgId];
}
int World::getWidth()
{
	return width;
}
int World::getHeight()
{
	return height;
}
Organism& World::getCreature(int x, int y)
{
	return board[y][x].getCell();
}
int World::worldScan(int id, std::vector<Organism*>* foundObjects)
{
	int counter = 0;
	for (int i = 0; i < organisms.size(); i++)
	{
		if (organisms[i]->getId() == id)
		{
			counter++;
			foundObjects->push_back(organisms[i]);
		}
	}
	return counter;
}
bool World::validMove(int x, int y)
{
	if ((x < width && y < height) && (x >= 0 && y >= 0))
		return true;
	else
		return false;
}
bool World::checkCell(int x, int y)
{
	if (board[y][x].occupied())
		return false;
	else
		return true;
}

//UI and formatting code below
void World::setConsole()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	c.X = 140;
	c.Y = 38;
	SetConsoleScreenBufferSize(handle, c);
	SMALL_RECT r;
	r.Left = 0;
	r.Right = 0;
	r.Right = c.X - 1;
	r.Bottom = c.Y - 1;
	SetConsoleWindowInfo(handle, true, &r);
	HWND console = GetConsoleWindow();
	RECT R;
	GetWindowRect(console, &R); //stores the console's current dimensions	
	MoveWindow(console, R.left, R.top, 1200, 600, TRUE);
}
void World::setCursorPosition(int x, int y)
{
	COORD coordinates = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void World::printFrameAndControls()
{
	printAnnouncements();
	setCursorPosition(0, 20);
	for (int i = 0; i <= 141; i++)
	{
		cout << "*";
	}
	setCursorPosition(0, 33);
	for (int i = 0; i <= 141; i++)
	{
		cout << "*";
	}
	for (int i = 21; i < 33; i++)
	{
		setCursorPosition(0, i);
		cout << "*";
		setCursorPosition(141, i);
		cout << "*";
	}
	clearBox(0, 15, 5, 25);
	setCursorPosition(0, 0);
	cout << "World Simulator" << endl << "Kacper Krzeminski" << endl << "180229" << endl << "You play as the Human(H)" << endl << "Controls:" << endl << endl << "Up-   Move North" << endl << "Down- Move South" << endl << "Left- Move Wast" << endl << "Right-Move East" << endl << "5-    Use Magic Potion" << endl << "Space-Skip Human Turn" << "\n\n\n\n" << "Press S-save, L-load" << endl << "Press Q-quit,R-restart" << endl << "Press ENTER to start turn" << endl << endl << "Log:";
	clearBox(126, 0, 1, 15);
	setCursorPosition(126, 0);
	cout << "Turn: " << turnCounter;
	setCursorPosition(126, 1);
	cout << "Encyclopedia:";
	for (int i = 2; i < symbolMap.size() + 1; i++)
	{
		setCursorPosition(126, i);
		cout << symbolMap[i] << " = " << nameMap[i];
	}
}
void World::addAnnouncement(string givenAnnouncement)
{
	announcements.push_back(givenAnnouncement);
	if (announcements.size() > ANNOUNCEMENT_LIMIT)
		announcements.erase(announcements.begin());
}
void World::printAnnouncements()
{
	int counter = 21;
	clearBox(1, 21, 12, 140);
	setCursorPosition(1, 21);
	for (int i = announcements.size() - 1; i >= 0; i--)
	{
		cout << announcements[i] << endl;
		counter++;
		setCursorPosition(1, counter);
	}
}
void World::clearBox(int x, int y, int height, int width)
{
	int counter = y;
	setCursorPosition(x, y);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << " ";
		}
		cout << endl;
		counter++;
		setCursorPosition(x, counter);
	}
}
void World::drawWorld()
{
	clearBox(25, 0, height, width);
	for (int i = 0; i < height; i++)
	{
		setCursorPosition(25, i);
		for (int j = 0; j < width; j++)
		{
			if (!board[i][j].occupied())
				cout << "-";
			else
				cout << board[i][j].getCell().draw();
		}
		cout << endl;
	}
	printFrameAndControls();
}