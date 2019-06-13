#include <fstream>

#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <Drawable/PointsDrawable.hpp>
#include <Drawable/ShapesDrawable.hpp>
#include <Drawable/RectangleDrawable.hpp>
#include <Drawable/SquareDrawable.hpp>
#include <Drawable/CircleDrawable.hpp>
#include <Drawable/EllipseDrawable.hpp>
#include <Drawable/TriangleDrawable.hpp>
// #include <Drawable/PolygonDrawable.hpp> !!INCOMPLET
#include <Drawable/Color.hpp>
#include <Drawable/menuInfo.hpp>
#include <Drawable/Menu.hpp>


int main() {
	std::ofstream saveF;
	std::ifstream loadF;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Editeur de Formes", sf::Style::Default, settings);

	bool boutonCoulActive=false;
	uint nbS = 0, nbSMax = 10;
	PointsDrawable layoutGestPoints[nbSMax];
	ShapesDrawable layoutGestShapes[nbSMax];

	bool showLayer = false;

	bool isoverFichier=false;
	bool isoverEdition=false;
	bool isoverAidee=false;
	bool ssFich=false;
	bool ssEdition=false;
	bool isCtrlPressed=false;

	Point * pointSelect = nullptr;
	Shape<sf::RenderWindow, edf::Color> * shapeSelect = nullptr;
	Shape<sf::RenderWindow, edf::Color> * lastShapeSelect = nullptr;
	
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}

	uint X, Y, j = 0, distX, distY;
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

				if(shapeSelect != nullptr)
					shapeSelect->setAnchorXY(X - distX, Y - distY);
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				isPushLeft=true;

			if(event.type == sf::Event::MouseButtonPressed) {
				if(showLayer) {
					uint i = 0;
					while(pointSelect == nullptr && shapeSelect == nullptr && i < nbSMax) {
						pointSelect = layoutGestPoints[i].isOver(X, Y);
						shapeSelect = layoutGestShapes[i].isOver(X, Y);
						i++;
					}
				} else {
					pointSelect = layoutGestPoints[nbS].isOver(X, Y);
					shapeSelect = layoutGestShapes[nbS].isOver(X, Y);
				}

				if(isCtrlPressed) {

				}

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
				if(isCtrlPressed) {
					switch(event.key.code) {
						case sf::Keyboard::A:
								j = j + 10;
								layoutGestShapes[nbS].add(new RectangleDrawable(j, 280, 10, 20, sf::Color::Black));
							break;
						case sf::Keyboard::Z:
								j = j + 10;
								layoutGestShapes[nbS].add(new SquareDrawable(j, 260, 10, sf::Color::Yellow));
							break;
						case sf::Keyboard::E:
								j = j + 10;
								layoutGestShapes[nbS].add(new CircleDrawable(j, 220, 5, sf::Color::Green));
							break;
						case sf::Keyboard::R:
								j = j + 10;
								layoutGestShapes[nbS].add(new EllipseDrawable(j, 240, 10, 5, sf::Color::Black));
							break;
						case sf::Keyboard::T:
								j = j + 10;
								Point * pointA; pointA = new Point(j, 260);
								Point * pointB; pointB = new Point(j + 20, 280);
								Point * pointC; pointC = new Point(j - 5, 300);
								layoutGestPoints[nbS].add(pointA);
								layoutGestPoints[nbS].add(pointB);
								layoutGestPoints[nbS].add(pointC);
								layoutGestShapes[nbS].add(new TriangleDrawable(pointA, pointB, pointC, sf::Color::Green));
							break;
						/*case sf::Keyboard::Y: 		// malloc consolidate error A la fermeture et add method necessaire dans Shape.hpp
								Point * p; p = new Point(100, 320);
								layoutGestPoints[nbS].add(p);
								layoutGestShapes[nbS].add(new PolygonDrawable(p, sf::Color::Black, 1));
								Point * p1; p1 = new Point(140, 320);
								layoutGestPoints[nbS].add(p1);
								layoutGestShapes[nbS].browse(layoutGestShapes[nbS].getNbShapes() - 1)->add(p1);
								Point * p2; p2 = new Point(145, 340);
								layoutGestPoints[nbS].add(p2);
								layoutGestShapes[nbS].browse(layoutGestShapes[nbS].getNbShapes() - 1)->add(p2);
								Point * p3; p3 = new Point(130, 350);
								layoutGestPoints[nbS].add(p3);
								layoutGestShapes[nbS].browse(layoutGestShapes[nbS].getNbShapes() - 1)->add(p3);
								Point * p4; p4 = new Point(90, 330);
								layoutGestPoints[nbS].add(p4);
								layoutGestShapes[nbS].browse(layoutGestShapes[nbS].getNbShapes() - 1)->add(p4);
							break;*/
						case sf::Keyboard::Left:
								if(nbS < (nbSMax - 1))
									nbS++;
								else
									std::cout << "Pas de calques superieurs " << std::endl;
							break;
						case sf::Keyboard::Right:
								if(nbS > 0)
									nbS--;
								else
									std::cout << "Pas de calques inferieurs " << nbS << std::endl;
							break;
						case sf::Keyboard::Q:
								showLayer = !showLayer;
							break;
						case sf::Keyboard::S:
								saveF.open ("Shapes.save", std::ofstream::out | std::ofstream::trunc);
								for (uint i = 0; i < nbSMax; i++) {
									saveF << i << std::endl;
									layoutGestShapes[i].save(saveF);
								}
								saveF.close();
							break;
						case sf::Keyboard::D:
								loadF.open ("Shapes.save", std::ifstream::in);
								for (uint i = 0; i < nbSMax; i++) {
									uint k;
									loadF >> k;
									layoutGestShapes[k].load(loadF, layoutGestPoints[k]);
								}
								loadF.close();
						default:
							break;
					}
				} else {
					switch(event.key.code) {
						case sf::Keyboard::LControl:
								isCtrlPressed = true;
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
									layoutGestPoints[nbS].remove();
									pointSelect = nullptr;
								}
								if(shapeSelect != nullptr) {
									layoutGestShapes[nbS].remove();
									shapeSelect = nullptr;
									lastShapeSelect = nullptr;
								}
							break;
						default:
							break;
					}
				}
			}

			if(event.type == sf::Event::KeyReleased) {
				if(event.key.code == sf::Keyboard::LControl)
					isCtrlPressed = false;
			}
		}
		
		if(showLayer) {
			for(uint i = 0; i < 10; i++) {
				layoutGestShapes[i].draw(window, X, Y);
				layoutGestPoints[i].draw(window, X, Y);
			}
		} else {
			layoutGestShapes[nbS].draw(window, X, Y);
			layoutGestPoints[nbS].draw(window, X, Y);
		}

		if(shapeSelect != nullptr) {
			lastShapeSelect = shapeSelect;
			afficheMenuInfo(font, shapeSelect, window.getSize().x,X,Y,isPushLeft,boutonCoulActive, window);
		}else if(lastShapeSelect != nullptr) {
			afficheMenuInfo(font, lastShapeSelect, window.getSize().x,X,Y,isPushLeft,boutonCoulActive, window);
		}


		Menu(window.getSize().x, window.getSize().y, X, Y, isPushLeft, window,layoutGestPoints,layoutGestShapes,showLayer,nbS,nbSMax,isoverFichier,isoverEdition,isoverAidee,ssFich,ssEdition);//permet la creation du menu
		window.display();
	}

	return 0;
}
