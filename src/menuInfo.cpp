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
						
void afficheMenuInfo(sf::Font &Font,Shape<sf::RenderWindow, sf::Color>  *forme, uint sizeecran,sf::RenderWindow &w){
	RectangleDrawable ecranmenInfo(sizeecran-200,31,sf::Color(192,192,192),200,sizeecran-31);
	ecranmenInfo.draw(w,false);
	sf::Text Titre("Info sur le Rectangle",Font,24);
	Titre.setPosition(500,500);
	Titre.setFillColor(sf::Color::Black);
	w.draw(Titre);
	if(typeid(forme) == typeid(Rectangle<sf::RenderWindow, sf::Color>)){
		sf::Text Titre("Info sur le Rectangle",Font,24);
		Titre.setPosition(500,500);
		Titre.setFillColor(sf::Color::Black);
		w.draw(Titre);
		sf::Text vTX("Valeur de X:",Font,24);
		std::string ttvX=nbToStr(forme->getAnchor()->getX());
		sf::Text vX(ttvX,Font,24);
		sf::Text vTY("Valeur de Y:",Font,24);
		sf::Text vY(nbToStr(forme->getAnchor()->getY()),Font,24);
		//sf::Text vTLar("Valeur de largeur:",Font,24);
		//sf::Text vLar(nbToStr(forme.getWidth()),Font,24);
		//sf::Text vTLon("Valeur de longeur:",Font,24);
		//sf::Text vLon(nbToStr(forme.getHeight()),Font,24);
	}
	//~ if(type=="Carre"){
		
	//~ }
	//~ if(type=="Ellipse"){
	
	//~ }
	//~ if(type=="Cercle"){
		
	//~ }
}


