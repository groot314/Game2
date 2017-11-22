#include <SFML\Graphics.hpp>

class Asteroid : public sf::CircleShape{

public:
	Asteroid(sf::RenderWindow & window) : CircleShape(20){
		this->setFillColor(sf::Color::Green);

		//random position on outside
		int r = rand() % 4;
		if (r == 0) {//top
			this->setPosition(sf::Vector2f(rand() % window.getSize().x, 10));
		}
		else if (r == 1) {//bottom
			this->setPosition(sf::Vector2f(rand() % window.getSize().x, window.getSize().y + -10));
		}
		else if (r == 2) {//left
			this->setPosition(sf::Vector2f(0, rand() % window.getSize().y));
		}
		else {//right
			this->setPosition(sf::Vector2f(window.getSize().x + -10, rand() % window.getSize().y));
		}

	};

	//TODO: random movement passing through screen

private:


};