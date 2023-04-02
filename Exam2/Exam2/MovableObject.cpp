#include "MovableObject.h"
#include <iostream>;

MovableObject::MovableObject(int xPosition, int yPosition)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
}

/// <summary>
/// Display position
/// </summary>
void MovableObject::Display()
{
	std::cout << "Position: (" << xPosition << ", " << yPosition << ")" << std::endl;
}

MovableObject::~MovableObject()
{
	std::cout << "MovableObject Destructor" << std::endl;
}