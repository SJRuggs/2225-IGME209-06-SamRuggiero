#include "Functions.h"
#include <iostream>
#include <GravitySnake.h>
#include <conio.h>
using namespace std;

void display(b2Body* snake)
{
	cout << "Target: (" << getTargetPosition().x << ", " << getTargetPosition().y << ")  ";
	cout << "Snake: (" << snake->GetPosition().x << ", " << snake->GetPosition().y << ")  ";
	cout << "TargetSMFL: (" << B2DtoSFML(getTargetPosition())[0] << ", " << B2DtoSFML(getTargetPosition())[1] << ")  ";
	cout << "SnakeSMFL: (" << B2DtoSFML(snake->GetPosition())[0] << ", " << B2DtoSFML(snake->GetPosition())[1] << ")  " << endl;

}

void handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyForceToSnake(b2Vec2(0.0f, 100000.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForceToSnake(b2Vec2(-10000.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForceToSnake(b2Vec2(10000.0f, 0.0f));
	}
}

float* B2DtoSFML(b2Vec2 b2d)
{
	float arr[2] = {90.0f * (b2d.x + 5.0f), 90.0f * (b2d.y * -1.0f + 5.0f)};
	return arr;
}