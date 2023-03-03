#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <Windows.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace sf;

void applyForces(b2Body* snake)
{
	// reads the key passed and applies the forces to the player to move
	b2Vec2 force;
	force.x = 0;
	force.y = 0;
	if (GetKeyState('A') & 0x8000)
	{
		// left
		force.x = -1;
		snake->ApplyForceToCenter(force, true);
	}
	if (GetKeyState('D') & 0x8000)
	{
		// right
		force.x = 1;
		snake->ApplyForceToCenter(force, true);
	}
	if (GetKeyState('W') & 0x8000)
	{
		// up
		force.y = 10;
		snake->ApplyForceToCenter(force, true);
	}
}

void display(b2Body* snake, b2Vec2* target, int score)
{
	// displays the position of a target and the player
	string snakeX = std::to_string(snake->GetPosition().x);
	string snakeY = std::to_string(snake->GetPosition().y);
	snakeX.resize(4, ' ');
	snakeY.resize(4, ' ');

	string targetX = std::to_string(target->x);
	string targetY = std::to_string(target->y);
	targetX.resize(4, ' ');
	targetY.resize(4, ' ');

	std::cout << "Score: " << score << "  |  Target: (" << targetX << ", " << targetY << ")  |  Snake: (" << snakeX << ", " << snakeY << ")" << endl;

}

void intro()
{
	// introduce the game to the user with instructions as to the keys to press
	std::cout << "*---------------------------*" << std::endl;
	std::cout << "| Let's play Gravity Snake! |" << std::endl;
	std::cout << "*---------------------------*" << std::endl;
	std::cout << "|         Controls:         |" << std::endl;
	std::cout << "|       W: jump             |" << std::endl;
	std::cout << "|       A: move left        |" << std::endl;
	std::cout << "|       D: move right       |" << std::endl;
	std::cout << "*---------------------------*" << std::endl;
	std::cout << "|    Press SPACE to Play    |" << std::endl;
	std::cout << "|    Press ESC to Escape    |" << std::endl;
	std::cout << "*---------------------------*" << std::endl;
	std::cout << std::endl << std::endl;
}

void moveTarget(b2Vec2* target)
{
	// moves the target to a new location
	target->x = (rand() % 100 - 50.0f) / 10;
	target->y = (rand() % 100 - 50.0f) / 10;
}

int main()
{
	// setup and intro
	srand(time(0));
	intro();
	Clock deltaClock;
	Time deltaTime;
	bool continuePlaying = false;
	int score = 0;

	// create world and bounds
	b2Vec2 gravity(0.0f, -5.0f);
	b2World world(gravity); b2BodyDef nBoundDef;

	b2BodyDef eBoundDef;
	b2BodyDef sBoundDef;
	b2BodyDef wBoundDef;
	nBoundDef.position.Set(0.0f, 6.0f);
	eBoundDef.position.Set(6.0f, 0.0f);
	sBoundDef.position.Set(0.0f, -6.0f);
	wBoundDef.position.Set(-6.0f, 0.0f);
	b2Body* nBound = world.CreateBody(&nBoundDef);
	b2Body* eBound = world.CreateBody(&eBoundDef);
	b2Body* sBound = world.CreateBody(&sBoundDef);
	b2Body* wBound = world.CreateBody(&wBoundDef);

	b2PolygonShape nBox;
	b2PolygonShape eBox;
	b2PolygonShape sBox;
	b2PolygonShape wBox;
	nBox.SetAsBox(6.0f, 0.5f);
	eBox.SetAsBox(0.5f, 6.0f);
	sBox.SetAsBox(6.0f, 0.5f);
	wBox.SetAsBox(0.5f, 6.0f);
	nBound->CreateFixture(&nBox, 0.0f);
	eBound->CreateFixture(&eBox, 0.0f);
	sBound->CreateFixture(&sBox, 0.0f);
	wBound->CreateFixture(&wBox, 0.0f);

	// create snake
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, -4.9f);
	b2Body* snake = world.CreateBody(&snakeDef);
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(0.5f, 0.5f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	snake->CreateFixture(&fixtureDef);

	// create target
	b2Vec2 target;
	moveTarget(&target);

	// start loop
	while (!(GetKeyState(32) & 0x8000)) /* start on space press */
	{
		if (GetKeyState(27) & 0x8000) { return 0; }
	}

	// game loop
	while (!(GetKeyState(27) & 0x8000)) /* quit on ESC press */
	{
		if (continuePlaying || score < 5)
		{
			// clock
			deltaTime = deltaClock.getElapsedTime();
			deltaClock.restart();

			// calculations
			applyForces(snake);
			world.Step(deltaTime.asSeconds(), 6, 2);
			if (sqrt(pow(snake->GetPosition().x - target.x, 2) + pow(snake->GetPosition().y - target.y, 2)) < 0.5f)
			{
				score++;
				moveTarget(&target);
			}

			// display
			display(snake, &target, score);
		}
		else
		{
			// win message
			std::cout << "*---------------------------------*" << std::endl;
			std::cout << "|      You win with 5 points!     |" << std::endl;
			std::cout << "*---------------------------------*" << std::endl;
			std::cout << "| Press SPACE to continue playing |" << std::endl;
			std::cout << "|        Press ESC to quit        |" << std::endl;
			std::cout << "*---------------------------------*" << std::endl;
			while (!(GetKeyState(32) & 0x8000) && !(GetKeyState(27) & 0x8000))
			if (GetKeyState(32) & 0x8000)
			{
				continuePlaying = true;
			}
		}
	}
	
	// quit
	return 0;
}