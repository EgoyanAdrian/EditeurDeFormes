#include <iostream>
#include <SFML/Graphics.hpp>
#include "DrawablePoint.hpp"

int main() {
	
	int X, Y;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Editeur de Formes", sf::Style::Default);

	DrawablePoint pointA(10, 20, sf::Color::Black, sf::Color::Blue, sf::Color::Red);
	std::cout << "Hello World!" << std::endl;

	while(window.isOpen()) {
		window.clear(sf::Color::White);

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::MouseMoved) {
				X = event.mouseMove.x;
				Y = event.mouseMove.y;
			}
			if(event.type == sf::Event::MouseButtonPressed) {
				pointA.setSelected(pointA.isOver(X, Y));
			}
			if(event.type == sf::Event::MouseButtonReleased) {
				pointA.setSelected(false);
			}
		}

		pointA.update(X, Y);
		pointA.draw(window, pointA.isOver(X, Y));
		window.display();
	}

	return 0;
}
