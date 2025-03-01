#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
using namespace std;

class Room
{
private:
    string name;
    string description;
    Room *next;
    Room *previous;

public:
    // Constructors
    Room();
    Room(string name, string description, Room *next, Room *previous);

    // Destructor
    ~Room();

    // Getter and Setter Methods
    string getName();
    void setName(string name);

    string getDescription();
    void setDescription(string description);

    Room *getNext();
    void setNext(Room *next);

    Room *getPrevious();
    void setPrevious(Room *previous);

    // General Methods
    void display();
};

#endif