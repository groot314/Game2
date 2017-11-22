#include <SFML\Graphics.hpp>

class Asteroid : public sf::CircleShape{

public:
	Asteroid() {
		this->setRadius(30.f);
		this->setFillColor(sf::Color::Green);
	};


private:


};