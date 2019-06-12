#include "Menu.hpp"

/*###################################################################
				Construction (Barre des taches)
####################################################################*/
std::string Menu::nbToStr(int nombre)//converti le sint en string
{
    std::ostringstream a;
    a << nombre;
    return a.str();
}


Menu::Menu(uint _sizeX,uint _sizeY ,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable PointsD[],ShapesDrawable SD[],bool &showLayer,uint &nbS,uint &nbSMax,bool &isoverFichier,bool &isoverEdition,bool &isoverAidee,bool &ssFich,bool &ssEdition){
sizeEcranX=_sizeX;//coordnonne de la taille du Menu en x
sizeEcranY=_sizeY;//	"							y
sf::Font font;
isOverFichier=isoverFichier;
isOverEdition=isoverEdition;
isOverAidee=isoverAidee;
j=100;
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


/*

		Affichage des calques et gestion
*/
/*
			MODIFI LES VALEURS DE LA FORME
*/
//affichage de tout les calques
RectangleDrawable boutonT(sizeEcranX-380,1,70,26,sf::Color::Black);
sf::Text TbTP("Tout",font,19);
TbTP.setPosition(sizeEcranX-370,1);
TbTP.setFillColor(sf::Color::Black);
boutonT.setFilled(false);
boutonT.draw(w,false);
w.draw(TbTP);

if(boutonT.isOver(mouse_x,mouse_y)){
	TbTP.setFillColor(sf::Color::Blue);
	if(isPush){
		w.draw(TbTP);
		showLayer = !showLayer;
	}
}


SquareDrawable bouton1(sizeEcranX-60,3,20,sf::Color::Black);
sf::Text Tb1P("+",font,20);
Tb1P.setPosition(sizeEcranX-58,1);
Tb1P.setFillColor(sf::Color::Black);
bouton1.setFilled(false);
bouton1.draw(w,false);
w.draw(Tb1P);
SquareDrawable bouton2(sizeEcranX-30,3,20,sf::Color::Black);
sf::Text Tb2P("-",font,20);
Tb2P.setPosition(sizeEcranX-25,1);
Tb2P.setFillColor(sf::Color::Black);
bouton2.setFilled(false);
bouton2.draw(w,false);
w.draw(Tb2P);


if(bouton1.isOver(mouse_x,mouse_y)){
	Tb1P.setFillColor(sf::Color::Blue);
	w.draw(Tb1P);
	if(isPush){
		if(nbS < (nbSMax - 1)){
			nbS++;
			SD[nbS].draw(w, mouse_x,mouse_y);
			PointsD[nbS].draw(w, mouse_x, mouse_y);
		}
		
		
	}
}
if(bouton2.isOver(mouse_x,mouse_y)){
	Tb2P.setFillColor(sf::Color::Blue);
	w.draw(Tb2P);
	if(isPush){
		if(nbS > 0){
			nbS--;
			SD[nbS].draw(w, mouse_x, mouse_y);
			PointsD[nbS].draw(w, mouse_x, mouse_y);
		}
	}
}

/*
	AFFICHE LES INFORMATION SUR LA FORME
*/
sf::Text textnbCalque("Numeros du calque:",font,19);
sf::Text nbTCalque("Max",font,19);
sf::Text nbCalque(nbToStr(nbS),font,21);
textnbCalque.setPosition(sizeEcranX-300,0);
nbCalque.setPosition(sizeEcranX-100,0);
nbTCalque.setPosition(sizeEcranX-100,0);
textnbCalque.setFillColor(sf::Color::Black);
nbCalque.setFillColor(sf::Color::Black);
nbTCalque.setFillColor(sf::Color::Black);
w.draw(textnbCalque);
if(nbS==9){
	w.draw(nbTCalque);
}
else
	w.draw(nbCalque);


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

	if((!(menu.browse(1)->isOver(mouse_x,mouse_y) ) &&(sousmenuFichier.browse(0)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(1)->isOver(mouse_x,mouse_y)==false) && (sousmenuFichier.browse(2)->isOver(mouse_x,mouse_y)==false))&&isPush) {
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
	RectangleDrawable GR(xme, yme, 210, yme*6, sf::Color(192,192,192));//rectangle global des option du menu
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme, 200, 31, sf::Color(192,192,192)));//premier rectangle creation d'un rectangle
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme*2, 200, 31, sf::Color(192,192,192)));//46 car 5 car meme niveau que le rectangle 1 +31 pour la hauteur du rectangle 1 +10 d'espace enter le deux rectangle
	tabMenuOutil.add(new RectangleDrawable(xme+5, yme*3, 200, 31, sf::Color(192,192,192)));//option cercle
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*4, 200, 31, sf::Color(192,192,192)));//option Ellipse
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*5, 200, 31, sf::Color(192,192,192)));//option Triangle
	tabMenuOutil.add(new RectangleDrawable(xme+5,yme*6, 200, 31, sf::Color(192,192,192)));//option Polynome

	


	sf::Text creaRect("Rectangle",font,19);
	sf::Text creaRectCtr("Touche R",font,19);
	sf::Text creaCarre("Carre",font,20);
	sf::Text creaCarreCtr("Touche S",font,20);
	sf::Text creaCercle("Cercle",font,20);
	sf::Text creaCercleCtr("Touche C",font,20);
	sf::Text creaEllips("Ellipse",font,20);
	sf::Text creaEllipsCtr("Touche E",font,20);
	sf::Text creaTriangle("Triangle",font,19);
	sf::Text creaTriangleCtr("Touche T",font,19);
	sf::Text creaPoly("Polygones",font,19);
	sf::Text creaPolyCtr("Touche ?",font,19);


	//Position des Textes des boutons
	creaRect.setPosition(xme+5,yme+2);
	creaCarre.setPosition(xme+5,yme*2+2);//yme *nb de forme avant+1(pour lui meme)+2 pour faire un espace
	creaCercle.setPosition(xme+5,yme*3+2);
	creaEllips.setPosition(xme+5,yme*4+2);
	creaTriangle.setPosition(xme+5,yme*5+2);
	creaPoly.setPosition(xme+5,yme*6+2);


	//Position des Textes de controle
	creaRectCtr.setPosition(xme+110,yme+2);	
	creaCarreCtr.setPosition(xme+110,yme*2+2);
	creaCercleCtr.setPosition(xme+110,yme*3+2);
	creaEllipsCtr.setPosition(xme+110,yme*4+2);
	creaTriangleCtr.setPosition(xme+110,yme*5+2);
	creaPolyCtr.setPosition(xme+110,yme*6+2);

	//Couleur des texte
	creaRect.setFillColor(sf::Color::Black);
	creaRectCtr.setFillColor(sf::Color::Black);
	creaCarre.setFillColor(sf::Color::Black);
	creaCarreCtr.setFillColor(sf::Color::Black);
	creaCercle.setFillColor(sf::Color::Black);
	creaCercleCtr.setFillColor(sf::Color::Black);
	creaEllips.setFillColor(sf::Color::Black);
	creaEllipsCtr.setFillColor(sf::Color::Black);
	creaTriangle.setFillColor(sf::Color::Black);
	creaTriangleCtr.setFillColor(sf::Color::Black);
	creaPoly.setFillColor(sf::Color::Black);
	creaPolyCtr.setFillColor(sf::Color::Black);

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


	if((menu.browse(2)->isOver(mouse_x,mouse_y))&&isPush){//permet de savoir si on click sur Edition
		isOverEdition=true;
	}
	
	//permet de savoir si on n'est pas sur un bouton du sous menu
	if(isOverEdition && (GR.isOver(mouse_x,mouse_y))) {
		//ligne de soulignement
		ssEdition=true;
	}

	//si la souris n'est ni le rectangle Edition ni le rectangle du sous menu on ferme le sous menu
	if((!(menu.browse(2)->isOver(mouse_x,mouse_y)) && (GR.isOver(mouse_x,mouse_y)==false))&&isPush) {
		isOverEdition=false;//ferme le sous menu
		ssEdition=false;//ferme le sous menu
	}

	if((isOverEdition==true)||(ssEdition==true)){
		//ligne de soulignement
		w.draw(line1E, 2, sf::Lines);
		w.draw(line2E, 2, sf::Lines);
		w.draw(line3E, 2, sf::Lines);
		
		//affiche les rectangles du menu deroulant
		GR.draw(w,false);
		tabMenuOutil.draw(w,-200,-200);
		//changement de la couleur du text
		textEdition.setFillColor(sf::Color::Blue);
		w.draw(textEdition);
		//~ //afficher les text
		w.draw(creaRect);
		w.draw(creaRectCtr);
		w.draw(creaCarre);
		w.draw(creaCarreCtr);
		w.draw(creaCercle);
		w.draw(creaCercleCtr);
		w.draw(creaEllips);
		w.draw(creaEllipsCtr);
		w.draw(creaTriangle);
		w.draw(creaTriangleCtr);
		w.draw(creaPoly);
		w.draw(creaPolyCtr);
	
		//si on click sur les bouton du sous menu
		if(tabMenuOutil.browse(0)->isOver(mouse_x,mouse_y)){
			creaRect.setFillColor(sf::Color::Blue);
			creaRectCtr.setFillColor(sf::Color::Blue);
			w.draw(creaRect);
			w.draw(creaRectCtr);
			if(isPush){
				j = j + 10;
				SD[nbS].add(new RectangleDrawable(j, 280, 10, 20, sf::Color::Black));
				isOverEdition=false;
				ssEdition=false;
			}
		}
		if(tabMenuOutil.browse(1)->isOver(mouse_x,mouse_y)){
			creaCarre.setFillColor(sf::Color::Blue);
			creaCarreCtr.setFillColor(sf::Color::Blue);
			w.draw(creaCarre);
			w.draw(creaCarreCtr);
			if(isPush){
				j = j + 10;
				SD[nbS].add(new SquareDrawable(j, 260, 10, sf::Color::Yellow));
				isOverEdition=false;
				ssEdition=false;
			}
		}
		if(tabMenuOutil.browse(2)->isOver(mouse_x,mouse_y)){
			creaCercle.setFillColor(sf::Color::Blue);
			creaCercleCtr.setFillColor(sf::Color::Blue);
			w.draw(creaCercle);
			w.draw(creaCercleCtr);
			if(isPush){
				j = j + 10;
				SD[nbS].add(new CircleDrawable(j, 220, 5, sf::Color::Green));
				isOverEdition=false;
				ssEdition=false;
			}
		}
		if(tabMenuOutil.browse(3)->isOver(mouse_x,mouse_y)){
			creaEllips.setFillColor(sf::Color::Blue);
			creaEllipsCtr.setFillColor(sf::Color::Blue);
			w.draw(creaEllips);
			w.draw(creaEllipsCtr);
			if(isPush){
				j = j + 10;
				SD[nbS].add(new EllipseDrawable(j, 240, 10, 5, sf::Color::Black));
				isOverEdition=false;
				ssEdition=false;
			}
			
		}
		if(tabMenuOutil.browse(4)->isOver(mouse_x,mouse_y)){
			creaTriangle.setFillColor(sf::Color::Blue);
			creaTriangleCtr.setFillColor(sf::Color::Blue);
			w.draw(creaTriangle);
			w.draw(creaTriangleCtr);
			if(isPush){
				j = j + 10;
				Point * pointA; pointA = new Point(j, 260);
				Point * pointB; pointB = new Point(j + 20, 280);
				Point * pointC; pointC = new Point(j - 5, 300);
				PointsD[nbS].add(pointA);
				PointsD[nbS].add(pointB);
				PointsD[nbS].add(pointC);
				SD[nbS].add(new TriangleDrawable(pointA, pointB, pointC, sf::Color::Green));
				isOverEdition=false;
				ssEdition=false;
			}
		}
		if(tabMenuOutil.browse(5)->isOver(mouse_x,mouse_y)){
			creaPoly.setFillColor(sf::Color::Blue);
			creaPolyCtr.setFillColor(sf::Color::Blue);
			w.draw(creaPoly);
			w.draw(creaPolyCtr);
			if(isPush){
				std::cout<<"pas d'implementation pour polynome"<<std::endl;
			}
		}




	}
