#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

// Constructors
Room::Room()
{
    name = "";
    description = "";
    next = nullptr;
    previous = nullptr;
}

Room::Room(string name, string description, Room *next, Room *previous, Enemy *enemy, Treasure *treasure)
{
    this->name = name;
    this->description = description;
    this->next = next;
    this->previous = previous;
    this->enemy = enemy;
    this->treasure = treasure;
}

// Destructor
Room::~Room()
{
}

// Getter and Setter Methods
string Room::getName()
{
    return name;
}

void Room::setName(string name)
{
    this->name = name;
}

string Room::getDescription()
{
    return description;
}

void Room::setDescription(string description)
{
    this->description = description;
}

Room *Room::getNext()
{
    return next;
}

void Room::setNext(Room *next)
{
    this->next = next;
}

Room *Room::getPrevious()
{
    return previous;
}

void Room::setPrevious(Room *previous)
{
    this->previous = previous;
}

Enemy *Room::getEnemy()
{
    return enemy;
}

void Room::setEnemy(Enemy *enemy)
{
    this->enemy = enemy;
}

Treasure *Room::getTreasure()
{
    return treasure;
}

void Room::setTreasure(Treasure *treasure)
{
    this->treasure = treasure;
}

// General Methods
void Room::display()
{
    cout << "Room Name: " << name << endl;
    cout << "Description: " << description << endl;
}