#include <Drawable/menuOutils.hpp>

menuOutils::menuOutils(sf::Event &e,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable &PointsD,ShapesDrawable &SD,sf::Font font ):nbrectangle(50){
	uint x=0,y=0,j=0;

/*



		Creation du Menu pour construire les formes



*/

	//creation des rectangles du tabMenuOutil        82 car 5(decalage de bord)+31(taille du rectangle jaune)
	//												+46 car espace entre de y
	//												*5 car il y a 5 rectangle en plus de deux defini dans 82
	tabMenuOutil.add(new RectangleDrawable(x, y, 110, 82+46*5, sf::Color(192,192,192)));//rectangle global des option du menu
	tabMenuOutil.add(new RectangleDrawable(x+5, y+5, 100, 31, sf::Color::Yellow));//premier rectangle creation d'un rectangle
	tabMenuOutil.add(new RectangleDrawable(x+5, y+46, 100, 31, sf::Color::Yellow));//46 car 5 car meme niveau que le rectangle 1 +31 pour la hauteur du rectangle 1 +10 d'espace enter le deux rectangle
	tabMenuOutil.add(new RectangleDrawable(x+5, y+46*2, 100, 31, sf::Color::Yellow));//option cercle
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*3, 100, 31, sf::Color::Yellow));//option Ellipse
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*4, 100, 31, sf::Color::Yellow));//option Triangle
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*5, 100, 31, sf::Color::Yellow));//option Polynome
	tabMenuOutil.add(new RectangleDrawable(x+5,y+46*6, 100, 31, sf::Color::Yellow));//option Calque
	
	//creation tu texte du Menu

	sf::Text creaRect("Rectangle",font,19);
	sf::Text creaCarre("Carre",font,20);
	sf::Text creaCercle("Cercle",font,20);
	sf::Text creaEllips("Ellipse",font,20);
	sf::Text creaTriangle("Triangle",font,19);
	sf::Text creaPoly("Polygones",font,19);
	sf::Text creaCalque("Calque",font,20);
	
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
	
	if(tabMenuOutil.browse(1)->isOver(mouse_x,mouse_y)&&isPush ){//bouton pour faire un rectangle
		//~ CoorRectangle.textSaisie(e,w);
		//~ sf::Text test("test",font,24);
		//~ test.setPosition(500,500);
		//~ test.setFillColor(sf::Color::Black);
		//~ w.draw(test);
		//~ std::cout<<CoorRectangle.getString()<<std::endl;
	
		nbrectangle += 10;
		SD.add(new RectangleDrawable(nbrectangle, 40, 10, 20, sf::Color::Black));
	}
	if(tabMenuOutil.browse(2)->isOver(mouse_x,mouse_y)&&isPush){//bouton pour faire un carre
		j = j + 10;
		SD.add(new SquareDrawable(j, 260, 10, sf::Color::Yellow));
	}
	if(tabMenuOutil.browse(3)->isOver(mouse_x,mouse_y)&&isPush){//bouton pour faire un cercle
		j = j + 10;
		SD.add(new CircleDrawable(j, 220, 5, sf::Color::Green));
	}
	if(tabMenuOutil.browse(4)->isOver(mouse_x,mouse_y)&&isPush){//bouton pour faire uune Ellipse
		j = j + 10;
		SD.add(new EllipseDrawable(j, 240, 10, 5, sf::Color::Black));
	}
	if(tabMenuOutil.browse(5)->isOver(mouse_x,mouse_y)&&isPush){//bouton pour faire un triangle
		j = j + 10;
		Point * pointA; pointA = new Point(j, 260);
		Point * pointB; pointB = new Point(j + 20, 280);
		Point * pointC; pointC = new Point(j - 5, 300);
		PointsD.add(pointA);
		PointsD.add(pointB);
		PointsD.add(pointC);
		SD.add(new TriangleDrawable(pointA, pointB, pointC, sf::Color::Green));
	}
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
	
	//~ if((tabMenuOutil.browse(0)->isOver(mouse_x,mouse_y) && !(tabMenuOutil.browse(1)->isOver(mouse_x,mouse_y)) &&!(tabMenuOutil.browse(2)->isOver(mouse_x,mouse_y)))&&isPush){
		
		//~ moveMenu(mouse_x,mouse_y,w);
	//~ }

/*



			Creation du menu qui permet de modifer la taille des formes




*/
	tabMenuModif.add(new RectangleDrawable(x+120, y, 110, 82+46*5, sf::Color(192,192,192)));
	tabMenuOutil.draw(w,-200,-200);






}

menuOutils::~menuOutils(){}

