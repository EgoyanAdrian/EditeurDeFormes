#include "menuOutils.hpp"

menuOutils::menuOutils(sf::Event &e,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable &PointsD,ShapesDrawable &SD){
	uint x=150,y=160,i=0,j=0;
	
	//creation des rectangles du Menu
	tabMenuOutil.add(new RectangleDrawable(x, y,sf::Color(192,192,192), 110, 82+46*5));//rectangle global des option du menu
	tabMenuOutil.add(new RectangleDrawable(x+5, y+5,sf::Color::Yellow, 100, 31));//premier rectangle creation d'un rectangle
	tabMenuOutil.add(new RectangleDrawable(x+5, y+46,sf::Color::Yellow, 100, 31));//46 car 5 car meme niveau que le rectangle 1 +31 pour la hauteur du rectangle 1 +10 d'espace enter le deux rectangle
	tabMenuOutil.add(new RectangleDrawable(x+5, y+46*2,sf::Color::Yellow,100,31));//option cercle
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*3,sf::Color::Yellow,100,31));//option Ellipse
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*4,sf::Color::Yellow,100,31));//option Triangle
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*5,sf::Color::Yellow,100,31));//option Polynome
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*6,sf::Color::Yellow,100,31));//option Calque
	
	//creation tu texte du Menu
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}
	sf::Text creaRect("Rectangle",font,24);
	sf::Text creaCarre("Carre",font,24);
	sf::Text creaCercle("Cercle",font,24);
	sf::Text creaEllips("Ellipse",font,24);
	sf::Text creaTriangle("Triangle",font,24);
	sf::Text creaPoly("Polygones",font,24);
	sf::Text creaCalque("Calque",font,24);
	
	//position du texte
	creaRect.setPosition(x+7,y+7);
	creaCarre.setPosition(x+7,y+48);
	creaCercle.setPosition(x+7,y+47*2);
	creaEllips.setPosition(x+7,y+47*3);
	creaTriangle.setPosition(x+7,y+46*4);
	creaPoly.setPosition(x+7,y+46*5);
	creaCalque.setPosition(x+7,y+46*6);
	
	//couleur du texte
	creaRect.setFillColor(sf::Color::Black);
	creaCarre.setFillColor(sf::Color::Black);
	creaCercle.setFillColor(sf::Color::Black);
	creaEllips.setFillColor(sf::Color::Black);
	creaTriangle.setFillColor(sf::Color::Black);
	creaPoly.setFillColor(sf::Color::Black);
	creaCalque.setFillColor(sf::Color::Black);
	//dessin des rectangles
	tabMenuOutil.draw(w,-200,-200);
	
	//apparition du texte
	w.draw(creaRect);
	w.draw(creaCarre);
	w.draw(creaCercle);
	w.draw(creaEllips);
	w.draw(creaTriangle);
	w.draw(creaPoly);
	w.draw(creaCalque);
	
	//~ if(tabMenuOutil.browse(0)->isOver(mouse_x,mouse_y) ){
		//~ CoorRectangle.textSaisie(e,w);
		//~ sf::Text test("test",font,24);
		//~ test.setPosition(500,500);
		//~ test.setFillColor(sf::Color::Black);
		//~ w.draw(test);
		//~ std::cout<<CoorRectangle.getString()<<std::endl;
	
		//~ //j = j + 10;
		//~ //SD.add(new RectangleDrawable(j, 40, sf::Color::Black, 10, 20));
	//~ }
	
	
	
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
