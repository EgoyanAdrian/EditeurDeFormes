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
sf::Text textFichier("Fichier",font,24);
sf::Text textEdition("Edition",font,24);
sf::Text textHelp("Help",font,24);
//~ //position des texts
textFichier.setPosition(10,0);
textEdition.setPosition(110,0);
textHelp.setPosition(210,0);
//~ //couleur du text
textFichier.setFillColor(sf::Color::Black);
textEdition.setFillColor(sf::Color::Black);
textHelp.setFillColor(sf::Color::Black);

//      Fonction pour dessiner
//dessiner les boutons
//dessiner(w,menuFichier,false,0,0,false);
//dessiner(w,menuEdition,false,0,0,false);
//dessiner(w,menuHelp,false,0,0,false);
//ecrire les textes
w.draw(textFichier);
w.draw(textEdition);
w.draw(textHelp);


//					definition des rectangles du Menu deroulant
//definition du soulignement bleu

sf::Vertex line1[] =
{
    sf::Vertex(sf::Vector2f(0,30),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,30 ),sf::Color::Blue)
};
sf::Vertex line2[] =
{
    sf::Vertex(sf::Vector2f(0,30),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,29 ),sf::Color::Blue)
};
sf::Vertex line3[] =
{
    sf::Vertex(sf::Vector2f(0,30),sf::Color::Blue),
    sf::Vertex(sf::Vector2f(100,31 ),sf::Color::Blue)
};


//rectangle

sousmenuFichier.add(new RectangleDrawable(0, 31, 100, 31, sf::Color(192,192,192)));//MenuFiOuvrir
sousmenuFichier.add(new RectangleDrawable(0, 31*2, 100, 31, sf::Color(192,192,192)));//MenuFiEnregis
sousmenuFichier.add(new RectangleDrawable(0, 31*3, 100, 31, sf::Color(192,192,192)));//MenuFiQuitter
//~ Rectangle menuFiEnregis("Gris",0,31,sizeEcranX,100);
//~ Rectangle menuFiOuvrir("Gris",0,31+sizeEcranX,sizeEcranX,100);
//~ Rectangle menuFiQuitter("Gris",0,31+sizeEcranX*2,sizeEcranX,100);

//texte
sf::Text textFichOuvrir("Ouvrir",font,20);
sf::Text textFichEnrg("Enregistrer",font,20);
sf::Text textFichQuit("Quitter",font,20);

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
		clickFich=true;
		isOverFichier=true;
		std::cout<<"true"<<std::endl;
	}

	//permet de savoir si on s
/*	if((menu.browse(1)->isOver(mouse_y,mouse_y)&&!(sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)&&!(sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)&&!(sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)))))){
		isOverFichier=false;
		//isOverFicMenuDeour=false;
		std::cout<<"false"<<std::endl;
	}*/
	//					Fichier								Ouvrir														Enregistrer										Quitter
	
	//permet de savoir si on n'est pas sur un bouton du sous menu
	if((menu.browse(1)->isOver(mouse_y,mouse_y))==false && (sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)==false)){
		//ligne de soulignement
		isOverFichier=false;
	}

	if(isOverFichier){
		w.draw(line1, 2, sf::Lines);
		w.draw(line2, 2, sf::Lines);
		w.draw(line3, 2, sf::Lines);
		//changement de la couleur du text
		textFichier.setFillColor(sf::Color::Blue);
		w.draw(textFichier);
	
		//affiche les rectangles du menu deroulant
		sousmenuFichier.draw(w,-200,-200);
		
		//~ dessiner(w,menuFiEnregis,false,0,0,false);
		//~ dessiner(w,menuFiOuvrir,false,0,0,false);
		//~ dessiner(w,menuFiQuitter,false,0,0,false);
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
 * 
 * 
 * 
 * */
	//~ if(menuEdition.isOver(mouse_x,mouse_y)){
		
	//~ }
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

