#include "Color.hpp"

namespace edf {

Color::Color(sf::Color _color)
:sf::Color(_color)
{ }

Color::Color(sf::Uint32 _color)
:sf::Color(_color)
{ }

Color::~Color()
{ }

std::ostream & operator << (std::ostream & os, const Color & _color) {
	os << _color.toInteger();

	return os;
}

std::istream & operator >> (std::istream & is, Color & _color) {
	sf::Uint32 _colUint;
	is >> _colUint;
	edf::Color _colCop(_colUint);

	_color = _colCop;

	return is;
}

}