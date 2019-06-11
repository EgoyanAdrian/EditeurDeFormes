#include "Menu.hpp"

/*###################################################################
				Construction (Barre des taches)
####################################################################*/

Menu::Menu(uint _sizeX,uint _sizeY ,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w){
sizeEcranX=_sizeX;//coordnonne de la taille du Menu en x
sizeEcranY=_sizeY;//	"							y
sf::Font font;
if (!font.loadFromFile("font.ttf"))
{
   // erreur...
}
//~ font.loadFromFile("font.ttf");

//
//
//	Creation des composants du menu
//
//

//creation de la barre des taches
menu.add(new RectangleDrawable(0, 0,sizeEcranX,31,sf::Color(192,192,192)));

//creation des icone du menu
menu.add(new RectangleDrawable(0, 0, 100, 31,sf::Color(192,192,192)));//menuFichier
menu.add(new RectangleDrawable(100, 0, 100, 31,sf::Color(192,192,192)));//menuEdition
menu.add(new RectangleDrawable(200, 0, 100, 31,sf::Color(192,192,192)));//menuHelp
menu.draw(w,-200,-200);

//definition des text
sf::Text textFichier("Fichier",font,22);
sf::Text textEdition("Edition",font,22);
sf::Text textHelp("Aide",font,22);
//~ //position des texts
textFichier.setPosition(10,0);
textEdition.setPosition(110,0);
textHelp.setPosition(210,0);
//~ //couleur du text
textFichier.setFillColor(sf::Color::Black);
textEdition.setFillColor(sf::Color::Black);
textHelp.setFillColor(sf::Color::Black);

//      Fonction pour dessiner

//ecrire les textes
w.draw(textFichier);
w.draw(textEdition);
w.draw(textHelp);


//					definition des rectangles du Menu deroulant
//definition du soulignement bleu

sf::Vertex line1F[] =
{
    sf::Vertex(sf::Vector2f(0,30),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,30 ),sf::Color::Blue)
};
sf::Vertex line2F[] =
{
    sf::Vertex(sf::Vector2f(0,29),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,29 ),sf::Color::Blue)
};
sf::Vertex line3F[] =
{
    sf::Vertex(sf::Vector2f(0,31),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,31 ),sf::Color::Blue)
};

/*
#################################################################################################
						Creation des rectangles et du texte du sous Menu de Fichier
#################################################################################################
*/
sousmenuFichier.add(new RectangleDrawable(0, 31, 100, 31, sf::Color(192,192,192)));//MenuFiOuvrir
sousmenuFichier.add(new RectangleDrawable(0, 31*2, 100, 31, sf::Color(192,192,192)));//MenuFiEnregis
sousmenuFichier.add(new RectangleDrawable(0, 31*3, 100, 31, sf::Color(192,192,192)));//MenuFiQuitter
//~ Rectangle menuFiEnregis("Gris",0,31,sizeEcranX,100);
//~ Rectangle menuFiOuvrir("Gris",0,31+sizeEcranX,sizeEcranX,100);
//~ Rectangle menuFiQuitter("Gris",0,31+sizeEcranX*2,sizeEcranX,100);

//texte
sf::Text textFichOuvrir("Ouvrir",font,17);
sf::Text textFichEnrg("Enregistrer",font,17);
sf::Text textFichQuit("Quitter",font,17);

textFichOuvrir.setPosition(0,32);
textFichEnrg.setPosition(0,31*2);
textFichQuit.setPosition(0,32*3);

textFichOuvrir.setFillColor(sf::Color::Black);
textFichEnrg.setFillColor(sf::Color::Black);
textFichQuit.setFillColor(sf::Color::Black);

/*
 * 
 * 
 * 
 * 		Afficher le menu deroulant de Fichier
 * 
 * 
 * 
 * 
 * */
	
	if((menu.browse(1)->isOver(mouse_y,mouse_y))&&isPush){//permet de savoir si on click sur Fichier
		isOverFichier=true;
	}
