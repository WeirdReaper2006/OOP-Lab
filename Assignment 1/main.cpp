#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Room.h"
#include "Weapon.h"
#include "Treasure.h"
using namespace std;

int main()
{
    Dungeon dungeon1 = Dungeon("Fiery Dungeon", 3, 3, 3);
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Player player1 = Player(playerName, 100, 10, 200, dungeon1.firstRoom, 10);
    bool run = true;
    cout << "Welcome to the " << dungeon1.getName() << "!" << endl;

    while (run)
    {
        cout << "You are in " << player1.getCurrentRoom()->getName() << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Move to another room" << endl;
        cout << "2. Attack the Enemy in Room" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            player1.setMovesRemaining(player1.getMovesRemaining() - 1);
            string direction;
            cout << "Enter direction (North or South)(Just enter the first letter of the direction you want to go to): ";
            cin >> direction;
            while (direction != "n" && direction != "s")
            {
                if (player1.getCurrentRoom()->getEnemy() != nullptr)
                {
                    cout << "You cannot move to another room without defeating the enemy in the current room." << endl;
                    direction = ""; // Reset direction to stay in the loop
                }
                else
                {
                    cout << "Invalid direction. Please enter n or s: ";
                }
                cin >> direction;
            }
            player1.Move(direction);
            player1.DisplayStats();
            cout << "You have moved to " << player1.getCurrentRoom()->getName() << endl;
            break;
        }
        case 2:
        {
            player1.setMovesRemaining(player1.getMovesRemaining() - 1);
            if (player1.getCurrentRoom()->getEnemy() != nullptr)
            {
                player1.Attack(player1.getCurrentRoom()->getEnemy());
                player1.setHealthPoints(player1.getHealthPoints() - player1.getCurrentRoom()->getEnemy()->getAttack());
                if (player1.getHealthPoints() <= 0)
                {
                    cout << "You have been defeated by the enemy" << endl;
                    run = false;
                }
                else if (player1.getCurrentRoom()->getEnemy()->getHealth() <= 0)
                {
                    cout << "You have defeated the enemy" << endl;
                    player1.getCurrentRoom()->setEnemy(nullptr);
                }
            }
            else
            {
                cout << "There is no enemy in this room" << endl;
            }
            break;
        }
        case 3:
        {
            run = false;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
        if (player1.getMovesRemaining() == 0)
        {
            cout << "You have run out of moves" << endl;
            cout << "Game Over" << endl;
            run = false;
        }
    }
    return 0;
}