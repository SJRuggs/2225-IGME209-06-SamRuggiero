#include "Gameplay.h"
#include <iostream>
#include <string>

Gameplay::Gameplay(std::string name)
{
	this->name = name;
}

void Gameplay::Update()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << this->name << ": " << (i + 1) * 10 << "% Complete" << std::endl;
	}
}