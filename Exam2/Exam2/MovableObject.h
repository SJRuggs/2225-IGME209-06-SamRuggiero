#pragma once
class MovableObject
{
public:
	int xPosition;
	int yPosition;
	MovableObject(int xPosition, int yPosition);
	virtual void Display();
	virtual ~MovableObject();
};

