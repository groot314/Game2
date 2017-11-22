#include <SFML\Graphics.hpp>

class Player : public sf::RectangleShape {

public:
	Player() {
		this->setSize(sf::Vector2f(100, 100));
		this->setFillColor(sf::Color::Blue);
		this->setPosition(sf::Vector2f(300, 300));
	}

	void control(sf::Event event);

private:
};