//					Fichier								Ouvrir														Enregistrer										Quitter
	
	//permet de savoir si on n'est pas sur un bouton du sous menu
	if(isOverFichier && ((sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)) || (sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)) || (sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)))) {
		//ligne de soulignement
		ssFich=true;
	}

	if((!(menu.browse(1)->isOver(mouse_x,mouse_y))&&(sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)==false))&&isPush) {
		isOverFichier=false;
		ssFich=false;
	}

	if(isOverFichier||ssFich){
		//ligne de soulignement
		w.draw(line1F, 2, sf::Lines);
		w.draw(line2F, 2, sf::Lines);
		w.draw(line3F, 2, sf::Lines);
		//changement de la couleur du text
		textFichier.setFillColor(sf::Color::Blue);
		w.draw(textFichier);
	
		//affiche les rectangles du menu deroulant
		sousmenuFichier.draw(w,-200,-200);
		
		//~ //afficher les text
		w.draw(textFichEnrg);
		w.draw(textFichOuvrir);
		w.draw(textFichQuit);
		
/*$$$$$$$$$$$$$$$$$$$$$$$$$ Sous Menu Ouvrir $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

		if(sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)){//si la souri et sur le rectangle menuFiEnregis
			textFichOuvrir.setFillColor(sf::Color::Blue);//chagement de la couleur du text noir -> bleu
			w.draw(textFichOuvrir);
			if(isPush){
				
			}
		}

/*$$$$$$$$$$$$$$$$$$$$$$$$$ Sous Menu Enregistrement $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
		if(sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)){
			textFichEnrg.setFillColor(sf::Color::Blue);
			w.draw(textFichEnrg);//ecrie le nouveau texte
			if(isPush){
				textFichEnrg.setFillColor(sf::Color::Red);//chagement de la couleur du text noir -> bleu
				w.draw(textFichEnrg);
				std::ofstream outfile ("test.txt");
				outfile << "my text here!" << std::endl;
				outfile.close();
			}
		}

/*$$$$$$$$$$$$$$$$$$$$$$$$$ Sous Menu  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
		if(sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)){
			textFichQuit.setFillColor(sf::Color::Blue);
			w.draw(textFichQuit);
			if(isPush){
				closeWindow(w);
				}
		}
	}
/*
 * 
 * 
 * 
 * 		Afficher le menu deroulant de Edition
 * 
 * Permettant de creer les formes avec les racourcies
 * 
 * 
 * */
/*
#################################################################################################
						Creation des rectangles et du texte du sous Menu de Edition
#################################################################################################
*/
	

	//Position du premier rectangle

	uint xme=102;//x :valeur de x m:menu e:edition
	uint yme=32;// de meme pour yme


	//creation des rectangles du tabMenuOutil     110:largeur yme*7:longeur
	RectangleDrawable GR(xme, yme, 180, yme*7, sf::Color(192,192,192));//rectangle global des option du menu
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme, 170, 31, sf::Color(192,192,192)));//premier rectangle creation d'un rectangle
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme*2, 100, 31, sf::Color(192,192,192)));//46 car 5 car meme niveau que le rectangle 1 +31 pour la hauteur du rectangle 1 +10 d'espace enter le deux rectangle
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme*3, 100, 31, sf::Color(192,192,192)));//option cercle
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*4, 100, 31, sf::Color(192,192,192)));//option Ellipse
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*5, 100, 31, sf::Color(192,192,192)));//option Triangle
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*6, 100, 31, sf::Color(192,192,192)));//option Polynome
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*7, 100, 31, sf::Color(192,192,192)));//option Calque
	


	sf::Text creaRect("Rectangle",font,19);
	sf::Text creaRectCtr("ctrl+R",font,19);
	sf::Text creaCarre("Carre",font,20);
	sf::Text creaCarreCtr("ctrl+S",font,20);
	sf::Text creaCercle("Cercle",font,20);
	sf::Text creaCercleCtr("ctrl+C",font,20);
	sf::Text creaEllips("Ellipse",font,20);
	sf::Text creaEllipsCtr("ctrl+E",font,20);
	sf::Text creaTriangle("Triangle",font,19);
	sf::Text creaTriangleCtr("ctrl+T",font,19);
	sf::Text creaPoly("Polygones",font,19);
	sf::Text creaCalque("Calque",font,20);


	//Position des Textes des boutons
	creaRect.setPosition(xme+5,yme+2);
	creaCarre.setPosition(xme+5,yme*2+2);//yme *nb de forme avant+1(pour lui meme)+2 pour faire un espace
	creaCercle.setPosition(xme+5,yme*3+2);
	creaEllips.setPosition(xme+5,yme*4+2);
	creaTriangle.setPosition(xme+5,yme*5+2);
	creaPoly.setPosition(xme+5,yme*6+2);
	creaCalque.setPosition(xme+5,yme*7+2);

	//Position des Textes de controle
	creaRectCtr.setPosition(xme+110,yme+2);	
	creaCarreCtr.setPosition(xme+110,yme*2+2);
	creaCercleCtr.setPosition(xme+110,yme*3+2);
	creaEllipsCtr.setPosition(xme+110,yme*4+2);
	creaTriangleCtr.setPosition(xme+110,yme*5+2);


	//Couleur des texte
	creaRect.setFillColor(sf::Color::Black);
	creaRectCtr.setFillColor(sf::Color::Black);
	creaCarre.setFillColor(sf::Color::Black);
	creaCarreCtr.setFillColor(sf::Color::Black);
	creaCercle.setFillColor(sf::Color::Black);
	creaCercleCtr.setFillColor(sf::Color::Black);
	creaEllips.setFillColor(sf::Color::Black);
	creaEllipsCtr.setFillColor(sf::Color::Black);

	//definition du soulignement bleu	
	sf::Vertex line1E[] =
	{
    	sf::Vertex(sf::Vector2f(101,30),sf::Color::Blue),
    	sf::Vertex(sf::Vector2f(210,30 ),sf::Color::Blue)
	};
	sf::Vertex line2E[] =
	{
    	sf::Vertex(sf::Vector2f(101,29),sf::Color::Blue),
    	sf::Vertex(sf::Vector2f(210,29 ),sf::Color::Blue)
	};
	sf::Vertex line3E[] =
	{
    	sf::Vertex(sf::Vector2f(101,31),sf::Color::Blue),
    	sf::Vertex(sf::Vector2f(210,31 ),sf::Color::Blue)
	};

