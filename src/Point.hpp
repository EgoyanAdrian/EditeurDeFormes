#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

typedef unsigned int uint;

template <typename ...> class Point;	// Needed to use multiple template on a single class

template <typename WindowT, typename ColorT>
class Point<WindowT, ColorT> {
		static const uint rad = 3;
		uint x;
		uint y;
		ColorT color;
		bool selected;

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
		inline bool isOver(uint _x, uint _y) const { return (x == _x && y == _y);}
		void update(uint _x, uint _y);

		inline virtual void draw(WindowT & window, bool isActive) const { }

		//friend std::ostream & operator <<(std::ostream & os, const Point<WindowT, ColorT> & _orig);
		//friend std::istream & operator >>(std::istream & is, Point<WindowT, ColorT> & _orig);
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
	is >> color;
}

template <typename WindowT, typename ColorT>
Point<WindowT, ColorT>::~Point()
{ }

template <typename WindowT, typename ColorT>
void Point<WindowT, ColorT>::update(uint _x, uint _y) {
	if (selected) {
		x = _x - (x - _x);
		y = _y - (y - _y);
	}
}
/*
template <typename WindowT, typename ColorT>
std::ostream & Point<WindowT, ColorT>::operator<<(std::ostream & os, const Point<WindowT, ColorT> & _orig) {
	x >> os;
	y >> os;
	color >> os;
}

template <typename WindowT, typename ColorT>
std::istream & Point<WindowT, ColorT>::operator>>(std::istream & is, Point<WindowT, ColorT> & _orig) {
	is >> x;
	is >> y;
	is >> color;
}
*/
#endif