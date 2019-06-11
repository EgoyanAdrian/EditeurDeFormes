#ifndef COLOR_HPP
#define COLOR_HPP

#include "iostream"
#include <SFML/Graphics.hpp>

namespace edf {

class Color : public sf::Color {
	public:
		Color(sf::Color _color = sf::Color::Black);
		Color(sf::Uint32 & _color);
		Color(sf::Uint32 _color);
		~Color();

		friend std::ostream & operator<<(std::ostream &os, const Color &color);
		friend std::istream & operator>>(std::istream & is, const Color & color);
};

}
#endif