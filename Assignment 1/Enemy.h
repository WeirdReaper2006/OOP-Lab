#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
using namespace std;

class Enemy
{
private:
    string name;
    int attack;
    int health;
    bool isAlive;

public:
    // Constructors
    Enemy();
    Enemy(string name, int damage, int health);

    // Destructor
    virtual ~Enemy() = 0;

    // Getter and Setter Methods
    virtual string getName() = 0;
    virtual void setName(string name) = 0;

    virtual int getAttack() = 0;
    virtual void setAttack(int attack) = 0;

    virtual int getHealth() = 0;
    virtual void setHealth(int health) = 0;

    virtual bool getIsAlive() = 0;
    virtual void setIsAlive(bool isAlive) = 0;
};

#endif