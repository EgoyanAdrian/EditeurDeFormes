#include "menuOutils.hpp"

menuOutils::menuOutils(uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w){
	uint x=150;
	uint y=160;
	//creation des rectangles du Menu
	tabMenuOutil.add(new RectangleDrawable(x, y,sf::Color(192,192,192), 110, 82));//rectangle global des option du menu
	tabMenuOutil.add(new RectangleDrawable(x+5, y+5,sf::Color::Red, 100, 31));//premier rectangle creation d'un rectangle
	tabMenuOutil.add(new RectangleDrawable(x+5, y+46,sf::Color::Yellow, 100, 31));//46 car 5 car meme niveau que le rectangle 1 +31 pour la hauteur du rectangle 1 +10 d'espace enter le deux rectangle
	
	
	//creation tu texte du Menu
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}
	sf::Text creaRect("Rectangle",font,24);
	sf::Text creaCarre("Carre",font,24);
	sf::Text creaCercle("Cercle",font,24);
	sf::Text creaEllisp("Ellipse",font,24);
	/*
	sf::Text creaTriangle("Triangle"),font,24);
	sf::Text creaPoly("Polygones",font,24);
	sf::Text creaCalque("Calque",font,24);
	*/
	//position du texte
	creaRect.setPosition(x+7,y+7);
	creaCarre.setPosition(x+7,y+48);
	//couleur du texte
	creaRect.setFillColor(sf::Color::Black);
	creaCarre.setFillColor(sf::Color::Black);
	
	//dessin des rectangles
	tabMenuOutil.draw(w,-200,-200);
	
	//apparition du texte
	w.draw(creaRect);
	w.draw(creaCarre);
	
	//~ if((tabMenuOutil.browse(0)->isOver(mouse_x,mouse_y) && !(tabMenuOutil.browse(1)->isOver(mouse_x,mouse_y)) &&!(tabMenuOutil.browse(2)->isOver(mouse_x,mouse_y)))&&isPush){
		
		//~ moveMenu(mouse_x,mouse_y,w);
	//~ }
}

menuOutils::~menuOutils(){}

void menuOutils::moveMenu(uint mouse_X,uint mouse_Y,sf::RenderWindow &w){
	uint distX,distY,X,Y;
	
	distX=mouse_X-tabMenuOutil.browse(0)->getAnchor()->getX();//calcule de la distance entre l'ancre du rectangle principale et de la sourie
	distY=mouse_Y-tabMenuOutil.browse(0)->getAnchor()->getY();
	
	X=mouse_X-distX;//nouvelle valeur pour X du rectangle principale
	Y=mouse_Y-distY;//nouvelle valeur pour Y du rectangle principale
	
	//mise ajour des valeur des ancres des rectangles
	tabMenuOutil.browse(0)->setAnchorXY(X,Y);
	tabMenuOutil.browse(0)->setAnchorXY(X+5,Y+5);
	tabMenuOutil.browse(0)->setAnchorXY(X+5,Y+46);
	
}
