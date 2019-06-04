#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

typedef unsigned int uint;

template <typename ...> class Point;	// Needed to use multiple template on a single class

template <typename WindowT, typename ColorT>
class Point<WindowT, ColorT> {
		static const uint rad = 6;
		uint x;
		uint y;
		ColorT color;
		bool selected = false;

	public:
	// Constructor & Destructor
		Point(uint _X, uint _y, ColorT _color);
		Point(const Point<WindowT, ColorT> & _orig);
		Point(std::istream & is);
		~Point();

	// Getter & Setter
		inline uint getRad() const { return rad;}

		inline uint getX() const { return x;}
		inline void setX(uint _x) { x = _x;} 

		inline uint getY() const { return y;}
		inline void setY(uint _y) { y = _y;}

		inline ColorT getCol() const { return color;}
		inline void setCol(ColorT _color) { color = _color;}

		inline bool getSel() const { return selected;}
		inline void setSel(bool _selected) { selected = _selected;}

	// Other Methods
		inline bool isOver(uint _x, uint _y) const { return (((_x - (x + rad))*(_x - (x + rad)) + (_y - (y + rad))*(_y - (y + rad)))<= (rad * rad));}
		void update(uint _x, uint _y);

		inline virtual void draw(WindowT & window, bool isActive) const { }

		friend std::ostream & operator <<(std::ostream & os, const Point<WindowT, ColorT> & _orig) { os << _orig.getX() << std::endl << _orig.getY() << std::endl; return os;}
		friend std::istream & operator >>(std::istream & is, Point<WindowT, ColorT> & _orig) { uint _x, _y; is >> _x; is >> _y; _orig.setX(_x); _orig.setY(_y); return is;}
};

template <typename WindowT, typename ColorT>
Point<WindowT, ColorT>::Point(uint _x, uint _y, ColorT _color)
:x(_x), y(_y), color(_color)
{ }

template <typename WindowT, typename ColorT>
Point<WindowT, ColorT>::Point(const Point<WindowT, ColorT> & _orig)
:Point(_orig.getX(), _orig.getY(), _orig.getCol())
{ }

template <typename WindowT, typename ColorT>
Point<WindowT, ColorT>::Point(std::istream & is) {
	is >> x;
	is >> y;
}

template <typename WindowT, typename ColorT>
Point<WindowT, ColorT>::~Point()
{ }

template <typename WindowT, typename ColorT>
void Point<WindowT, ColorT>::update(uint _x, uint _y) {
	if (selected) {
		x = _x;
		y = _y;
	}
}

#endif