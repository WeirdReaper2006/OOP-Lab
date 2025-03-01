#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon
{
private:
    string name;
    string description;
    int damage;

public:
    // Constructors
    Weapon();
    Weapon(string name, string description, int damage);

    // Destructor
    ~Weapon();

    // Getter and Setter Methods
    string getName();
    void setName(string Name);

    string getDescription();
    void setDescription(string Description);

    int getDamage();
    void setDamage(int Damage);

    // General Methods
    void DisplayStats();
};

#endif