#include <SFML/Graphics.hpp>
#include "PointsDrawable.hpp"
#include "ShapesDrawable.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Editeur de Formes", sf::Style::Default);
	PointsDrawable gestPoint;
	Point * pointSelect = nullptr;

	ShapesDrawable gestShape;

	uint X, Y, i = 0, j = 0, distX, distY;
	while(window.isOpen()) {
		window.clear(sf::Color::White);

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseMoved) {
				X = event.mouseMove.x;
				Y = event.mouseMove.y;
				
				if(pointSelect != nullptr) {
					pointSelect->setX(X - distX);
					pointSelect->setY(Y - distY);
				}

			}

			if(event.type == sf::Event::MouseButtonPressed) {
				pointSelect = gestPoint.isOver(X, Y);

				if(pointSelect != nullptr) {
					pointSelect->setSelected(true);
					distX = X - pointSelect->getX();
					distY = Y - pointSelect->getY();
				}
			}

			if(event.type == sf::Event::MouseButtonReleased) {
				if(pointSelect != nullptr) {
					pointSelect->setSelected(false);
					pointSelect = nullptr;	
				}
			}

			if(event.type == sf::Event::KeyPressed) {
				switch(event.key.code) {
					case sf::Keyboard::P:
					 		i = i + 10;
							gestPoint.add(new Point(i, 10));
						break;
					case sf::Keyboard::F:
							j = j + 10;
							gestShape.add(new Shape<sf::RenderWindow, sf::Color>(j, 40, sf::Color::Black));
						break;
					case sf::Keyboard::Delete:
							if(pointSelect != nullptr)
								gestPoint.remove();
						break;
					default:
						break;
				}
			}
		}

		gestShape.draw(window, X, Y);
		gestPoint.draw(window, X, Y);
		window.display();
	}

	return 0;
}