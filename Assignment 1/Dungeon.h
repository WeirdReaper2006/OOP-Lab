#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>
#include <iostream>
#include <vector>
#include "Room.h"
using namespace std;

class Dungeon
{
private:
    string name;
    int level;
    int numRooms;
    int numMonsters;
    int numTreasure;

public:
    Room *firstRoom;
    // Constructors
    Dungeon();
    Dungeon(string name, int level, int numRooms, int numMonsters, int numTreasure);

    // Destructor
    ~Dungeon();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    int getLevel();
    void setLevel(int level);

    int getNumRooms();
    void setNumRooms(int numRooms);

    int getNumMonsters();
    void setNumMonsters(int numMonsters);

    int getNumTreasure();
    void setNumTreasure(int numTreasure);

    // General Methods
    void print();
};

#endif