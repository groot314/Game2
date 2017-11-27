#include <SFML\Graphics.hpp>

class Asteroid : public sf::CircleShape{

public:
	Asteroid(sf::RenderWindow & window) : CircleShape(20){
		this->setFillColor(sf::Color::Red);

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

	bool checkBounds(sf::RenderWindow & window) {
		int bound = 50;

		if (this->getPosition().x < -bound) {//left
			this->setPos(window);
			return true;
		}
		if (this->getPosition().y < -bound) {//top
			this->setPos(window);
			return true;
		}
		if (this->getPosition().x > 50 + window.getSize().x) {//right
			this->setPos(window);
			return true;
		}
		if (this->getPosition().y > 50 + window.getSize().y) {//bottom
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