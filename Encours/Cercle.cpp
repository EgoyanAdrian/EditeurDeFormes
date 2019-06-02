#include "Cercle.hpp"
#include "Forme.hpp"

Cercle::Cercle(std::string _couleur,uint radius,uint _x,uint _y, std::size_t nombPoint):Forme(_couleur,_x,_y){
	Shape.setRadius(radius);
	Shape.setPosition(_x,_y);
	Shape.setOutlineColor(CCouleur(_couleur));
	}
Cercle::Cercle(Cercle &orig):Cercle(orig.getcouleur(),orig.radius,orig.getAncre().getX(),orig.getAncre().getY(),orig.nombPoint){}

Cercle::~Cercle(){
}

bool Cercle::isOver(uint _x,uint _y) const{
	
}
