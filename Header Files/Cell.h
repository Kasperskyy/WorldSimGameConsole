#pragma once
class Organism;
class Cell
{
private:
    Organism* currentOrg;
public:
    Cell();
    bool occupied();
    void setCell(Organism& newOrg);
    void clearCell();   
    Organism& getCell();
};

