#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include "Enemy.h"
#include "Treasure.h"
using namespace std;

class Room
{
private:
    string name;
    string description;
    Room *next;
    Room *previous;
    Enemy *enemy;
    Treasure *treasure;

public:
    // Constructors
    Room();
    Room(string name, string description, Room *next, Room *previous, Enemy *enemy, Treasure *treasure);

    // Destructor
    ~Room();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    string getDescription();
    void setDescription(string description);

    Room *getNext();
    void setNext(Room *next);

    Room *getPrevious();
    void setPrevious(Room *previous);

    Enemy *getEnemy();
    void setEnemy(Enemy *enemy);

    Treasure *getTreasure();
    void setTreasure(Treasure *treasure);

    // General Methods
    void display();
};

#endif