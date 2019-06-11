#include "Point.hpp"

Point::Point(uint _x, uint _y)
:x(_x), y(_y)
{ }

Point::Point(const Point & _origin)
:Point(_origin.getX(), _origin.getY())
{ }

Point::Point(std::istream & is) {
	is >> x;
	is >> y;
}

Point::~Point()
{ }

std::ostream & operator << (std::ostream & os, const Point & _point) {
	os << _point.getX() << std::endl;
	os << _point.getY() << std::endl;

	return os;
}

std::istream & operator >> (std::istream & is, Point & _point) {
	is >> _point;

	return is;
}