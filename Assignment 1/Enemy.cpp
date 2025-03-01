#include <iostream>
#include <string>
#include "Enemy.h"
using namespace std;

// Constructors
Enemy::Enemy()
{
    name = "Default";
    attack = 0;
    health = 0;
    isAlive = true;
    cout << "Enemy " << name << " has been created." << endl;
}

Enemy::Enemy(string name, int attack, int health)
{
    this->name = name;
    this->attack = attack;
    this->health = health;
    this->isAlive = true;
    cout << "Enemy " << name << " has been created." << endl;
}
