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

Room::Room(string name, string description, Room *next, Room *previous)
{
    this->name = name;
    this->description = description;
    this->next = next;
    this->previous = previous;
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

// General Methods
void Room::display()
{
    cout << "Room Name: " << name << endl;
    cout << "Description: " << description << endl;
}