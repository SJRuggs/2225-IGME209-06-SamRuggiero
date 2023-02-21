#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player()
{
	this->name = "Unknown";
	this->str = 10;
	this->dex = 10;
	this->con = 10;
}

Player::Player(string name, int str, int dex, int con)
{
	this->name = name;
	this->str = str;
	this->dex = dex;
	this->con = con;
}

void Player::printPlayer()
{
	cout << "Name:         " << this->name << endl;
	cout << "Strength:     " << this->str << endl;
	cout << "Dexterity:    " << this->dex << endl;
	cout << "Constitution: " << this->con << endl;
}