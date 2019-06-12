#include <SFML/Graphics.hpp>
#include <sstream>
#include <typeinfo>
#include "../BaseShapes/Shape.hpp"
#include "../DrawableShapes/ShapesDrawable.hpp"
#include "../DrawableShapes/PointsDrawable.hpp"
#include "../DrawableShapes/RectangleDrawable.hpp"
#include "../DrawableShapes/SquareDrawable.hpp"
#include "../DrawableShapes/EllipseDrawable.hpp"
#include "../DrawableShapes/CircleDrawable.hpp"
#include "../DrawableShapes/TriangleDrawable.hpp"
#include "../DrawableShapes/Color.hpp"


std::string nbToStr(int nombre);
void createMenuInfo();

void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow,edf::Color> *forme ,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);


void Info(sf::Font &Font,RectangleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,SquareDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,EllipseDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,CircleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,TriangleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);

