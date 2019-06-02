

#include "Rectangle.hpp"
#include "Forme.hpp"
#include "Point.hpp"

Rectangle::Rectangle(std::string _couleur,uint _x,uint _y , uint _largeur, uint _hauteur)
	:Forme(_couleur,_x,_y),largeur(_largeur),hauteur(_hauteur){}

Rectangle::Rectangle(const Rectangle &orig)
	:Rectangle(orig.getcouleur(),orig.getAncre().getX(),orig.getAncre().getY(),orig.largeur,orig.hauteur){}
	
Rectangle::Rectangle(std::istream &is):Forme(is){
	is>>largeur;
	is>>hauteur;
}
Rectangle::~Rectangle(){}



 
bool Rectangle::isOver(uint _x,uint _y) const{
	bool over=false;
	//std::cerr<<"mouse_x "<<_x<<" mouse_y:"<<_y<<std::endl;
	//std::cout<<getAncre().getY()+hauteur<<std::endl;
	//si   _              x<x<_x+largeur                              ET                y<_y<y-hauteur
	if( ((_x>=getAncre().getX())&&(_x<getAncre().getX()+hauteur))  && ((getAncre().getY()<_y)&& (_y<getAncre().getY()+largeur)))
	//traduction       x<_x            _x>x+largeur                   et           y<_y          et              _y<y-hauteur   
		over=true;
	//std::cout<<over<<std::endl;
	return over;
}


void Rectangle::ecrire(std::ostream & os) const{
	 os<<"Rectangle ";
	 Forme::ecrire(os);
	 os<<largeur<<' '<<hauteur<<std::endl;
}

