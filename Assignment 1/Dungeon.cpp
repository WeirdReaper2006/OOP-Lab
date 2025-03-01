#include <string>
#include <iostream>
#include <vector>
#include "Dungeon.h"
#include "Room.h"
using namespace std;

// Constructors
Dungeon::Dungeon()
{
    name = "";
    level = 0;
    numRooms = 1;
    firstRoom = new Room("Room 1", "This is the first room", nullptr, nullptr);
    firstRoom->setPrevious(nullptr);
    numMonsters = 0;
    numTreasure = 0;
}

Dungeon::Dungeon(string name, int level, int numRooms, int numMonsters, int numTreasure)
{
    this->name = name;
    this->level = level;
    this->numRooms = numRooms;
    firstRoom = new Room("Room 1", "This is the first room", nullptr, nullptr);
    firstRoom->setPrevious(nullptr);
    Room currentRoom = *firstRoom;
    for (int i = 1; i < numRooms; i++)
    {
        Room *newRoom = new Room();
        newRoom->setPrevious(&currentRoom);
        currentRoom.setNext(newRoom);
    }
    this->numMonsters = numMonsters;
    this->numTreasure = numTreasure;
}

// Destructor
Dungeon::~Dungeon()
{
}

// Getter and Setter Methods
string Dungeon::getName()
{
    return name;
}

void Dungeon::setName(string name)
{
    this->name = name;
}

int Dungeon::getLevel()
{
    return level;
}

void Dungeon::setLevel(int level)
{
    this->level = level;
}

int Dungeon::getNumRooms()
{
    return numRooms;
}

void Dungeon::setNumRooms(int numRooms)
{
    this->numRooms = numRooms;
}

int Dungeon::getNumMonsters()
{
    return numMonsters;
}

void Dungeon::setNumMonsters(int numMonsters)
{
    this->numMonsters = numMonsters;
}

int Dungeon::getNumTreasure()
{
    return numTreasure;
}

void Dungeon::setNumTreasure(int numTreasure)
{
    this->numTreasure = numTreasure;
}

// General Methods
void Dungeon::print()
{
    cout << "Dungeon Name: " << name << endl;
    cout << "Dungeon Level: " << level << endl;
    cout << "Number of Rooms: " << numRooms << endl;
    cout << "Number of Monsters: " << numMonsters << endl;
    cout << "Number of Treasure: " << numTreasure << endl;
}