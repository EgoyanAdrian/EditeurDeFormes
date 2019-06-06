#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

template <typename ...> class Circle;

template <typename WindowT, typename ColorT>
class Circle<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		uint radius;

	public:
		Circle(uint _x, uint _y, ColorT _color, uint _radius);
		Circle(Point * _anchor, ColorT _color, uint _radius);
		Circle(const Circle<WindowT, ColorT> & _origin);
		Circle(std::istream & is);
		~Circle();

		inline uint getRadius() const { return radius;}
		inline void setRadius(uint _radius) { radius = _radius;}

		inline bool isOver(uint _x, uint _y) const override { return (((_x - (this->getAnchor()->getX() + radius))*(_x - (this->getAnchor()->getX() + radius)) + (_y - (this->getAnchor()->getY() + radius))*(_y - (this->getAnchor()->getY() + radius)))<= (radius * radius));}
		inline virtual void draw(WindowT & window, bool isActive) const override { }
};

template <typename WindowT, typename ColorT>
Circle<WindowT, ColorT>::Circle(uint _x, uint _y, ColorT _color, uint _radius)
:Shape<WindowT, ColorT>(_x, _y, _color), radius(_radius) 
{ }

template <typename WindowT, typename ColorT>
Circle<WindowT, ColorT>::Circle(Point * _anchor, ColorT _color, uint _radius)
:Shape<WindowT, ColorT>(_anchor, _color), radius(_radius)
{ }

template <typename WindowT, typename ColorT>
Circle<WindowT, ColorT>::Circle(const Circle<WindowT, ColorT> & _origin)
:Circle<WindowT, ColorT>(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), _origin.getColor(), _origin.getRadius())
{ }

template <typename WindowT, typename ColorT>
Circle<WindowT, ColorT>::Circle(std::istream & is)
:Shape<WindowT, ColorT>(is) {
	is >> radius;
}

template <typename WindowT, typename ColorT>
Circle<WindowT, ColorT>::~Circle()
{ }

#endif