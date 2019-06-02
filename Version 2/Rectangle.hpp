#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <fstream>
#include "Forme.hpp"

class Rectangle : public Forme
{
	private:
		uint largeur;
		uint hauteur;
		
	public:
		Rectangle(std::string _couleur,uint _x,uint _y , uint _largeur, uint _hauteur);
		Rectangle(const Rectangle &orig);
		Rectangle(std::istream &is);
		Rectangle()=delete;
		~Rectangle(); //en premier le ~Rectangle puis ~forme
		//void dessiner(sf::RenderWindow & w,bool isActive,uint mx,uint my,bool isPush=false) override ;
		inline uint getLargeur(){return largeur;};
		inline void setLargeur(uint _largeur){largeur=_largeur;};
		inline uint getHauteur(){return hauteur;};
		inline void setHauteur(uint _hauteur){hauteur=_hauteur;};
		inline double perimetre() const override {return 2*(largeur+hauteur);};
		void ecrire(std::ostream &os) const;
		bool isOver(uint _x,uint _y) const;
};

#endif

