#include "menuInfo.hpp"

std::string nbToStr(int nombre)//converti le sint en string
{
    std::ostringstream a;
    a << nombre;
    return a.str();
}
//~ void createMenuInfo(std::string type){
	//~ if(type=="Rectangle"){
		//~ sf:Text Titre("Info Creation Rectangle",font,24);
		//~ sf::Text vX("Valeur de X:",font,24);
		//~ sf::Text vY("Valeur de Y:",font,24);
		//~ sf::Text vLar("Valeur de largeur:",font,24);
		//~ sf::Text vLon("Valeur de longeur:",font,24);
	//~ }
	//~ if(type=="Carre"){
		
	//~ }
	//~ if(type=="Ellipse"){
	
	//~ }
	//~ if(type=="Cercle"){
		
	//~ }
//~ }
void infoShapes(Rectangle<sf::RenderWindow, sf::Color>  *r){
	//~ std::cout<<"fonctionne"<<std::endl;
}




void Info(sf::Font &Font,RectangleDrawable *RD,uint sizeecran,sf::RenderWindow &w){
	//affiche le titre "Info Rectangle"
	sf::Text Titre("Info Rectangle",Font,22);
	Titre.setPosition(sizeecran-180,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-180,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(RD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-45,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-180,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(RD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-45,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "largeur" et ça valeur
	sf::Text vTLar("Largeur:",Font,20);
	vTLar.setPosition(sizeecran-180,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(RD->getWidth()),Font,20);
	vLar.setPosition(sizeecran-65,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
	//affiche "Longeur et ça valeur
	sf::Text vTLon("Longeur:",Font,20);
	vTLon.setPosition(sizeecran-180,130);
	vTLon.setFillColor(sf::Color::Black);
	w.draw(vTLon);
	sf::Text vLon(nbToStr(RD->getHeight()),Font,20);
	vLon.setPosition(sizeecran-65,130);
	vLon.setFillColor(sf::Color::Black);
	w.draw(vLon);
}
void Info(sf::Font &Font,SquareDrawable *SD,uint sizeecran,sf::RenderWindow &w){
	//affiche le titre "Info Carre"
	sf::Text Titre("Info Carre",Font,22);
	Titre.setPosition(sizeecran-180,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-180,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(SD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-45,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-180,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(SD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-45,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "Cote" et ça valeur
	sf::Text vTLar("Cote:",Font,20);
	vTLar.setPosition(sizeecran-180,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(SD->getSide()),Font,20);
	vLar.setPosition(sizeecran-65,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
}
void Info(sf::Font &Font,EllipseDrawable *ED,uint sizeecran,sf::RenderWindow &w){
	//affiche le titre "Info Carre"
	sf::Text Titre("Info Ellispe",Font,22);
	Titre.setPosition(sizeecran-180,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-180,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(ED->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-45,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-180,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(ED->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-45,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "largeur" et ça valeur
	sf::Text vTLar("Largeur:",Font,20);
	vTLar.setPosition(sizeecran-180,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(ED->getWidth()),Font,20);
	vLar.setPosition(sizeecran-65,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
	//affiche "Longeur et ça valeur
	sf::Text vTLon("Longeur:",Font,20);
	vTLon.setPosition(sizeecran-180,130);
	vTLon.setFillColor(sf::Color::Black);
	w.draw(vTLon);
	sf::Text vLon(nbToStr(ED->getHeight()),Font,20);
	vLon.setPosition(sizeecran-65,130);
	vLon.setFillColor(sf::Color::Black);
	w.draw(vLon);
}
void Info(sf::Font &Font,CircleDrawable *CD,uint sizeecran,sf::RenderWindow &w){
	//affiche le titre "Info Cercle"
	sf::Text Titre("Info Cercle",Font,22);
	Titre.setPosition(sizeecran-180,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	//affiche "valeur x" et ça valeur
	sf::Text vTX("Valeur de X:",Font,20);
	vTX.setPosition(sizeecran-180,60);
	vTX.setFillColor(sf::Color::Black);
	w.draw(vTX);
	std::string ttvX=nbToStr(CD->getAnchor()->getX());
	sf::Text vX(ttvX,Font,20);
	vX.setPosition(sizeecran-45,60);
	vX.setFillColor(sf::Color::Black);
	w.draw(vX);
	//affiche "valeur de Y" et ça valeur
	sf::Text vTY("Valeur de Y:",Font,20);
	vTY.setPosition(sizeecran-180,86);
	vTY.setFillColor(sf::Color::Black);
	w.draw(vTY);
	sf::Text vY(nbToStr(CD->getAnchor()->getY()),Font,20);
	vY.setPosition(sizeecran-45,86);
	vY.setFillColor(sf::Color::Black);
	w.draw(vY);
	//affiche "Rayon" et ça valeur
	sf::Text vTLar("Rayon:",Font,20);
	vTLar.setPosition(sizeecran-180,110);
	vTLar.setFillColor(sf::Color::Black);
	w.draw(vTLar);
	sf::Text vLar(nbToStr(CD->getRadius()),Font,20);
	vLar.setPosition(sizeecran-65,110);
	vLar.setFillColor(sf::Color::Black);
	w.draw(vLar);
}
void Info(sf::Font &Font,TriangleDrawable *TD,uint sizeecran,sf::RenderWindow &w){
	//ajustement de l'écran
	RectangleDrawable ecranmenInfo(sizeecran-200,160,sf::Color(192,192,192),200,150);
	ecranmenInfo.draw(w,false);

	//affiche le titre "Info Cercle"
	sf::Text Titre("Info Triangle",Font,22);
	Titre.setPosition(sizeecran-180,33);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	
	//&&&&&&&&&   Ancre1
	
	
	//affiche "valeur x" et ça valeur
	sf::Text vA1T("Ancre 1:",Font,20);
	vA1T.setPosition(sizeecran-180,60);
	vA1T.setFillColor(sf::Color::Black);
	w.draw(vA1T);
	//affiche "valeur x" et ça valeur
	sf::Text vA1TX("Valeur de X:",Font,20);
	vA1TX.setPosition(sizeecran-180,86);
	vA1TX.setFillColor(sf::Color::Black);
	w.draw(vA1TX);
	std::string ttvX=nbToStr(TD->getAnchor()->getX());
	sf::Text vA1X(ttvX,Font,20);
	vA1X.setPosition(sizeecran-45,86);
	vA1X.setFillColor(sf::Color::Black);
	w.draw(vA1X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA1TY("Valeur de Y:",Font,20);
	vA1TY.setPosition(sizeecran-180,110);
	vA1TY.setFillColor(sf::Color::Black);
	w.draw(vA1TY);
	sf::Text vA1Y(nbToStr(TD->getAnchor()->getY()),Font,20);
	vA1Y.setPosition(sizeecran-45,110);
	vA1Y.setFillColor(sf::Color::Black);
	w.draw(vA1Y);
	
	
	//&&&&&&&&&&&& Ancer 2 
	sf::Text vA2T("Ancre 2:",Font,20);
	vA2T.setPosition(sizeecran-180,140);
	vA2T.setFillColor(sf::Color::Black);
	w.draw(vA2T);
	//affiche "valeur x" et ça valeur
		sf::Text vA2TX("Valeur de X:",Font,20);
	vA2TX.setPosition(sizeecran-180,160);
	vA2TX.setFillColor(sf::Color::Black);
	w.draw(vA2TX);
	sf::Text vA2X(nbToStr(TD->getAnchor1()->getX()),Font,20);
	vA2X.setPosition(sizeecran-45,160);
	vA2X.setFillColor(sf::Color::Black);
	w.draw(vA2X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA2TY("Valeur de Y:",Font,20);
	vA2TY.setPosition(sizeecran-180,180);
	vA2TY.setFillColor(sf::Color::Black);
	w.draw(vA2TY);
	sf::Text vA2Y(nbToStr(TD->getAnchor1()->getY()),Font,20);
	vA2Y.setPosition(sizeecran-45,180);
	vA2Y.setFillColor(sf::Color::Black);
	w.draw(vA2Y);
	
	//&&&&&&&&&&&& Ancer 3 
	sf::Text vA3T("Ancre 3:",Font,20);
	vA3T.setPosition(sizeecran-180,220);
	vA3T.setFillColor(sf::Color::Black);
	w.draw(vA3T);
	//affiche "valeur x" et ça valeur
	sf::Text vA3TX("Valeur de X:",Font,20);
	vA3TX.setPosition(sizeecran-180,240);
	vA3TX.setFillColor(sf::Color::Black);
	w.draw(vA3TX);
	sf::Text vA3X(nbToStr(TD->getAnchor2()->getX()),Font,20);
	vA3X.setPosition(sizeecran-45,240);
	vA3X.setFillColor(sf::Color::Black);
	w.draw(vA3X);
	//affiche "valeur de Y" et ça valeur
	sf::Text vA3TY("Valeur de Y:",Font,20);
	vA3TY.setPosition(sizeecran-180,260);
	vA3TY.setFillColor(sf::Color::Black);
	w.draw(vA3TY);
	sf::Text vA3Y(nbToStr(TD->getAnchor2()->getY()),Font,20);
	vA3Y.setPosition(sizeecran-45,260);
	vA3Y.setFillColor(sf::Color::Black);
	w.draw(vA3Y);
	
}




		
void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow, sf::Color>  *forme, uint sizeecran,sf::RenderWindow &w){
	RectangleDrawable ecranmenInfo(sizeecran-200,31,sf::Color(192,192,192),200,150);
	ecranmenInfo.draw(w,false);
	
	//permet de savoir le type de shape
	RectangleDrawable* my_rD=dynamic_cast<RectangleDrawable*>(forme);
	SquareDrawable* my_sD=dynamic_cast<SquareDrawable*>(forme);
	EllipseDrawable* my_eD=dynamic_cast<EllipseDrawable*>(forme);
	CircleDrawable* my_cD=dynamic_cast<CircleDrawable*>(forme);
	TriangleDrawable* my_tD=dynamic_cast<TriangleDrawable*>(forme);
	if(my_rD!=nullptr)
		Info(Font,my_rD,sizeecran,w);
	if(my_sD!=nullptr)
		Info(Font,my_sD,sizeecran,w);
	if(my_eD!=nullptr)
		Info(Font,my_eD,sizeecran,w);
	if(my_cD!=nullptr)
		Info(Font,my_cD,sizeecran,w);
	if(my_tD!=nullptr)
		Info(Font,my_tD,sizeecran,w);

	
}



