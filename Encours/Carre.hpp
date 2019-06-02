#ifndef CARRE_HPP
#define CARRE_HPP

#include <iostream>
#include "Forme.hpp"

class Carre :public Forme{
		
		uint cote;
	
	public:
	//definition de constructeur
		Carre(std::string _couleur,uint _x, uint _y,  uint _cote);
		Carre(const Carre & orig);
		//Carre(std::istream & is);
		Carre()=delete;
		~Carre();
		inline uint getCote(){return cote;};
		inline void setCote(uint _cote){cote=_cote;};
		inline double perimetre() const {return (cote)^2;};
		bool isOver(uint _x,uint _y) const;
};
#endif
