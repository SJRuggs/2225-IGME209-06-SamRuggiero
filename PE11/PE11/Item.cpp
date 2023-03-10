#include "Item.h"
#include <string>
#include <iostream>

Item::Item()
{
	this->name = "The Nameless Thing";
	this->damage = 0;
	this->weight = 1.0f;
}
void Item::print()
{
	std::cout << "Name:   " << this->name << std::endl;
	std::cout << "Damage: " << this->damage << std::endl;
	std::cout << "Weight: " << this->weight<< std::endl;
}