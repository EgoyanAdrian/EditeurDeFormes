#include "MenuOutils.hpp"


/*###################################################################
				Construction (Barre d'outis)
####################################################################*/

void menuOutil(uint _x,uint _y,uint _mousex, uint _mousey,bool isPushLeft,sf::RenderWindow &w){
	//Rectangle
	sf::Font font;

	if(!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}
	font.loadFromFile("font.ttf");
	//rectangle du Menu
	Rectangle dessinRectan("Gris",_x,_y,30,100);
	Rectangle dessinCarre("Gris",_x,_y+30,30,100);
	Rectangle dessinPoint("Gris",_x,_y+60,30,100);
	//TRectangle.push_back(10);//stoque l'adress du rectangle dans le tableau 
	//Texte du Menu
	sf::Text textdessinRectan("Rectangle",font,24);
	sf::Text textdessinCarre("Carre",font,24);
	sf::Text textdessinPoint("Point",font,24);
	//position du text
	textdessinRectan.setPosition(_x+10,_y);
	textdessinCarre.setPosition(_x+10,_y+30);
	textdessinPoint.setPosition(_x+10,_y+60);
	//couleur du text
	textdessinRectan.setFillColor(sf::Color::Black);
	textdessinCarre.setFillColor(sf::Color::Black);
	textdessinPoint.setFillColor(sf::Color::Black);
	//dessin de rectangle
	dessiner(w,dessinRectan,dessinRectan.isOver(_x,_y),0,0,false);
	dessiner(w,dessinCarre,dessinCarre.isOver(_x,_y),0,0,false);
	dessiner(w,dessinPoint,dessinPoint.isOver(_x,_y),0,0,false);
	if(dessinRectan.isOver(_x,_y)){
		//ouvre le fenetre de configuration
	}
	else if(dessinCarre.isOver(_x,_y)){
		//ouvre la fenetre de configuration
	}
	else if(dessinPoint.isOver(_x,_y)){
		//ouver la fenetre de configuration
	}
	w.draw(textdessinRectan);
	w.draw(textdessinCarre);
	w.draw(textdessinPoint);

}
