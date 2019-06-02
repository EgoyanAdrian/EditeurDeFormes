#include <iostream>
#include <cstdio>
#include "Ellipse.hpp"
#include "Forme.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"

Ellipse::Ellipse(ulong couleur,uint x,uint y,uint _demiLargeur,uint _demiHauteur)
	:Forme(couleur,x,y),demiLargeur(_demiLargeur),demiHauteur(_demiHauteur){}

Ellipse::Ellipse(Ellipse &orig)
	:Ellipse(orig.getcouleur(),orig.getAncre().getX(),orig.getAncre().getY(),orig.demiLargeur,orig.demiHauteur){}

Ellipse::~Ellipse(){}


bool Ellipse::isOver(uint _x,uint _y) const{
	//creation du rectangle correspondant
	//std::cerr<<"mouse_x "<<_x<<" mouse_y:"<<_y<<std::endl;
	Rectangle RectEllipse(2,getAncre().getX()-demiLargeur,getAncre().getY()-demiHauteur,2*demiLargeur,2*demiHauteur);
	//std::cout<<RectEllipse.isOver(_x,_y)<<std::endl;
	return (RectEllipse.isOver(_x,_y));
}
