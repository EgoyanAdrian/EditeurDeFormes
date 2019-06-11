#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "PointsDrawable.hpp"
#include "ShapesDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "SquareDrawable.hpp"
#include "CircleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "menuInfo.hpp"
#include "Menu.hpp"


int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Editeur de Formes", sf::Style::Default);
	sf::RenderWindow window2(sf::VideoMode(31, 100), "Outils", sf::Style::Default);

	uint screenSize=1000;
	PointsDrawable gestPoint;
	ShapesDrawable gestShape;

	Point * pointSelect = nullptr;
	Shape<sf::RenderWindow, sf::Color> * shapeSelect = nullptr;
	Shape<sf::RenderWindow,sf::Color> * lastShapeSelect = nullptr;
	
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}

	uint X, Y, i = 0, j = 0, distX, distY;
	while(window.isOpen()) {
		bool isPushLeft=false; //variable pour savoir si le bouton gauche de la souris et enfoncer)
		window.clear(sf::Color::White);

		/*while(window2.isOpen()) {
			window2.clear(sf::Color::White);

			sf::Event event2;
			while(window2.pollEvent(event2)) {
				if(event2.type == sf::Event::Closed)
					window2.close();
			}
		}*/

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseMoved) {
				X = event.mouseMove.x;//coordonner X de la sourie
				Y = event.mouseMove.y;//coordonner Y de la sourie
				
				if(pointSelect != nullptr) {
					pointSelect->setX(X - distX);
					pointSelect->setY(Y - distY);
				}

				if(shapeSelect != nullptr) {
					shapeSelect->setAnchorXY(X - distX, Y - distY);
				}

			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				isPushLeft=true;
			}

			if(event.type == sf::Event::MouseButtonPressed) {
				pointSelect = gestPoint.isOver(X, Y);
				shapeSelect = gestShape.isOver(X, Y);

				if(pointSelect != nullptr) {
					pointSelect->setSelected(true);
					distX = X - pointSelect->getX();
					distY = Y - pointSelect->getY();
				}

				if(shapeSelect != nullptr) {
					shapeSelect->setSelected(true);
					distX = X - shapeSelect->getAnchor()->getX();//difference enter X de la forme et du X de la sourie
					distY = Y - shapeSelect->getAnchor()->getY();//difference entre Y de la forme et du Y de la sourie
				}
			}
			

			if(event.type == sf::Event::MouseButtonReleased) {
				if(pointSelect != nullptr) {
					pointSelect->setSelected(false);
					pointSelect = nullptr;	
				}

				if(shapeSelect != nullptr) {
					shapeSelect->setSelected(false);
					shapeSelect = nullptr;
				}
			}

			if(event.type == sf::Event::KeyPressed) {
				switch(event.key.code) {
					case sf::Keyboard::P:
					 		i = i + 10;
							gestPoint.add(new Point(i, 200));
						break;
					case sf::Keyboard::R:
							j = j + 10;
							gestShape.add(new RectangleDrawable(j, 280, 10, 20, sf::Color::Black));
						break;
					case sf::Keyboard::S:
							j = j + 10;
							gestShape.add(new SquareDrawable(j, 260, 10, sf::Color::Yellow));
						break;
					case sf::Keyboard::C:
							j = j + 10;
							gestShape.add(new CircleDrawable(j, 220, 5, sf::Color::Green));
						break;
					case sf::Keyboard::E:
							j = j + 10;
							gestShape.add(new EllipseDrawable(j, 240, 10, 5, sf::Color::Black));
						break;
					case sf::Keyboard::T:
							j = j + 10;
							Point * pointA; pointA = new Point(j, 260);
							Point * pointB; pointB = new Point(j + 20, 280);
							Point * pointC; pointC = new Point(j - 5, 300);
							gestPoint.add(pointA);
							gestPoint.add(pointB);
							gestPoint.add(pointC);
							gestShape.add(new TriangleDrawable(pointA, pointB, pointC, sf::Color::Green));
						break;
					case sf::Keyboard::F:
							if(shapeSelect != nullptr) {
								shapeSelect->setFilled(!shapeSelect->getFilled());
							}
						break;
					case sf::Keyboard::Add:
							if(shapeSelect != nullptr) {
								shapeSelect->setBorderSize(shapeSelect->getBorderSize() - 1);
							}
						break;
					case sf::Keyboard::Subtract:
							if(shapeSelect != nullptr) {
								shapeSelect->setBorderSize(shapeSelect->getBorderSize() + 1);
							}
						break;
					case sf::Keyboard::Delete:
							if(pointSelect != nullptr) {
								gestPoint.remove();
								pointSelect = nullptr;
							}
							if(shapeSelect != nullptr) {
								gestShape.remove();
								shapeSelect = nullptr;
								lastShapeSelect = nullptr;
							}
						break;
					default:
						break;
				}
			}
		}

		if(shapeSelect != nullptr) {
			lastShapeSelect = shapeSelect;
			afficheMenuInfo(font, shapeSelect, screenSize, window);
		}else if(lastShapeSelect != nullptr) {
			afficheMenuInfo(font, lastShapeSelect, screenSize, window);
		}

		gestShape.draw(window, X, Y);//coordonne de la a souris X en x et Y en y
		gestPoint.draw(window, X, Y);
		menuOutils(event, X, Y, isPushLeft, window, gestPoint, gestShape, font);
		Menu(screenSize, screenSize, X, Y, isPushLeft, window);//permet la creation du menu
		window.display();
	}

	return 0;
}