isoverFichier=isOverFichier;
isoverEdition=isOverEdition;


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
	uint sizeEX=(sizeEcranX/4);
	uint sizeEY=(sizeEcranY/4);
	RectangleDrawable ecranAidee(sizeEX,sizeEY,sizeEX*2,sizeEY*2.5,sf::Color::Black);
	ecranAidee.setFilled(false);
	ecranAidee.setBorderSize(10);
	//redaction du texte d'aide
	sf::Text test("\t\tBienvenu dans le Menu d'aide\nvoici quelque racourcies utile:\nZ pour afficher le calque supperieur\nX pour afficher le calque inferieur\nA pour afficher tout les calque",font,19);
	test.setPosition(sizeEX+12,sizeEY+12);
	test.setFillColor(sf::Color::Black);

	if((menu.browse(3)->isOver(mouse_x,mouse_y))&&isPush) {//permet de savoir si on click sur aidee
		textHelp.setFillColor(sf::Color::Blue);
		w.draw(textHelp);
		isOverAidee=true;
	}
	if( !(menu.browse(3)->isOver(mouse_x,mouse_y))&&isPush){
		isOverAidee=false;
	}
	
	if(isOverAidee){
		ecranAidee.draw(w,false);//affiche "l'ecran d'aidee"
		w.draw(test);









	}
isoverAidee=isOverAidee;

}
Menu::~Menu(){};

