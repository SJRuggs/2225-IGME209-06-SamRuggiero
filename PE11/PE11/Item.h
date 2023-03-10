#pragma once
#include <string>
struct Item
{
	Item();
	void print();
private:
	std::string name;
	int damage;
	float weight;
};

