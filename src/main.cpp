#include <SFML/Graphics.hpp>
#include "PointDrawable.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Salut ca va", sf::Style::Default);
	PointDrawable pointA(10, 20, sf::Color::Black);
	PointDrawable pointB(pointA);

	uint X, Y;
	uint distX, distY;
	while(window.isOpen()) {
		window.clear(sf::Color::White);

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseMoved) {
				X = event.mouseMove.x;
				Y = event.mouseMove.y;
			}

			if(event.type == sf::Event::MouseButtonPressed) {
				pointA.setSel(pointA.isOver(X, Y));
				distX = X - pointA.getX();
				distY = Y - pointA.getY();
			}

			if(event.type == sf::Event::MouseButtonReleased) {
				pointA.setSel(false);
			}
		}

		pointA.update(X - distX, Y - distY);
		pointA.draw(window, pointA.isOver(X, Y));
		window.display();
	}

	return 0;
}