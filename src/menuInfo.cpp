#include "menuInfo.hpp"

std::string nbToStr(int nombre)//converti le sint en string
{
    std::ostringstream a;
    a << nombre;
    return a.str();
}




void Info(sf::Font &Font,RectangleDrawable *RD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	/*

	permet de modifier la couleur au bon vouloir de l'utilisateur

	*/
	uint SquareDrawableX=200; //position X du premier carre de selection de couleur
	uint SquareDrawableY=200;  //positiion Y du premier carre de selcetion de couleur

	RectangleDrawable contour(SquareDrawableX-5,SquareDrawableY-5,20*4+5*5,20*2+5*3,sf::Color(192,192,192));
	contour.draw(w,false);
	ShapesDrawable carreCouleur=ShapesDrawable(8);
	//permier ligne de carre
	carreCouleur.add(new SquareDrawable(SquareDrawableX,SquareDrawableY,20,sf::Color::Black));//carre noir
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25,SquareDrawableY,20,sf::Color::White));//carre blanc
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25*2,SquareDrawableY,20,sf::Color::Red));//carre rouge
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25*3,SquareDrawableY,20,sf::Color::Green));//carre vert
	//deuxieme ligne de carre
	carreCouleur.add(new SquareDrawable(SquareDrawableX,SquareDrawableY+25,20,sf::Color::Blue));//carre bleu
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25,SquareDrawableY+25,20,sf::Color::Yellow));//carre jaune
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25*2,SquareDrawableY+25,20,sf::Color::Magenta));//carre magenta
	carreCouleur.add(new SquareDrawable(SquareDrawableX+25*3,SquareDrawableY+25,20,sf::Color::Cyan));//carre cyan
	carreCouleur.draw(w,-200,-200);

	if(carreCouleur.browse(0)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Black);
		}
	}
	if(carreCouleur.browse(1)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::White);
		}
	}	
	if(carreCouleur.browse(2)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Red);
		}
	}
	if(carreCouleur.browse(3)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Green);
		}
	}
	if(carreCouleur.browse(4)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Blue);
		}
	}
	if(carreCouleur.browse(5)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Yellow);
		}
	}
	if(carreCouleur.browse(6)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Magenta);
		}
	}
	if(carreCouleur.browse(7)->isOver(mouse_x,mouse_y)){
		if(isPush){
			RD->setColor(sf::Color::Cyan);
		}
	}



	/*
			MODIFI LES VALEURS DE LA FORME
	*/
	SquareDrawable bouton1(sizeecran-180,110,20,sf::Color::Black);
	sf::Text Tb1P("+",Font,20);
	Tb1P.setPosition(sizeecran-178,106);
	Tb1P.setFillColor(sf::Color::Black);
	bouton1.setFilled(false);
	bouton1.draw(w,false);
	w.draw(Tb1P);

	SquareDrawable bouton2(sizeecran-150,110,20,sf::Color::Black);
	sf::Text Tb2P("-",Font,20);
	Tb2P.setPosition(sizeecran-143,106);
	Tb2P.setFillColor(sf::Color::Black);
	bouton2.setFilled(false);
	bouton2.draw(w,false);
	w.draw(Tb2P);

	SquareDrawable bouton3(sizeecran-180,135,20,sf::Color::Black);
	sf::Text Tb3P("+",Font,20);
	Tb3P.setPosition(sizeecran-178,131);
	Tb3P.setFillColor(sf::Color::Black);
	bouton3.setFilled(false);
	bouton3.draw(w,false);
	w.draw(Tb3P);

	SquareDrawable bouton4(sizeecran-150,135,20,sf::Color::Black);
	sf::Text Tb4P("-",Font,20);
	Tb4P.setPosition(sizeecran-143,131);
	Tb4P.setFillColor(sf::Color::Black);
	bouton4.setFilled(false);
	bouton4.draw(w,false);
	w.draw(Tb4P);
	if(bouton1.isOver(mouse_x,mouse_y)){
		Tb1P.setFillColor(sf::Color::Blue);
		w.draw(Tb1P);
		if(isPush){
			RD->setWidth(RD->getWidth()+1);
		}
	}
	if(bouton2.isOver(mouse_x,mouse_y)){
		Tb2P.setFillColor(sf::Color::Blue);
		w.draw(Tb2P);
		if(isPush){
			RD->setWidth(RD->getWidth()-1);
		}
	}
	if(bouton3.isOver(mouse_x,mouse_y)){
		Tb3P.setFillColor(sf::Color::Blue);
		w.draw(Tb3P);
		if (isPush){
			RD->setHeight(RD->getHeight()+1);
		}
	}
	if(bouton4.isOver(mouse_x,mouse_y)){
		Tb4P.setFillColor(sf::Color::Blue);
		w.draw(Tb4P);
		if(isPush){
			RD->setHeight(RD->getHeight()-1);
		}
	}

	/*
		AFFICHE LES INFORMATION SUR LA FORME
	*/
	//affiche le titre "Info Rectangle"
	sf::Text Titre("Info Rectangle",Font,22);
	Titre.setPosition(sizeecran-380,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-380,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(RD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-245,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-380,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(RD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-245,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "largeur" et ça valeur
	sf::Text vTLar("Largeur:",Font,20);
	vTLar.setPosition(sizeecran-380,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(RD->getWidth()),Font,20);
	vLar.setPosition(sizeecran-265,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
	//affiche "Longeur et ça valeur
	sf::Text vTLon("Longeur:",Font,20);
	vTLon.setPosition(sizeecran-380,130);
	vTLon.setFillColor(sf::Color::Black);
	w.draw(vTLon);
	sf::Text vLon(nbToStr(RD->getHeight()),Font,20);
	vLon.setPosition(sizeecran-265,130);
	vLon.setFillColor(sf::Color::Black);
	w.draw(vLon);



}
void Info(sf::Font &Font,SquareDrawable *SD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	/*
			MODIFI LES VALEURS DE LA FORME
	*/
	SquareDrawable bouton1(sizeecran-180,110,20,sf::Color::Black);
	sf::Text Tb1P("+",Font,20);
	Tb1P.setPosition(sizeecran-178,106);
	Tb1P.setFillColor(sf::Color::Black);
	bouton1.setFilled(false);
	bouton1.draw(w,false);
	w.draw(Tb1P);

	SquareDrawable bouton2(sizeecran-150,110,20,sf::Color::Black);
	sf::Text Tb2P("-",Font,20);
	Tb2P.setPosition(sizeecran-143,106);
	Tb2P.setFillColor(sf::Color::Black);
	bouton2.setFilled(false);
	bouton2.draw(w,false);
	w.draw(Tb2P);

	if(bouton1.isOver(mouse_x,mouse_y)){
		Tb1P.setFillColor(sf::Color::Blue);
		w.draw(Tb1P);
		if(isPush){
			SD->setSide(SD->getSide()+1);
		}
	}
	if(bouton2.isOver(mouse_x,mouse_y)){
		Tb2P.setFillColor(sf::Color::Blue);
		w.draw(Tb2P);
		if(isPush){
			SD->setSide(SD->getSide()-1);
		}
	}

	/*
		AFFICHE LES INFORMATION SUR LA FORME
	*/
	//affiche le titre "Info Carre"
	sf::Text Titre("Info Carre",Font,22);
	Titre.setPosition(sizeecran-380,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-380,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(SD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-245,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-380,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(SD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-245,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "Cote" et ça valeur
	sf::Text vTLar("Cote:",Font,20);
	vTLar.setPosition(sizeecran-380,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(SD->getSide()),Font,20);
	vLar.setPosition(sizeecran-265,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
}
void Info(sf::Font &Font,EllipseDrawable *ED,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	/*
			MODIFI LES VALEURS DE LA FORME
	*/
	SquareDrawable bouton1(sizeecran-180,110,20,sf::Color::Black);
	sf::Text Tb1P("+",Font,20);
	Tb1P.setPosition(sizeecran-178,106);
	Tb1P.setFillColor(sf::Color::Black);
	bouton1.setFilled(false);
	bouton1.draw(w,false);
	w.draw(Tb1P);

	SquareDrawable bouton2(sizeecran-150,110,20,sf::Color::Black);
	sf::Text Tb2P("-",Font,20);
	Tb2P.setPosition(sizeecran-143,106);
	Tb2P.setFillColor(sf::Color::Black);
	bouton2.setFilled(false);
	bouton2.draw(w,false);
	w.draw(Tb2P);

	SquareDrawable bouton3(sizeecran-180,135,20,sf::Color::Black);
	sf::Text Tb3P("+",Font,20);
	Tb3P.setPosition(sizeecran-178,131);
	Tb3P.setFillColor(sf::Color::Black);
	bouton3.setFilled(false);
	bouton3.draw(w,false);
	w.draw(Tb3P);

	SquareDrawable bouton4(sizeecran-150,135,20,sf::Color::Black);
	sf::Text Tb4P("-",Font,20);
	Tb4P.setPosition(sizeecran-143,131);
	Tb4P.setFillColor(sf::Color::Black);
	bouton4.setFilled(false);
	bouton4.draw(w,false);
	w.draw(Tb4P);

	if(bouton1.isOver(mouse_x,mouse_y)){
		Tb1P.setFillColor(sf::Color::Blue);
		w.draw(Tb1P);
		if(isPush){
			ED->setWidth(ED->getWidth()+1);
		}
	}
	if(bouton2.isOver(mouse_x,mouse_y)){
		Tb2P.setFillColor(sf::Color::Blue);
		w.draw(Tb2P);
		if(isPush){
			ED->setWidth(ED->getWidth()-1);
		}
	}
	if(bouton3.isOver(mouse_x,mouse_y)){
		Tb3P.setFillColor(sf::Color::Blue);
		w.draw(Tb3P);
		if (isPush){
			ED->setHeight(ED->getHeight()+1);
		}
	}
	if(bouton4.isOver(mouse_x,mouse_y)){
		Tb4P.setFillColor(sf::Color::Blue);
		w.draw(Tb4P);
		if(isPush){
			ED->setHeight(ED->getHeight()-1);
		}
	}

	/*
		AFFICHE LES INFORMATION SUR LA FORME
	*/

	//affiche le titre "Info Carre"
	sf::Text Titre("Info Ellispe",Font,22);
	Titre.setPosition(sizeecran-380,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-380,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(ED->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-245,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-380,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(ED->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-245,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "largeur" et ça valeur
	sf::Text vTLar("Largeur:",Font,20);
	vTLar.setPosition(sizeecran-380,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(ED->getWidth()),Font,20);
	vLar.setPosition(sizeecran-265,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
	//affiche "Longeur et ça valeur
	sf::Text vTLon("Longeur:",Font,20);
	vTLon.setPosition(sizeecran-380,130);
	vTLon.setFillColor(sf::Color::Black);
	w.draw(vTLon);
	sf::Text vLon(nbToStr(ED->getHeight()),Font,20);
	vLon.setPosition(sizeecran-265,130);
	vLon.setFillColor(sf::Color::Black);
	w.draw(vLon);
}
void Info(sf::Font &Font,CircleDrawable *CD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	/*
			MODIFI LES VALEURS DE LA FORME
	*/
	SquareDrawable bouton1(sizeecran-180,110,20,sf::Color::Black);
	sf::Text Tb1P("+",Font,20);
	Tb1P.setPosition(sizeecran-178,106);
	Tb1P.setFillColor(sf::Color::Black);
	bouton1.setFilled(false);
	bouton1.draw(w,false);
	w.draw(Tb1P);

	SquareDrawable bouton2(sizeecran-150,110,20,sf::Color::Black);
	sf::Text Tb2P("-",Font,20);
	Tb2P.setPosition(sizeecran-143,106);
	Tb2P.setFillColor(sf::Color::Black);
	bouton2.setFilled(false);
	bouton2.draw(w,false);
	w.draw(Tb2P);

	if(bouton1.isOver(mouse_x,mouse_y)){
		Tb1P.setFillColor(sf::Color::Blue);
		w.draw(Tb1P);
		if(isPush){
			CD->setRadius(CD->getRadius()+1);
		}
	}
	if(bouton2.isOver(mouse_x,mouse_y)){
		Tb2P.setFillColor(sf::Color::Blue);
		w.draw(Tb2P);
		if(isPush){
			CD->setRadius(CD->getRadius()-1);
		}
	}

	/*
		AFFICHE LES INFORMATION SUR LA FORME
	*/
	//affiche le titre "Info Cercle"
	sf::Text Titre("Info Cercle",Font,22);
	Titre.setPosition(sizeecran-380,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-380,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(CD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-245,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-380,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(CD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-245,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "Rayon" et ça valeur
	sf::Text vTLar("Rayon:",Font,20);
	vTLar.setPosition(sizeecran-380,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(CD->getRadius()),Font,20);
	vLar.setPosition(sizeecran-265,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
}
void Info(sf::Font &Font,TriangleDrawable *TD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	//ajustement de l'écran
	RectangleDrawable ecranmenInfo(sizeecran-400,160,400,150,sf::Color(192,192,192));
	ecranmenInfo.draw(w,false);

	//affiche le titre "Info Cercle"
	sf::Text Titre("Info Triangle",Font,22);
	Titre.setPosition(sizeecran-380,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	
	//&&&&&&&&&   Ancre1
	
	
	//affiche "valeur x" et ça valeur
	sf::Text vA1T("Ancre 1:",Font,20);
	vA1T.setPosition(sizeecran-380,60);
	vA1T.setFillColor(sf::Color::Black);
	w.draw(vA1T);
	//affiche "valeur x" et ça valeur
	sf::Text vA1TX("Valeur de X:",Font,20);
	vA1TX.setPosition(sizeecran-380,86);
	vA1TX.setFillColor(sf::Color::Black);
	w.draw(vA1TX);
	std::string ttvX=nbToStr(TD->getAnchor()->getX());
	sf::Text vA1X(ttvX,Font,20);
	vA1X.setPosition(sizeecran-245,86);
	vA1X.setFillColor(sf::Color::Black);
	w.draw(vA1X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA1TY("Valeur de Y:",Font,20);
	vA1TY.setPosition(sizeecran-380,110);
	vA1TY.setFillColor(sf::Color::Black);
	w.draw(vA1TY);
	sf::Text vA1Y(nbToStr(TD->getAnchor()->getY()),Font,20);
	vA1Y.setPosition(sizeecran-245,110);
	vA1Y.setFillColor(sf::Color::Black);
	w.draw(vA1Y);
	
	
	//&&&&&&&&&&&& Ancer 2 
	sf::Text vA2T("Ancre 2:",Font,20);
	vA2T.setPosition(sizeecran-380,140);
	vA2T.setFillColor(sf::Color::Black);
	w.draw(vA2T);
	//affiche "valeur x" et ça valeur
		sf::Text vA2TX("Valeur de X:",Font,20);
	vA2TX.setPosition(sizeecran-380,160);
	vA2TX.setFillColor(sf::Color::Black);
	w.draw(vA2TX);
	sf::Text vA2X(nbToStr(TD->getAnchor1()->getX()),Font,20);
	vA2X.setPosition(sizeecran-245,160);
	vA2X.setFillColor(sf::Color::Black);
	w.draw(vA2X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA2TY("Valeur de Y:",Font,20);
	vA2TY.setPosition(sizeecran-380,180);
	vA2TY.setFillColor(sf::Color::Black);
	w.draw(vA2TY);
	sf::Text vA2Y(nbToStr(TD->getAnchor1()->getY()),Font,20);
	vA2Y.setPosition(sizeecran-245,180);
	vA2Y.setFillColor(sf::Color::Black);
	w.draw(vA2Y);
	
	//&&&&&&&&&&&& Ancer 3 
	sf::Text vA3T("Ancre 3:",Font,20);
	vA3T.setPosition(sizeecran-380,220);
	vA3T.setFillColor(sf::Color::Black);
	w.draw(vA3T);
	//affiche "valeur x" et ça valeur
	sf::Text vA3TX("Valeur de X:",Font,20);
	vA3TX.setPosition(sizeecran-380,240);
	vA3TX.setFillColor(sf::Color::Black);
	w.draw(vA3TX);
	sf::Text vA3X(nbToStr(TD->getAnchor2()->getX()),Font,20);
	vA3X.setPosition(sizeecran-245,240);
	vA3X.setFillColor(sf::Color::Black);
	w.draw(vA3X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA3TY("Valeur de Y:",Font,20);
	vA3TY.setPosition(sizeecran-380,260);
	vA3TY.setFillColor(sf::Color::Black);
	w.draw(vA3TY);
	sf::Text vA3Y(nbToStr(TD->getAnchor2()->getY()),Font,20);
	vA3Y.setPosition(sizeecran-245,260);
	vA3Y.setFillColor(sf::Color::Black);
	w.draw(vA3Y);
	
}

//void Info(sf::Font &Font,PolynomeDrawable *PD,uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){}


		
void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow, edf::Color>  *forme, uint sizeecran,uint mouse_x,uint mouse_y,bool isPush,sf::RenderWindow &w){
	RectangleDrawable ecranmenInfo(sizeecran-400,31,400,150,sf::Color(192,192,192));
	ecranmenInfo.draw(w,false);
	
	//permet de savoir le type de shape rectangle,carre...
	RectangleDrawable* my_rD=dynamic_cast<RectangleDrawable*>(forme);
	SquareDrawable* my_sD=dynamic_cast<SquareDrawable*>(forme);
	EllipseDrawable* my_eD=dynamic_cast<EllipseDrawable*>(forme);
	CircleDrawable* my_cD=dynamic_cast<CircleDrawable*>(forme);
	TriangleDrawable* my_tD=dynamic_cast<TriangleDrawable*>(forme);
	//PolynomeDrawable* my_pD=dynamic_cast<PolynomeDrawable*>(forme);
	
	//appel la fonction qui affiche les info en fonction du type
	if(my_rD!=nullptr)
		Info(Font,my_rD,sizeecran,mouse_x,mouse_y,isPush,w);
	else if(my_sD!=nullptr)
		Info(Font,my_sD,sizeecran,mouse_x,mouse_y,isPush,w);
	else if(my_eD!=nullptr)
		Info(Font,my_eD,sizeecran,mouse_x,mouse_y,isPush,w);
	else if(my_cD!=nullptr)
		Info(Font,my_cD,sizeecran,mouse_x,mouse_y,isPush,w);
	else if(my_tD!=nullptr)
		Info(Font,my_tD,sizeecran,mouse_x,mouse_y,isPush,w);
	/*else if(my_pD!=nullptr)
		Info(Font,my_pD,sizeeecran,mouse_x,mouse_y,isPush,w);
	*/
}
