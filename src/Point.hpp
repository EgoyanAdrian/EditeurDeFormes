#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

typedef unsigned int uint;

class Point {
		static const uint radius = 3;
		uint x, y;
		bool selected = false;

	public:
	// Constructor & Destructor
		Point(uint _x, uint _y);
		Point(const Point & _origin);
		Point(std::istream & is);
		~Point();

	// Getter & Setter
		inline uint getRadius() const { return radius;}

		inline uint getX() const { return x;}
		inline void setX(uint _x) { x = _x;} 

		inline uint getY() const { return y;}
		inline void setY(uint _y) { y = _y;}

		inline bool getSelected() const { return selected;}
		inline void setSelected(bool _selected) { selected = _selected;}

	// Other Methods
		inline bool isOver(uint _x, uint _y) const { return (((_x - x)*(_x - x) + (_y - y)*(_y - y))<= (radius * radius));}
};

#endif