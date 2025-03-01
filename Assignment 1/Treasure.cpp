#include <iostream>
#include <string>
#include "Treasure.h"
using namespace std;

// Constructors
Treasure::Treasure() : Item()
{
    name = "";
    description = "";
}

Treasure::Treasure(string name, string description) : Item(name, description)
{
    this->name = name;
    this->description = description;
    cout << "Treasure" << name << "created" << endl;
}

// Destructor
Treasure::~Treasure()
{
}

// Getter and Setter Methods
string Treasure::getName()
{
    return name;
}

void Treasure::setName(string name)
{
    this->name = name;
}

string Treasure::getDescription()
{
    return description;
}

void Treasure::setDescription(string description)
{
    this->description = description;
}

// General Method
void Treasure::display()
{
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
}
