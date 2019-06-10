#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Shape.hpp"

template <typename ...> class Ellipse;

template <typename WindowT, typename ColorT>
class Ellipse<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		uint width, height;

	public:
		Ellipse(uint _x, uint _y, uint _width, uint _height, ColorT _color);
		Ellipse(Point * _anchor, uint _width, uint _height, ColorT _color);
		Ellipse(const Ellipse<WindowT, ColorT> & _origin);
		Ellipse(std::istream & is);
		~Ellipse();

		inline uint getWidth() const { return width;}
		inline void setWidth(uint _width) { width = _width;}

		inline uint getHeight() const { return height;}
		inline void setHeight(uint _height) { height = _height;}

		inline bool isOver(uint _x, uint _y) const override { return (((_x - (this->getAnchor()->getX() + width))*(_x - (this->getAnchor()->getX() + width)) + (_y - (this->getAnchor()->getY() + height))*(_y - (this->getAnchor()->getY() + height)))<= (width * height));}
		inline virtual void draw(WindowT & window, bool isActive) const override { }
};

template <typename WindowT, typename ColorT>
Ellipse<WindowT, ColorT>::Ellipse(uint _x, uint _y, uint _width, uint _height, ColorT _color)
:Shape<WindowT, ColorT>(_x, _y, _color), width(_width), height(_height)
{ }

template <typename WindowT, typename ColorT>
Ellipse<WindowT, ColorT>::Ellipse(Point * _anchor, uint _width, uint _height, ColorT _color)
:Shape<WindowT, ColorT>(_anchor, _color), width(_width), height(_height)
{ }

template <typename WindowT, typename ColorT>
Ellipse<WindowT, ColorT>::Ellipse(const Ellipse<WindowT, ColorT> & _origin)
:Shape<WindowT, ColorT>(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), width(_origin.getWidth()), height(_origin.getHeight(), _origin.getColor()))
{ }

template <typename WindowT, typename ColorT>
Ellipse<WindowT, ColorT>::Ellipse(std::istream & is)
:Shape<WindowT, ColorT>(is) {
	is >> width;
	is >> height;
}

template <typename WindowT, typename ColorT>
Ellipse<WindowT, ColorT>::~Ellipse()
{ }

#endif