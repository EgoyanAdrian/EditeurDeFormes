/*fichier qui regourpe les codes des draw*/
/*Zone d'include*/
#include "Draw.hpp"


sf::Color CCouleur(std::string _Color){
	sf::Color couleurs; //variable qui contiendra la couleur demande
	sf::Color Gris(192,192,192);
	if( _Color=="Red")
		couleurs=sf::Color::Red;
	else if(_Color== "Black")
			couleurs=sf::Color::Black;
	else if(_Color=="White")
		couleurs=sf::Color::White;
	else if(_Color=="Green")
		couleurs=sf::Color::Green;
	else if(_Color=="Blue")
		couleurs=sf::Color::Blue;
	else if(_Color=="Yellow")
		couleurs=sf::Color::Yellow;
	else if(_Color=="Magenta")
		couleurs=sf::Color::Magenta;
	else if(_Color=="Cyan")
		couleurs=sf::Color::Cyan;
	else if(_Color=="Transparent")
		couleurs=sf::Color::Transparent;
	else if(_Color=="Gris")
		couleurs=Gris;
		//mettre la gestion d'erreur 
	return couleurs;
}
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*############################################## Fonction pour dessiner un Point #######################################################*/

void dessiner(sf::RenderWindow & w,Point &P,bool isActive,uint mx,uint my,bool isPush){
	sf::Color couleur;
	uint x=P.getX();
	uint y=P.getY();
	if(isActive)
		couleur=sf::Color::Red;
	else
		couleur=sf::Color::White;
	
	
	if(isPush && isActive){
		P.SetXY(mx,my);
	}

	sf::Vertex vertices[]={
		sf::Vertex(sf::Vector2f(x,y),couleur),//	point(x,x)
		sf::Vertex(sf::Vector2f(x,y-1),couleur),//permet de faire un point de 3px de rayons
		sf::Vertex(sf::Vector2f(x,y+1),couleur),
		sf::Vertex(sf::Vector2f(x-1,y),couleur),
		sf::Vertex(sf::Vector2f(x+1,y),couleur)
	};
		
	w.draw(vertices,5,sf::Points);
}
/*#######################################################  Fin  #####################################################################*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*=========================================== Fonction pour dessiner un Rectangle ===================================================*/
void dessiner(sf::RenderWindow &w,Rectangle &R,bool isActive,uint mx,uint my,bool isPush){

	uint largeur=R.getLargeur();
	uint hauteur=R.getHauteur();

	sf::Color coul=CCouleur(R.getcouleur());
	//verification pour savoir si la souris et sur la forme
	if(isActive){																	//// a revoir tout comme le isOver du rectangle
		coul=sf::Color::Yellow; //si la souris et dessus la couleur et rouge
		//~ sf::Vertex vertices[]={
			//~ sf::Vertex(sf::Vector2f(X-1,Y-1),couleur),
			//~ sf::Vertex(sf::Vector2f(X-1,Y+largeur-2),couleur),
			//~ sf::Vertex(sf::Vector2f(X+hauteur+2,Y+largeur-2),couleur),
			//~ sf::Vertex(sf::Vector2f(X+hauteur+2,Y-2),couleur)					//X+hauteur+2 si on passe de +2 a +5 decalage de la ligne sur la droite
		//~ };
		//~ w.draw(vertices,4,sf::Lines);
	}
	if(isPush && isActive){ 
		//setAncre(mx,my);
		//R.setAncre(mx,my);
	}
	uint X=R.getAncre().getX();
	uint Y=R.getAncre().getY();
	
	sf::Vertex rectangle[]={//trace un rectangel grace a sf::Quads
		sf::Vertex(sf::Vector2f(X,Y),coul),
		sf::Vertex(sf::Vector2f(X,Y+largeur),coul),
		sf::Vertex(sf::Vector2f(X+hauteur,Y+largeur),coul),
		sf::Vertex(sf::Vector2f(X+hauteur,Y),coul)
	};
	w.draw(rectangle,4,sf::Quads);
}

/*======================================================== Fin ======================================================================*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*############################################# Fonction pour dessiner un carre #####################################################*/
void dessiner(sf::RenderWindow & w,Carre &C,bool isActive,uint mx,uint my,bool isPush){
	uint x=C.getAncre().getX();
	uint y=C.getAncre().getY();
	uint cote=C.getCote();
	sf::Color coul=CCouleur(C.getcouleur());
	
	if(isActive)//si le curseur et sur la forme
	{
		coul=sf::Color::Green; //la couleur devient verte
	}
	sf::Vertex carre[]={
		sf::Vertex(sf::Vector2f(x,y),coul),
		sf::Vertex(sf::Vector2f(x,y+cote),coul),
		sf::Vertex(sf::Vector2f(x+cote,y+cote),coul),
		sf::Vertex(sf::Vector2f(x+cote,y),coul)
	};
	w.draw(carre,4,sf::Quads);
}

/*######################################################## Fin ######################################################################*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

