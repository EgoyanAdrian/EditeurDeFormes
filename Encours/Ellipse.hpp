#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP


#include <iostream>
#include <math.h>
#include "ez-draw++.hpp"
#include "Forme.hpp"

class Ellipse:public Forme{
		uint demiLargeur;
		uint demiHauteur;
	public:
		Ellipse(ulong couleur,uint x,uint y,uint demilargeur,uint demiHauteur);
		Ellipse(Ellipse &orig);
		//Ellipse(istream &is);
		Ellipse()=delete;
		~Ellipse();
		void dessiner(EZWindow &fenetre,bool isAcitve=false)const override;
		inline uint getDemiLargeur(){return demiLargeur;};
		inline void setDemiLargeur(uint _demiLargeur){demiLargeur=_demiLargeur;}
		inline uint getDemiHauteur(){return demiHauteur;};
		inline void setDemiHauteur(uint _demiHauteur){demiHauteur=_demiHauteur;};
		inline double perimetre()const {return 2*M_PI*sqrt((((2*demiLargeur)^2)+((2*demiHauteur)^2))/2);};
		bool isOver(uint _x,uint _y)const ;
};
#endif

