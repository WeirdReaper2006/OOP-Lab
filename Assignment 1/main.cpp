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
    Dungeon dungeon1 = Dungeon("Fiery Dungeon", 1, 3, 3, 1);
    cout << dungeon1.firstRoom->getName() << endl;
    cout << dungeon1.firstRoom->getDescription() << endl;
    return 0;
}