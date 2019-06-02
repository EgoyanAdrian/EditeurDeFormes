#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"
#include "Carre.hpp"
//#include "Ellipse.hpp"
#include "Forme.hpp"
#include "Point.hpp"

Forme::Forme(const std::string _Color,uint _x,uint _y):couleur(_Color),ancre(_x,_y),selected(false){}

Forme::Forme(const Forme &o):Forme(o.couleur,o.ancre.getX(),o.ancre.getY()){}

Forme::Forme(std::istream &is):ancre(is){
	is>>couleur; 
}


Forme::~Forme(){}

void Forme::ecrire(std::ostream &os) const {
	os<<couleur<<' '<<ancre<<' ';
}

Forme *Forme::charger(std::istream &is){
	std::string type;
	is>>type;
	if(type=="Rectangle"){return new Rectangle(is);}
	//else if(type=="Carre"){return new Carre(is);}
	//else if(type=="Cercle"){return new Cercle(is);}
	//else if(type=="Ellipse"){return new Ellipse(is);}
	
}

std::ostream &operator<<(std::ostream &os,const Forme &f){f.ecrire(os);}

