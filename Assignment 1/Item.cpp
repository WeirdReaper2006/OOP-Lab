#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

// Constructors
Item::Item()
{
    name = "";
    description = "";
}

Item::Item(string name, string description)
{
    this->name = name;
    this->description = description;
}

// Destructor
Item::~Item()
{
}

// Getter and Setter Methods
string Item::getName()
{
    return name;
}

void Item::setName(string name)
{
    this->name = name;
}

string Item::getDescription()
{
    return description;
}

void Item::setDescription(string description)
{
    this->description = description;
}