/*
	w.draw(line1E, 2, sf::Lines);
	w.draw(line2E, 2, sf::Lines);
	w.draw(line3E, 2, sf::Lines);

	w.draw(creaRect);
	w.draw(creaRectCtr);
	w.draw(creaCarre);
	w.draw(creaCarreCtr);
	w.draw(creaCercle);
	w.draw(creaCercleCtr);
	w.draw(creaEllips);
	w.draw(creaEllipsCtr);
*/



	if((menu.browse(2)->isOver(mouse_y,mouse_y))&&isPush){//permet de savoir si on click sur Edition
		isOverEdition=true;
	}
	
	//permet de savoir si on n'est pas sur un bouton du sous menu
	if(isOverEdition && (GR.isOver(mouse_x,mouse_y))) {
		//ligne de soulignement
		ssEdition=true;
	}

	if((!(menu.browse(2)->isOver(mouse_x,mouse_y)))&&(GR.isOver(mouse_x,mouse_y)==false)&&isPush) {
		isOverEdition=false;
		ssEdition=false;
	}

	if(isOverEdition||ssEdition){
		std::cout<<"ok"<<std::endl;
		//ligne de soulignement
		w.draw(line1E, 2, sf::Lines);
		w.draw(line2E, 2, sf::Lines);
		w.draw(line3E, 2, sf::Lines);
		//changement de la couleur du text
		textEdition.setFillColor(sf::Color::Blue);
		w.draw(textEdition);
	
		//affiche les rectangles du menu deroulant
		GR.draw(w,false);
		tabMenuOutil.draw(w,-200,-200);
		
		//~ //afficher les text
		w.draw(creaRect);
		w.draw(creaRectCtr);
		w.draw(creaCarre);
		w.draw(creaCarreCtr);
		w.draw(creaCercle);
		w.draw(creaCercleCtr);
		w.draw(creaEllips);
		w.draw(creaEllipsCtr);
	}

/*
 * 
 * 
 * 
 * 		Afficher la fenetre d'aide
 * 
 * 
 * 
 * 
 * */
	//~ if(menuHelp.isOver(mouse_x,mouse_y) && isPush){
		//~ //creation d'une fenetre d'aide
		//~ sf::RenderWindow window(sf::VideoMode(500, 500), "Aide");
		//~ while (window.isOpen())
		//~ {
			//~ sf::Event event;
			//~ while (window.pollEvent(event))
			//~ {
				//~ if (event.type == sf::Event::Closed)
					//~ window.close();
			//~ }

        //~ window.clear(sf::Color::White);
        //~ window.display();
    //~ }
	//~ }



}
Menu::~Menu(){};

