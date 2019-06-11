#include "Color.hpp"

namespace edf {

Color::Color(sf::Color _color)
:sf::Color(_color)
{ }

Color::Color(sf::Uint32 & _color)
:sf::Color(_color)
{ }

Color::Color(sf::Uint32 _color)
:sf::Color(_color)
{ }

Color::~Color()
{ }

std::ostream & operator << (std::ostream & os, const Color & _color) {
	os << _color.toInteger() << std::endl;

	return os;
}

std::istream & operator >> (std::istream & is, const Color & _color) {
	is >> _color;

	return is;
}

}