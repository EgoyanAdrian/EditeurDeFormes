#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Point.hpp"



class Forme{
		std::string couleur;
		Point ancre;
		bool selected;
	
	protected:
		virtual void ecrire(std::ostream &os) const;
	public:
		Forme (const std::string _Color, uint _x,uint _y);
		Forme (const std::string _couleur, Point _ancre);
		Forme (const Forme & orig);
		Forme(std::istream &is);
		Forme()=delete;
		virtual ~Forme();
		inline std::string getcouleur() const{return couleur;}
		inline void setcouleur(std::string _couleur){couleur=_couleur;}
		inline const Point &getAncre()const{return ancre;};
		inline void setAncre(uint _x, uint _y){ancre.SetXY(_x,_y);}
		bool isOver(uint _x,uint _y) const;
		//virtual double perimetre() const=0;// virtue pur
		friend std::ostream &operator<<(std::ostream &os, const Forme &f);
		static Forme* charger(std::istream & is);
		void move(uint _x,uint _y);
};

#endif
