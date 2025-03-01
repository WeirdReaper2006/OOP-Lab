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
    numRooms = 1;
    Enemy *enemy = nullptr;
    Treasure *treasure = nullptr;
    firstRoom = new Room("Room 1", "This is the first room", nullptr, nullptr, enemy, treasure);
    firstRoom->setPrevious(nullptr);
    numMonsters = 0;
    numTreasure = 0;
}

Dungeon::Dungeon(string name, int numRooms, int numMonsters, int numTreasure)
{
    this->name = name;
    this->numRooms = numRooms;
    Enemy *enemy = nullptr;
    Treasure *treasure = nullptr;
    firstRoom = new Room("Room 1", "This is the first room", nullptr, nullptr, enemy, treasure);
    firstRoom->setPrevious(nullptr);
    Room currentRoom = *firstRoom;
    for (int i = 1; i < numRooms; i++)
    {
        Room *newRoom = new Room();
        newRoom->setName("Room " + to_string(i + 1));
        newRoom->setDescription("This is room " + to_string(i + 1));
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
    cout << "Number of Rooms: " << numRooms << endl;
    cout << "Number of Monsters: " << numMonsters << endl;
    cout << "Number of Treasure: " << numTreasure << endl;
}