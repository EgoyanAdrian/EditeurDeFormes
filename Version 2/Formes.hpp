#ifndef FORMES_HPP
#define FORMES_HPP
#include <iostream>
#include <fstream>
#include "Forme.hpp"


class Formes{
		size_t maxFormes;
		size_t nbFormes;
		Forme **formes;
	public:
		Formes(size_t taille=200);
		~Formes();
		void ajouter(Formes *forme);
		Forme *isOver(uint _x,uint _y);
		void sauver(std::ostream &os)const;
		void charger(std::istream &is);
		
};



#endif
