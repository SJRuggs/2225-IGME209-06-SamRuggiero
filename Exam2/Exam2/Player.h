#pragma once
#include "MovableObject.h"
class Player : public MovableObject
{
public:
	Player(int xPosition, int yPosition);
	void Display() override;
	~Player();
private:
	int* inventoryIds;
};

