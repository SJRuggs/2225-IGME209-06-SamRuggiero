#include <iostream>
#include <vector>
#include "Axe.h"
#include "Bow.h"
#include "Spear.h"
#include "Sword.h"
using namespace std;

int main()
{
    vector<Item*> inventory;
    inventory.push_back(new Axe());
    inventory.push_back(new Bow());
    inventory.push_back(new Spear());
    inventory.push_back(new Sword());
    for (Item* item : inventory)
    {
        item->print();
        cout << endl;
        delete item;
    }
    inventory.clear();
}