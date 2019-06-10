#include <SFML/Graphics.hpp>
#include <sstream>
#include <typeinfo>
#include "Shape.hpp"
#include "ShapesDrawable.hpp"
#include "PointsDrawable.hpp"
#include "RectangleDrawable.hpp"


std::string nbToStr(int nombre);
void createMenuInfo();
void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow, sf::Color> *forme,uint sizeecran,sf::RenderWindow &w);

