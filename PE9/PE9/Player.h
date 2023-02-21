#pragma once
#include <string>
using namespace std;

class Player
{
public:
	Player();
	Player(string name, int str, int dex, int con);
	void printPlayer();
private: 
	string name;
	int str;
	int dex;
	int con;
};