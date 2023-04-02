#include "Player.h"
#include <iostream>;

Player::Player(int xPosition, int yPosition) : MovableObject(xPosition, yPosition)
{
	inventoryIds = new int[3] {3, 9, 12};
}

/// <summary>
/// Display position and inventory
/// </summary>
void Player::Display()
{
	std::cout << "Player is at Position: (" << xPosition << ", " << yPosition << "). ";
	std::cout << "Its inventory contains: " << inventoryIds[0] << ", " << inventoryIds[1] << ", " << inventoryIds[2] << ", " << std::endl;
}

/// <summary>
/// Clean up memory and display function
/// </summary>
Player::~Player()
{
	std::cout << "Player Destructor" << std::endl;
	delete inventoryIds;
}