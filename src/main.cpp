#include <fstream>

#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "PointsDrawable.hpp"
#include "ShapesDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "SquareDrawable.hpp"
#include "CircleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "Color.hpp"
#include "menuInfo.hpp"
#include "Menu.hpp"


int main() {
	std::ofstream saveF;
	std::ifstream loadF;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Editeur de Formes", sf::Style::Default, settings);

	uint nbS = 0, nbSMax = 10;
	PointsDrawable gestPoint[nbSMax];
	ShapesDrawable gestShape[nbSMax];

	bool showLayer = false;

	bool isoverFichier=false;
	bool isoverEdition=false;

	Point * pointSelect = nullptr;
	Shape<sf::RenderWindow, edf::Color> * shapeSelect = nullptr;
	Shape<sf::RenderWindow, edf::Color> * lastShapeSelect = nullptr;
	
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}

	uint X, Y, i = 0, j = 0, distX, distY;
	while(window.isOpen()) {
		bool isPushLeft=false; //variable pour savoir si le bouton gauche de la souris et enfoncer)
		window.clear(sf::Color::White);

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::Resized)
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

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
				pointSelect = gestPoint[nbS].isOver(X, Y);
				shapeSelect = gestShape[nbS].isOver(X, Y);

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
							gestPoint[nbS].add(new Point(i, 200));
						break;
					case sf::Keyboard::R:
							j = j + 10;
							gestShape[nbS].add(new RectangleDrawable(j, 280, 10, 20, sf::Color::Black));
						break;
					case sf::Keyboard::S:
							j = j + 10;
							gestShape[nbS].add(new SquareDrawable(j, 260, 10, sf::Color::Yellow));
						break;
					case sf::Keyboard::C:
							j = j + 10;
							gestShape[nbS].add(new CircleDrawable(j, 220, 5, sf::Color::Green));
						break;
					case sf::Keyboard::E:
							j = j + 10;
							gestShape[nbS].add(new EllipseDrawable(j, 240, 10, 5, sf::Color::Black));
						break;
					case sf::Keyboard::T:
							j = j + 10;
							Point * pointA; pointA = new Point(j, 260);
							Point * pointB; pointB = new Point(j + 20, 280);
							Point * pointC; pointC = new Point(j - 5, 300);
							gestPoint[nbS].add(pointA);
							gestPoint[nbS].add(pointB);
							gestPoint[nbS].add(pointC);
							gestShape[nbS].add(new TriangleDrawable(pointA, pointB, pointC, sf::Color::Green));
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
								gestPoint[nbS].remove();
								pointSelect = nullptr;
							}
							if(shapeSelect != nullptr) {
								gestShape[nbS].remove();
								shapeSelect = nullptr;
								lastShapeSelect = nullptr;
							}
						break;
					case sf::Keyboard::Z:
							if(nbS < (nbSMax - 1))
								nbS++;
							else
								std::cout << "Pas de calques superieurs " << std::endl;
						break;
					case sf::Keyboard::X:
							if(nbS > 0)
								nbS--;
							else
								std::cout << "Pas de calques inferieurs " << nbS << std::endl;
						break;
					case sf::Keyboard::A:
							showLayer = !showLayer;
						break;
					case sf::Keyboard::M:
							saveF.open ("Points.save", std::ofstream::out | std::ofstream::trunc);
							for (uint i = 0; i < nbSMax; i++)
								gestPoint[i].save(saveF);
							saveF.close();
						break;
					case sf::Keyboard::N:
							loadF.open ("Points.save", std::ifstream::in);
							for (uint i = 0; i < nbSMax; i++)
								gestPoint[i].load(loadF);
							loadF.close();
					default:
						break;
				}
			}
		}
		
		if(showLayer) {
			for(uint i = 0; i < 10; i++) {
				gestShape[i].draw(window, X, Y);
				gestPoint[i].draw(window, X, Y);
			}
		} else {
			gestShape[nbS].draw(window, X, Y);
			gestPoint[nbS].draw(window, X, Y);
		}

		if(shapeSelect != nullptr) {
			lastShapeSelect = shapeSelect;
			afficheMenuInfo(font, shapeSelect, window.getSize().x,X,Y,isPushLeft, window);
		}else if(lastShapeSelect != nullptr) {
			afficheMenuInfo(font, lastShapeSelect, window.getSize().x,X,Y,isPushLeft, window);
		}

		Menu(window.getSize().x, window.getSize().y, X, Y, isPushLeft, window,gestPoint,gestShape,showLayer,nbS,nbSMax,isoverFichier,isoverEdition);//permet la creation du menu
		window.display();
	}

	return 0;
}
