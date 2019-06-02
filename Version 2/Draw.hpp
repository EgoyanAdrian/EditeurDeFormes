/*fichier qui regoupe tout les draw*/
#include "Point.hpp"
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"

sf::Color CCouleur(std::string _Color);
void dessiner(sf::RenderWindow & w,Point &P,bool isActive,uint mx,uint my,bool isPush);//dessine un Point
void dessiner(sf::RenderWindow & w,Rectangle &R,bool isActive,uint mx,uint my,bool isPush);//dessine un Rectangle
void dessiner(sf::RenderWindow & w,Carre &C,bool isActive,uint mx,uint my,bool isPush);//dessine un carre
//void dessiner(sf::RenderWindow & w,Ellipse &E,bool isActive,uint mx,uint my,bool isPush);//dessine une ellipse

