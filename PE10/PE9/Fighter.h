#pragma once
#include <string>
#include "Player.h"
using namespace std;

class Fighter :
    public Player
{
public:
    Fighter();
    Fighter(string name, string weaponSkill, int str, int dex, int con);
    void printFighter();
private:
    string weaponSkill;
};

