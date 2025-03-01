#include <iostream>
#include <string>
#include "Enemy.h"
using namespace std;

// Constructors
Enemy::Enemy()
{
    name = "Goblin";
    attack = 7;
    health = 15;
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

// Destructor
Enemy::~Enemy()
{
    cout << "Enemy " << name << " has been destroyed." << endl;
}

// Getter and Setter Methods
string Enemy::getName()
{
    return name;
}

void Enemy::setName(string name)
{
    this->name = name;
}

int Enemy::getAttack()
{
    return attack;
}

void Enemy::setAttack(int attack)
{
    this->attack = attack;
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::setHealth(int health)
{
    this->health = health;
}

bool Enemy::getIsAlive()
{
    return isAlive;
}

void Enemy::setIsAlive(bool isAlive)
{
    this->isAlive = isAlive;
}

// General Methods
void Enemy::display()
{
    cout << "Enemy Name: " << name << endl;
    cout << "Enemy Attack: " << attack << endl;
    cout << "Enemy Health: " << health << endl;
    cout << "Enemy Status: " << (isAlive ? "Alive" : "Dead") << endl;
}