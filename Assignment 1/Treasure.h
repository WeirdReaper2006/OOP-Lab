#ifndef TREASURE_H
#define TREASURE_H

#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Treasure : public Item
{
private:
    string name;
    string description;

public:
    // Constructors
    Treasure();
    Treasure(string name, string description);

    // Destructor
    ~Treasure();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    string getDescription();
    void setDescription(string description);

    int getValue();
    void setValue(int value);

    // General Method
    void display();
};

#endif