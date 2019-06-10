#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point.hpp"

template <typename ...> class Shape;

template <typename WindowT, typename ColorT>
class Shape<WindowT, ColorT> {
		Point * anchor;
		ColorT color;
		bool selected = false, filled = true;
		int borderSize = -1;

	public:
		Shape(uint _x, uint _y, ColorT _color);
		Shape(Point * _anchor, ColorT _color);
		Shape(const Shape<WindowT, ColorT> & _origin);
		Shape(std::istream & is);
		virtual ~Shape();

		inline Point * getAnchor() const { return anchor;}
		inline virtual void setAnchorXY(uint _x, uint _y) { anchor->setX(_x); anchor->setY(_y);}
		inline void setAnchor(Point * _anchor) { anchor = _anchor;}

		inline ColorT getColor() const { return color;}
		inline void setColor(ColorT _color) { color = _color;}

		inline bool getSelected() const { return selected;}
		inline void setSelected(bool _selected) { selected = _selected;}

		inline bool getFilled() const { return filled;}
		inline void setFilled(bool _filled) { filled = _filled;}

		inline int getBorderSize() const { return borderSize;}
		inline void setBorderSize(int _borderSize) { borderSize = _borderSize;}

		inline virtual bool isOver(uint _x, uint _y) const { return anchor->isOver(_x, _y);}
		inline virtual void draw(WindowT & window, bool isActive) const { }
};

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(uint _x, uint _y, ColorT _color)
:color(_color) {
	this->anchor = new Point(_x, _y);
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(Point * _anchor, ColorT _color)
:anchor(_anchor), color(_color)
{ }

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(const Shape<WindowT, ColorT> & _origin)
:Shape(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), _origin.getColor())
{ }

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(std::istream & is) {
	uint _x, _y;
	is >> _x;
	is >> _y;
	this->setAnchorXY(_x, _y);
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::~Shape()
{ }

#endif
