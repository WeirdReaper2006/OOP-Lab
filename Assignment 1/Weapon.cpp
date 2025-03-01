#include <iostream>
#include <string>
#include "Weapon.h"
#include "Item.h"
using namespace std;

// Constructors
Weapon::Weapon()
{
    name = "None";
    damage = 0;
}

Weapon::Weapon(string name, string description, int damage)
{
    this->name = name;
    this->description = description;
    this->damage = damage;
}

// Destructor
Weapon::~Weapon()
{
}

// Getter and Setter Methods
string Weapon::getName()
{
    return name;
}

void Weapon::setName(string Name)
{
    name = Name;
}

string Weapon::getDescription()
{
    return description;
}

void Weapon::setDescription(string Description)
{
    description = Description;
}

int Weapon::getDamage()
{
    return damage;
}

void Weapon::setDamage(int Damage)
{
    damage = Damage;
}

// General Methods
void Weapon::DisplayStats()
{
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Damage: " << damage << endl;
}