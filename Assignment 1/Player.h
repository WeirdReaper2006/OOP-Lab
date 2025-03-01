#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Weapon.h"
using namespace std;

class Player
{
private:
    string name;
    int Health_Points;
    Weapon rightHand;
    int Moves_Remaining;
    int Max_Health;
    int Inventory_Capacity; // Maximum number of items player can carry
    Item *Inventory;        // Pointer to dynamic array
    int inventorySize;      // Current number of items
    Room *currentRoom;

public:
    // Constructors
    Player();
    Player(string name, int Health_Points, int Moves_Remaining, int Max_Health, Room *currentRoom, int Inventory_Capacity);

    // Destructor
    ~Player();

    // Getter and Setter Methods
    string getName();
    void setName(string Name);

    Room *getCurrentRoom();
    void setCurrentRoom(Room *room);

    int getHealthPoints();
    void setHealthPoints(int Health_Points);

    int getMovesRemaining();
    void setMovesRemaining(int Moves_Remaining);

    Item getInventory(int index);

    // General Methods
    void DisplayInventory(Item Inventory[]);
    void DisplayStats();
    void Attack(Enemy *enemy);
    void PickUpItem(Item item);
    void DropItem(Item item);
    void UseItem(Item item);
    void Move(string direction);
};

#endif