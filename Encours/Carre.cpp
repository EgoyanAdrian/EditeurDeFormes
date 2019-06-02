#include <iostream>
#include "Carre.hpp"


Carre::Carre(std::string _couleur,uint _x ,uint _y ,uint _cote)
	:Forme(_couleur,_x,_y),cote(_cote){}

Carre::Carre(const Carre &orig)
	:Carre(orig.getcouleur(),orig.getAncre().getX(),orig.getAncre().getY(),orig.cote){}

Carre::~Carre(){}


bool Carre::isOver(uint _x, uint _y) const{
	bool over=false;
	//std::cerr<<"mouse_x:"<<_x<<" mouse_y:"<<_y<<std::endl;
	//si   _              x<x<_x+cote                              ET                y<_y<y-cote
	if( ((_x>getAncre().getX())&&(_x<getAncre().getX()+cote))  && ((_y>getAncre().getY())&& (_y<getAncre().getY()+cote)))
	//traduction       x<_x            _x>x+cote               et           y<_y          et              _y<y-cote 
		over=true;
	return over;
}
