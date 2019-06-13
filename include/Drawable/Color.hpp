#ifndef COLOR_HPP
#define COLOR_HPP


#include "iostream"
#include <SFML/Graphics.hpp>

namespace edf {
/*! La classe inherite de sf::Color, le gestionnaire de couleur de SFML mais implemente les operateur de flux qui ne sont pas implementer par SFML, cette classe est necessaire pour pouvoir enregistrer et charger des couleurs dans les Shape. Utilisation d'un namespace pour eviter de melanger avec le type Color de SFML. */


class Color : public sf::Color {
	public:
		//!
		//! Ce constructeur permet l'utilisation des couleur presente par defaut dans SFML : sf::Color::Black
		//!
		Color(sf::Color _color = sf::Color::Black);
		//!
		//! Ce constructeur permet d'utiliser le type sf::Uint32 de SFML pour creer des couleurs, utiliser pour le chargement des couleurs de puis un fichier
		//!
		Color(sf::Uint32 _color);
		~Color();

		friend std::ostream & operator<<(std::ostream &os, const Color &color);
		//!
		//! Surchargement de l'operateur de sortit pour permettre l'enregistrement des couleur SFML qui n'est pas initialement implementer
		//!
		friend std::istream & operator>>(std::istream & is, Color & color);
		//!
		//! Surchargement de l'operateur d'entrer pour permettre le chargement des couleurs SFML depuis un fichier
		//!
};

}
#endif