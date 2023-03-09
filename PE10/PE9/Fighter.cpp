#include "Fighter.h"
#include <iostream>
#include <string>
using namespace std;

Fighter::Fighter()
{
	weaponSkill = "Unarmed";
}

Fighter::Fighter(string name, string weaponSkill, int str, int dex, int con) : Player(name, str, dex, con)
{
	this->weaponSkill = weaponSkill;
}

void Fighter::printFighter()
{
	printPlayer();
	cout << "Weapon Skill: " << this->weaponSkill << endl;
}