/*creation du Menu*/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>  
#include <SFML/Graphics.hpp>
#include "PointsDrawable.hpp"
#include "ShapesDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "menuOutils.hpp"


class Menu{
		uint sizeEcranX;
		uint sizeEcranY;
		bool isOverFichier,ssFich;
		bool isOverEdition,ssEdition;
		ShapesDrawable menu=ShapesDrawable(4);
		ShapesDrawable sousmenuFichier=ShapesDrawable(3);
		ShapesDrawable tabMenuOutil=ShapesDrawable(10);//sous Menu de Edition

	
	public:
		Menu(uint _sizeX,uint _sizeY,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w);
		Menu()=delete;
		~Menu();

		
		//Getteur
		inline uint getsizeEcranX(){return sizeEcranX;};
		inline uint getsizeEcranY(){return sizeEcranY;};
		//Setteur
		inline void setsizeEcranX(uint _sizeX){sizeEcranX=_sizeX;};
		inline void setsizeEcranY(uint _sizeY){sizeEcranY=_sizeY;};
		//auter fonction
		inline void closeWindow(sf::RenderWindow &w){w.close();};
		//fonction qui sauvegarde
		
		//fonction qui charge un fichier
		//void ouvre(std::string monFichier);
};
#endif
