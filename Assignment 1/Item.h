#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string name;
    string description;

public:
    // Constructors
    Item();
    Item(string name, string description);

    // Destructor
    ~Item();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    string getDescription();
    void setDescription(string description);
};

#endif