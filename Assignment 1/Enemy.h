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
    ~Enemy();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    int getAttack();
    void setAttack(int attack);

    int getHealth();
    void setHealth(int health);

    bool getIsAlive();
    void setIsAlive(bool isAlive);

    // General Methods
    void display();
};

#endif