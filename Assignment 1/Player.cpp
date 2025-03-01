#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Weapon.h"
using namespace std;

Player::Player()
{
    name = "Player";
    Health_Points = 100;
    Moves_Remaining = 10;
    rightHand = Weapon("Fists", "Melee", 5);
    Max_Health = 250;
    Inventory_Capacity = 5;
    currentRoom = nullptr;
}

Player::Player(string name, int Health_Points, int Moves_Remaining, int Max_Health, Room *currentRoom, int Inventory_Capacity)
{
    this->name = name;
    this->Health_Points = Health_Points;
    this->Moves_Remaining = Moves_Remaining;
    this->rightHand = Weapon("Fists", "Melee", 5);
    this->Max_Health = Max_Health;
    this->currentRoom = currentRoom;
    this->Inventory_Capacity = Inventory_Capacity;
    Item *Inventory = new Item[Inventory_Capacity];
    this->inventorySize = 0;
}

Player::~Player()
{
    delete[] Inventory;
}

// Getter and Setter Methods
string Player::getName()
{
    return name;
}

void Player::setName(string Name)
{
    name = Name;
}

Room *Player::getCurrentRoom()
{
    return currentRoom;
}

void Player::setCurrentRoom(Room *room)
{
    currentRoom = room;
}

int Player::getHealthPoints()
{
    return Health_Points;
}

void Player::setHealthPoints(int Health_Points)
{
    this->Health_Points = Health_Points;
}

int Player::getMovesRemaining()
{
    return Moves_Remaining;
}

void Player::setMovesRemaining(int Moves_Remaining)
{
    this->Moves_Remaining = Moves_Remaining;
}

Item Player::getInventory(int index)
{
    return Inventory[index];
}

// General Methods
void Player::DisplayInventory(Item Inventory[])
{
    cout << "Inventory: " << endl;
    for (int i = 0; i < inventorySize; i++)
    {
        cout << Inventory[i].getName() << endl;
    }
}

void Player::DisplayStats()
{
    cout << "Name: " << name << endl;
    cout << "Health Points: " << Health_Points << endl;
    cout << "Moves Remaining: " << Moves_Remaining << endl;
    cout << "Max Health: " << Max_Health << endl;
    cout << "Inventory Capacity: " << Inventory_Capacity << endl;
}

void Player::Attack(Enemy *enemy)
{
    enemy->setHealth(enemy->getHealth() - rightHand.getDamage());
    cout << "You attacked the enemy with " << rightHand.getName() << " for " << rightHand.getDamage() << " damage." << endl;
}

void Player::PickUpItem(Item item)
{
    if (inventorySize < Inventory_Capacity)
    {
        Inventory[inventorySize] = item;
        inventorySize++;
    }
    else
    {
        cout << "Inventory is full!" << endl;
    }
}

void Player::DropItem(Item item)
{
    for (int i = 0; i < inventorySize; i++)
    {
        if (Inventory[i].getName() == item.getName())
        {
            // Shift all elements after index i one position to the left
            for (int j = i; j < inventorySize - 1; j++)
            {
                Inventory[j] = Inventory[j + 1];
            }

            // Decrease size of inventory
            inventorySize--;
            break; // Exit loop after removing the item
        }
    }
}

void Player::UseItem(Item item)
{
    if (item.getName() == "Health Potion")
    {
        Health_Points += 50;
    }
    else if (item.getName() == "Stamina Potion")
    {
        Moves_Remaining += 10;
    }
}

void Player::Move(string direction)
{
    if (direction == "n")
    {
        currentRoom = currentRoom->getNext();
    }
    else if (direction == "s")
    {
        currentRoom = currentRoom->getPrevious();
    }
}