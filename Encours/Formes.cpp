#include "Formes.hpp"

Formes::Formes(size_t _taille):maxFormes(_taille),nbFormes(0),Tab_formes(nullptr){
	Tab_formes=new Forme *[maxFormes];
}


Formes::~Formes(){
	for(size_t i=0;i<nbFormes;i++){
		delete Tab_formes[i];
	}
	delete[] Tab_formes;
}





void Formes::ajouter(Forme *forme){
	if(nbFormes>maxFormes){

	}
	nbFormes+=1;
	Tab_formes[nbFormes]=forme;
}


void Formes::sauver(std::ostream &os)const{
	os<<maxFormes<<std::endl;
	os<<nbFormes<<std::endl;
	for(size_t i=0;i<nbFormes;i++){
		os<<(*Tab_formes[i])<<std::endl;
	}
}



void Formes::charger(std::istream &is){
	for(size_t i=0;i<nbFormes;i++)
		delete Tab_formes[i];
	delete Tab_formes;
	nbFormes=0;
	
	is>>maxFormes;
	Tab_formes=new Forme *[maxFormes];
	size_t combien;
	is>>combien;
	for(size_t i=0;i<combien;i++){
		ajouter(Forme::charger(is));
	}
}
