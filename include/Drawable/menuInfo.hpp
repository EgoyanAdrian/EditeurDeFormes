#include <SFML/Graphics.hpp>
#include <sstream>
#include <typeinfo>
#include <EDF/Shape.hpp>
#include <Drawable/ShapesDrawable.hpp>
#include <Drawable/PointsDrawable.hpp>
#include <Drawable/RectangleDrawable.hpp>
#include <Drawable/SquareDrawable.hpp>
#include <Drawable/EllipseDrawable.hpp>
#include <Drawable/CircleDrawable.hpp>
#include <Drawable/TriangleDrawable.hpp>
#include <Drawable/Color.hpp>


std::string nbToStr(int nombre);
void createMenuInfo();

void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow,edf::Color> *forme ,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);


void Info(sf::Font &Font,RectangleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,SquareDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,EllipseDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,CircleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);
void Info(sf::Font &Font,TriangleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,bool &isOC,sf::RenderWindow &w);

