#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main() 
{
	// create window
	sf::RenderWindow window(sf::VideoMode(750, 350), "My window");

	sf::CircleShape triangle(80.f, 3);
	sf::CircleShape square(80.f, 4);
	sf::CircleShape pentagon(80.f, 5);
	triangle.setFillColor(sf::Color(100, 250, 50));
	square.setFillColor(sf::Color(250, 50, 100));
	pentagon.setFillColor(sf::Color(50, 100, 250));
	triangle.setPosition(100, 100);
	square.setPosition(300, 100);
	pentagon.setPosition(500, 100);

	// run while window is open
	while (window.isOpen()) 
	{
		// check events triggered since last loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// clear window
		window.clear(sf::Color::Black);

		// draw
		window.draw(triangle);
		window.draw(square);
		window.draw(pentagon);

		// end frame
		window.display();
	}

	// end when window closes
	return 0;
}