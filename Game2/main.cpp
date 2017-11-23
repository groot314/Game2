#include <SFML\Graphics.hpp>
#include "player.h"
#include "asteroid.h"

int main(void) {

	srand(time(NULL));//random

	sf::RenderWindow window(sf::VideoMode(960, 720), "Test!");
	Player player;
	Asteroid asteroid(window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			player.control(event);//player controls

		}
		asteroid.movement();//asteroid movement
		asteroid.checkCollision(player,window);
		asteroid.checkBounds(window);

		window.clear();
		window.draw(player);
		window.draw(asteroid);
		window.display();
	}


	return(0);
}