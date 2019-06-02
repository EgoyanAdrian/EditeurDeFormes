#include "Formes.hpp"

Formes::Formes(size_t _taille):maxFormes(_taille),nbFormes(0),formes(nullptr){
	formes=new Forme[maxFormes];
}
	
Formes::~Formes(){
	for(size_t i=0;i<nbFormes;i++){
		delete formes[i];
	}
	delete[] formes;
}
	
void Formes::sauver(std::ostream &os)const{
	os<<maxFormes<<endl;
	os<<nbFormes<<endl;
	for(size_t i=0;i<nbFormes;i++){
		os<<(*formes[i])<<endl;
	}
}



void Formes::charger(std::istream &is){
	for(size_t i=0;i<nbFormes;i++)
		delete formes[i];
	delete formes;
	nbForme=0;
	
	is>>maxFormes;
	formes=newForme *[maxForme];
	size_t combien;
	is>>combien;
	for(size_t i=0;i<combien;i++){
		ajouter(Forme::charger(is);
	}
}
