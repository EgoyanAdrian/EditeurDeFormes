#include <SFML/Graphics.hpp>
#include "PointDrawable.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Salut ca va", sf::Style::Default);
	PointDrawable pointA(10, 20, sf::Color::Black);
	PointDrawable pointB(pointA);

	while(window.isOpen()) {
		window.clear(sf::Color::White);

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		pointA.draw(window, pointA.isOver(12, 30));
		window.display();
	}

	return 0;
}