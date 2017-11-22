#include <SFML\Graphics.hpp>

class Asteroid : public sf::CircleShape{

public:
	Asteroid(sf::RenderWindow & window) : CircleShape(20){
		this->setFillColor(sf::Color::Green);

		setPos(window);


	};

	void movement() {
		this->move(xMovements*.075, yMovements*.075);
	}

	bool checkCollision(Player player, sf::RenderWindow & window) {
		if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
			this->setPos(window);

			return true;
		}

		return false;
	}

private:
	void setPos(sf::RenderWindow & window) {
		yMovements = 0;
		xMovements = 0;

		//random position on outside
		int r = rand() % 4;
		if (r == 0) {//top
			this->setPosition(sf::Vector2f(rand() % window.getSize().x, 10));
			yMovements = 1;
		}
		else if (r == 1) {//bottom
			this->setPosition(sf::Vector2f(rand() % window.getSize().x, window.getSize().y + -10));
			yMovements = -1;
		}
		else if (r == 2) {//left
			this->setPosition(sf::Vector2f(0, rand() % window.getSize().y));
			xMovements = 1;
		}
		else {//right
			this->setPosition(sf::Vector2f(window.getSize().x + -10, rand() % window.getSize().y));
			xMovements = -1;
		}
	}
	int xMovements;
	int yMovements;

};