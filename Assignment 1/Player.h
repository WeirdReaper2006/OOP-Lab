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
    int Stamina_Points;
    Weapon rightHand;
    int Moves_Remaining;
    int Max_Health;
    int Inventory_Capacity;
    vector<Item> Inventory[5];
    Room *currentRoom;

public:
    // Constructors
    Player();
    Player(string name, int Health_Points, int Attack_Points, int Stamina_Points, int Moves_Remaining, int Max_Health, Room *currentRoom, int Inventory_Capacity);

    // Destructor
    ~Player();

    // Getter and Setter Methods
    string getName();
    void setName(string Name);

    Room *getCurrentRoom();
    void setCurrentRoom(Room *room);

    int getHealthPoints();
    void setHealthPoints(int Health_Points);

    int getAttackPoints();
    void setAttackPoints(int Attack_Points);

    int getStaminaPoints();
    void setStaminaPoints(int Stamina_Points);

    int getMovesRemaining();
    void setMovesRemaining(int Moves_Remaining);

    vector<Item> getInventory(int index);

    // General Methods
    void DisplayInventory(vector<Item> Inventory);
    void DisplayStats();
    void Attack(Enemy *enemy);
    void PickUpItem(Item item);
    void DropItem(Item item);
    void UseItem(Item item);
    void MoveForward(string direction);
    void MoveBackward(string direction);
};

#endif