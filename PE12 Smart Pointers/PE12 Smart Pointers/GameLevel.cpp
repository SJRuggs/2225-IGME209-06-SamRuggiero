#include "GameLevel.h"
#include <iostream>

GameLevel::GameLevel()
{
	std::cout << "Constructing GameLevel" << std::endl;
	exitLoc = 0;
	levelNum = 0;
	treasure = new float[5];
}

GameLevel::~GameLevel()
{
	std::cout << "Destructing GameLevel" << std::endl;
	delete treasure;
}