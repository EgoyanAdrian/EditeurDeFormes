#include <EDF/Point.hpp>

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
