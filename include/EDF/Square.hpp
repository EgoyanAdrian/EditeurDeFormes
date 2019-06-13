#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <EDF/Shape.hpp>

template <typename ...> class Square<WindowT, ColorT>;

template <typename WindowT, typename ColorT>
class Square<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		uint side;

	public:
		Square(uint _x, uint _y, uint _side, ColorT _color);
		Square(Point * _anchor, uint _side, ColorT _color);
		Square(const Square<WindowT, ColorT> & _origin);
		Square(std::istream & is);
		~Square();

		inline uint getSide() const { return side;}
		inline void setSide(uint _side) { side = _side;}

		inline bool isOver(uint _x, uint _y) const override { return ((this->getAnchor()->getX() < _x) && ((this->getAnchor()->getX() + side) > _x) && (this->getAnchor()->getY() < _y) && ((this->getAnchor()->getY() + side) > _y));}
		inline virtual void draw(WindowT & window, bool isActive) const override { };
};

template <typename WindowT, typename ColorT>
Square<WindowT, ColorT>::Square(uint _x, uint _y, uint _side, ColorT _color)
:Shape<WindowT, ColorT>(_x, _y, _color), side(_side)
{ }

template <typename WindowT, typename ColorT>
Square<WindowT, ColorT>::Square(Point * _anchor, uint _side, ColorT _color)
:Shape<WindowT, ColorT>(_anchor, _color), side(_side)
{ }

template <typename WindowT, typename ColorT>
Square<WindowT, ColorT>::Square(const Square<WindowT, ColorT> & _origin)
:Square<WindowT, ColorT>(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), _origin.getSide(), _origin.getColor())
{ }

template <typename WindowT, typename ColorT>
Square<WindowT, ColorT>::Square(std::istream & is)
:Shape<WindowT, ColorT>(is) {
	is >> side;
}

template <typename WindowT, typename ColorT>
Square<WindowT, ColorT>::~Square()
{ }

#endif