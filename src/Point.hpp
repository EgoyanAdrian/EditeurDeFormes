#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

typedef unsigned int uint;

class Point {
		static const uint radius = 6;
		uint x, y;
		bool selected = false;

	public:
	// Constructor & Destructor
		Point(uint _X, uint _y);
		Point(const Point & _orig);
		Point(std::istream & is);
		~Point();

	// Getter & Setter
		inline uint getRadius() const { return radius;}

		inline uint getX() const { return x;}
		inline void setX(uint _x) { x = _x;} 

		inline uint getY() const { return y;}
		inline void setY(uint _y) { y = _y;}

	// Other Methods
		inline bool isOver(uint _x, uint _y) const { return (((_x - (x + radius))*(_x - (x + radius)) + (_y - (y + radius))*(_y - (y + radius)))<= (radius * radius));}
};

Point::Point(uint _x, uint _y)
:x(_x), y(_y)
{ }

Point::Point(const Point & _orig)
:Point(_orig.getX(), _orig.getY())
{ }

Point::Point(std::istream & is) {
	is >> x;
	is >> y;
}

Point::~Point()
{ }

#endif