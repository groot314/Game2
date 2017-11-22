#include "player.h"

void Player::control(sf::Event event)
{

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			this->move(sf::Vector2f(0, -7));
		}
		if (event.key.code == sf::Keyboard::Right) {
			this->move(sf::Vector2f(7, 0));
		}
		if (event.key.code == sf::Keyboard::Down) {
			this->move(sf::Vector2f(0, 7));
		}
		if (event.key.code == sf::Keyboard::Left) {
			this->move(sf::Vector2f(-7, 0));
		}
	}
}
