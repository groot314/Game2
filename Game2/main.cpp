#include <SFML\Graphics.hpp>
#include <vector>
#include "player.h"
#include "asteroid.h"

int main(void) {

	srand(time(NULL));//random

	sf::RenderWindow window(sf::VideoMode(960, 720), "Test!");
	Player player;
	Asteroid asteroid(window);

	std::vector<Asteroid*> asteroidVec;

	for (int i = 0; i < 3; i++) {
		Asteroid *newAsteroid = new Asteroid(window);
		asteroidVec.push_back(newAsteroid);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			

		}
		player.control(event);//player controls
		for (int i = 0; i < asteroidVec.size(); i++) {
			asteroidVec[i]->movement();//asteroid movement
			asteroidVec[i]->checkCollision(player, window);
			asteroidVec[i]->checkBounds(window);
		}

		window.clear();
		window.draw(player);
		for (int i = 0; i < asteroidVec.size(); i++) {
			window.draw(*asteroidVec[i]);
		}
		window.display();
	}


	return(0);
}