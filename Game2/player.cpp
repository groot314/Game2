#include "player.h"

void Player::control(sf::Event & event)
{
	double speed = .15;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			this->move(sf::Vector2f(0, -1*speed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			this->move(sf::Vector2f(1*speed, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			this->move(sf::Vector2f(0, 1*speed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			this->move(sf::Vector2f(-1*speed, 0));
		}
}
