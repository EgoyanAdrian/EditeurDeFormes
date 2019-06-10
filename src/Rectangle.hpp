#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

template <typename ...> class Rectangle;

template <typename WindowT, typename ColorT>
class Rectangle<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		uint width, height;

	public:
		Rectangle(uint _x, uint _y, uint _width, uint _height, ColorT _color);
		Rectangle(Point * _anchor, uint _width, uint _height, ColorT _color);
		Rectangle(const Rectangle<WindowT, ColorT> & _origin);
		Rectangle(std::istream & is);
		~Rectangle();

		inline uint getWidth() const { return width;}
		inline void setWidth(uint _width) { width = _width;}

		inline uint getHeight() const { return height;}
		inline void setHeight(uint _height) { height = _height;}

		inline bool isOver(uint _x, uint _y) const override { return (((this->getAnchor()->getX() < _x) && ((this->getAnchor()->getX() + width) > _x)) && ((this->getAnchor()->getY() < _y) && ((this->getAnchor()->getY() + height) > _y)));}
		inline virtual void draw(WindowT & window, bool isActive) const override { };
};

template <typename WindowT, typename ColorT>
Rectangle<WindowT, ColorT>::Rectangle(uint _x, uint _y, uint _width, uint _height, ColorT _color)
:Shape<WindowT, ColorT>(_x, _y, _color), width(_width), height(_height) {
}

template <typename WindowT, typename ColorT>
Rectangle<WindowT, ColorT>::Rectangle(Point * _anchor, uint _width, uint _height, ColorT _color)
:Shape<WindowT, ColorT>(_anchor, _color), width(_width), height(_height)
{ }

template <typename WindowT, typename ColorT>
Rectangle<WindowT, ColorT>::Rectangle(const Rectangle<WindowT, ColorT> & _origin)
:Rectangle<WindowT, ColorT>(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), _origin.getWidth(), _origin.getHeight(), _origin.getColor())
{ }

template <typename WindowT, typename ColorT>
Rectangle<WindowT, ColorT>::Rectangle(std::istream & is)
:Shape<WindowT, ColorT>(is) {
	is >> width;
	is >> height;
}

template <typename WindowT, typename ColorT>
Rectangle<WindowT, ColorT>::~Rectangle()
{ }

#endif