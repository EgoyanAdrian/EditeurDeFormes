#include <SFML/Graphics.hpp>
#include "Point.hpp"

Point::Point(uint _x, uint _y):x(_x), y(_y){} //constructeur avec 2 parametre coordonner du point

Point::Point(const Point &orig):Point(orig.x,orig.y){}//constructeur par copie (avec un point en parametre)

Point::Point(std::istream &is){
	is>>x;
	is>>y;
}

Point::~Point(){}

std::ostream &operator<<(std::ostream &os, const Point & p){
	os<<p.getX()<<std::endl;
	os<<p.getY();
	return os;
}

std::istream &operator>>(std::istream &is,Point &p){
	uint x;
	uint y;
	std::cout<<"donner la valeur de x"<<std::endl;
	is>>x;
	std::cout<<"Donner la valeur de y"<<std::endl;
	is>>y;
	p.SetXY(x,y);
	return is;
}

bool Point::isOver(uint _x, uint _y)const{
	//std::cerr<<"mouse_x "<<_x<<" mouse_y:"<<_y<<std::endl;
	bool over=false;
	if ((x==_x && y==_y) || (_x<(x+(taille-1)) && _x>(x-(taille-1))) || (_y<(y+(taille-1)) && _y>(y-(taille-1))))//si y-2<_y<y+2
		over=true;
	//std::cerr<<over<<std::endl;
	return over;
}


