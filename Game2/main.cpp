#include <SFML\Graphics.hpp>

int main(void) {

	sf::RenderWindow window(sf::VideoMode(600, 600), "Test!");
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(sf::Vector2f(300, 300));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					shape.move(sf::Vector2f(0, -7));
				}
				if (event.key.code == sf::Keyboard::Right) {
					shape.move(sf::Vector2f(7, 0));
				}
				if (event.key.code == sf::Keyboard::Down) {
					shape.move(sf::Vector2f(0, 7));
				}
				if (event.key.code == sf::Keyboard::Left) {
					shape.move(sf::Vector2f(-7, 0));
				}
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return(0);
}