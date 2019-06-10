#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

template <typename ...> class Triangle;

template <typename WindowT, typename ColorT>
class Triangle<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		Point * anchor1;
		Point * anchor2;

	public:
		Triangle(uint _x, uint _y, ColorT _color, uint _x1, uint _y1, uint _x2, uint _y2);
		Triangle(Point * _anchor, ColorT _color, Point * _anchor1, Point * _anchor2);
		Triangle(const Triangle<WindowT, ColorT> & _origin);
		Triangle(std::istream & is);
		~Triangle();

		void setAnchorXY(uint _x, uint _y) override;

		inline Point * getAnchor1() const { return anchor1;}
		inline void setAnchor1(uint _x, uint _y) { anchor1->setX(_x); anchor1->setY(_y);}

		inline Point * getAnchor2() const { return anchor2;}
		inline void setAnchor2(uint _x, uint _y) { anchor2->setX(_x); anchor2->setY(_y);}

		bool isOver(uint _x, uint _y) const override;
		inline virtual void draw(WindowT & window, bool isActive) const override { }
};

template <typename WindowT, typename ColorT>
Triangle<WindowT, ColorT>::Triangle(uint _x, uint _y, ColorT _color, uint _x1, uint _y1, uint _x2, uint _y2)
:Shape<WindowT, ColorT>(_x, _y, _color) {
	anchor1 = new Point(_x1, _y1);
	anchor2 = new Point(_x2, _y2);
}

template <typename WindowT, typename ColorT>
Triangle<WindowT, ColorT>::Triangle(Point * _anchor, ColorT _color, Point * _anchor1, Point * _anchor2)
:Shape<WindowT, ColorT>(_anchor, _color), anchor1(_anchor1), anchor2(_anchor2)
{ }

template <typename WindowT, typename ColorT>
Triangle<WindowT, ColorT>::Triangle(const Triangle<WindowT, ColorT> & _origin)
:Triangle<WindowT, ColorT>(_origin->getAnchor(), _origin->getColor(), _origin.getAnchor1(), _origin.getAnchor2())
{ }

template <typename WindowT, typename ColorT>
Triangle<WindowT, ColorT>::Triangle(std::istream & is)
:Shape<WindowT, ColorT>(is), anchor1(is), anchor2(is)
{ }

template <typename WindowT, typename ColorT>
Triangle<WindowT, ColorT>::~Triangle()
{ }

template <typename WindowT, typename ColorT>
void Triangle<WindowT, ColorT>::setAnchorXY(uint _x, uint _y) {

	int dif_x = (_x - this->getAnchor()->getX());
	int dif_y = (_y - this->getAnchor()->getY());

	this->getAnchor()->setX(_x);
	this->getAnchor()->setY(_y);

	anchor1->setX(anchor1->getX() + dif_x);
	anchor1->setY(anchor1->getY() + dif_y);

	anchor2->setX(anchor2->getX() + dif_x);
	anchor2->setY(anchor2->getY() + dif_y);
}

template <typename WindowT, typename ColorT>
bool Triangle<WindowT, ColorT>::isOver(uint _x, uint _y) const {

	uint a_x = this->getAnchor()->getX(), a_y = this->getAnchor()->getY();
	uint b_x = anchor1->getX(), b_y = anchor1->getY();
	uint c_x = anchor2->getX(), c_y = anchor2->getY();

	float s = a_y * c_x - a_x * c_y + (c_y - a_y) * _x + (a_x - c_x) * _y;
    float t = a_x * b_y - a_y * b_x + (a_y - b_y) * _x + (b_x - a_x) * _y;

    if ((s < 0) != (t < 0))
        return false;

    float A = -b_y * c_x + a_y * (c_x - b_x) + a_x * (b_y - c_y) + b_x * c_y;

    return A < 0 ?
            (s <= 0 && s + t >= A) :
            (s >= 0 && s + t <= A);
}

#endif