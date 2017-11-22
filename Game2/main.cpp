#include <SFML\Graphics.hpp>
#include "player.h"

int main(void) {

	sf::RenderWindow window(sf::VideoMode(600, 600), "Test!");
	Player player;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			player.control(event);
		}

		window.clear();
		window.draw(player);
		window.display();
	}


	return(0);
}