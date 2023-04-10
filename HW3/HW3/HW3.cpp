#include <iostream>
#include <GravitySnake.h>
#include <iomanip>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
using namespace std;

/* GravitySnake.h is the header file for a dynamically linked library (dll) called
* GravitySnake.dll. The GravitySnake library is a set of functions that satisfy the
* requirements of HW2 - Gravity Snake. In order to allow you to complete HW3 without
* the need for a done version of HW2, this DLL has been created. Using it's functions,
* you can implement HW3 without the HW2 code. A full breakdown of it's functions
* can be found in the homework document.
*/

// CREATIVE PORTION:
// I added a trailing snake body that follows the player around and grows larger as they eat apples.

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	//Sets the possible bounds of where the target can spawn (-4, -4) to (4, 4) here.
	//This function is from the DLL.
	setTargetBounds(-4.0f, 4.0f, -4.0f, 4.0f);

	//Create the physics world, and all the objects. Return a pointer to the snake body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	createFloor(b2Vec2(0.0f, -6.0f), 10.0f, 1.0f);
	createCeiling(b2Vec2(0.0f, 6.0f), 10.0f, 1.0f);
	createLeftWall(b2Vec2(-6.0f, 0.0f), 1.0f, 10.0f);
	createRightWall(b2Vec2(6.0f, 0.0f), 1.0f, 10.0f);
	b2Body* snake = createSnake(b2Vec2(0.0f, 0.0f), 0.5f, 0.5f);

	int targetsCollected = 0;
	int lastTargetsCollected = 0;
	float tempDeltaTime = 0;


	/* The following block of code is from the SFML drawing tutorial. To accomplish
	* the requirements of HW3, you will need to take the code above and modify it
	* to work within the code provided below. Rather than using the display() method
	* like above, you will need to render shapes to represent the walls, snake, and
	* target.
	* 
	* Note, you should be creating your SFML shapes BEFORE the while (window.isOpen())
	* loop, then render them WITHIN the loop. Additionally, the while(targetsCollected < 2)
	* loop from up above will need to be turned into an if statement so that it doesn't
	* block SFML from rendering new frames to the window.
	*/

	
	
	sf::RenderWindow window(sf::VideoMode(900, 900), "Gravity Snake");

	// define shapes
	sf::CircleShape snakeSFML(10.0f);
	sf::CircleShape target(10.0f);
	sf::RectangleShape floor(sf::Vector2f(820.0f, 10.0f));
	sf::RectangleShape ceiling(sf::Vector2f(820.0f, 10.0f));
	sf::RectangleShape leftWall(sf::Vector2f(10.0f, 820.0f));
	sf::RectangleShape rightWall(sf::Vector2f(10.0f, 830.0f));

	// define positions
	floor.setPosition(45.0f, 865.0f);
	ceiling.setPosition(45.0f, 45.0f);
	leftWall.setPosition(45.0f, 45.0f);
	rightWall.setPosition(865.0f, 45.0f);

	// define colors
	snakeSFML.setFillColor(sf::Color::Green);
	target.setFillColor(sf::Color::Blue);
	floor.setFillColor(sf::Color::Red);
	ceiling.setFillColor(sf::Color::Red);
	leftWall.setFillColor(sf::Color::Red);
	rightWall.setFillColor(sf::Color::Red);

	// snake trailing
	vector<sf::CircleShape> trail;
	trail.push_back(snakeSFML);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		// clear the window with black color
		window.clear(sf::Color::Black);

		// update world
		float deltaTime = updateWorldAndReturnDeltaTime();
		handleInput();
		if (checkCollisionAndMoveTarget(0.5f))
		{
			targetsCollected++;
		}
		target.setPosition(B2DtoSFML(getTargetPosition())[0], B2DtoSFML(getTargetPosition())[1]);
		trail[0].setPosition(B2DtoSFML(snake->GetPosition())[0], B2DtoSFML(snake->GetPosition())[1]);

		// update snake trail
		if (tempDeltaTime > 0.1f)
		{
			tempDeltaTime = 0;
			if (targetsCollected > lastTargetsCollected)
			{
				lastTargetsCollected = targetsCollected;
				sf::CircleShape newSnakeCircle(10.0f);
				newSnakeCircle.setFillColor(sf::Color::Green);
				trail.push_back(newSnakeCircle);
			}
			for (int i = trail.size() - 1; i > 0; i--)
			{
				trail[i].setPosition(trail[i - 1].getPosition().x, trail[i - 1].getPosition().y);
			}
		}
		else
		{
			tempDeltaTime += deltaTime;
		}

		// draw everything here...
		window.draw(target);
		window.draw(floor);
		window.draw(ceiling);
		window.draw(leftWall);
		window.draw(rightWall);
		for (int i = 0; i < trail.size(); i++)
		{
			window.draw(trail[i]);
		}

		// end the current frame
		window.display();
	}
}