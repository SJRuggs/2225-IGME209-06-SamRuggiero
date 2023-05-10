#include "Player.h"
#include <iostream>
#include <string>

/// <summary>
/// Paramaterized constructor that accepts a string for a name.
/// </summary>
Player::Player(std::string name)
{
	this->name = name;
	this->invSize = 3;
	this->inventory = new int[3] {3, 5, 8};
}

/// <summary>
/// Takes in a new item id, and attempts to save it to a particular slot in the inventory.
/// If the index is out of range, an error is printed to the console.
/// </summary>
void Player::SwapItem(int _itemId, int _slot)
{
	if (this->invSize > _slot)
	{
		this->inventory[_slot] = _itemId;
	}
	else
	{
		std::cout << "Attempted to put item in invalid slot!" << std::endl;
	}
}

/// <summary>
/// Prints the player's inventory to the console.
/// </summary>
void Player::PrintInventory()
{
	std::cout << this->name << "'s Inventory: ";
	for (int i = 0; i < this->invSize; i++)
	{
		std::cout << this->inventory[i] << ", ";
	}
	std::cout << std::endl;
}

/// <summary>
/// Sets the player's name equal to _newName.
/// </summary>
void Player::ChangeName(std::string _newName)
{
	this->name = _newName;
}

/// <summary>
/// Copy constructor
/// </summary>
/// <returns></returns>
Player* Player::Copy()
{
	Player* newPlayer = new Player(this->name);
	for (int i = 0; i < this->invSize; i++)
	{
		newPlayer->inventory[i] = this->inventory[i];
	}
	return newPlayer;
}

/// <summary>
/// Copy assignment operator
/// </summary>
void Player::CopyAssignmentOp(Player other)
{
	this->name = other.name;
	this->invSize = other.invSize;
	this->inventory = other.inventory;
}