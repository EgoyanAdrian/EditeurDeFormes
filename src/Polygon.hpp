#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <iostream>
#include "Shape.hpp"

template <typename ...> class Polygon;

template <typename WindowT, typename ColorT>
class Polygon<WindowT, ColorT> : public Shape<WindowT, ColorT> {
		uint maxPoints, nbPoints;
		Point ** tabPoints;

	public:
		Polygon(uint _maxPoints = 10);
		~Polygon();

		bool isOver(uint _x, uint _y) const override;
		virtual void add(Point * _point);
		virtual void remove(uint _x, uint _y);
		inline virtual void draw(WindowT _window, bool isActive) const override { }
};

template <typename WindowT, typename ColorT>
Polygon<WindowT, ColorT>::Polygon(uint _maxPoints)
{ }

template <typename WindowT, typename ColorT>
Polygon<WindowT, ColorT>::~Polygon() {
	for(uint i = 0; i < nbPoints; i++)
		delete tabPoints[i];

	delete [] tabPoints;
}

template <typename WindowT, typename ColorT>
bool Polygon<WindowT, ColorT>::isOver(uint _x, uint _y) {
	return true;
}

template <typename WindowT, typename ColorT>
void Polygon<WindowT, ColorT>::add(Point * _point) {
	if(nbPoints >= maxPoints)
		throw std::runtime_error("Plus de places");
	else
		tabShapes[nbPoints++] = _point;
}

template <typename WindowT, typename ColorT>
void Polygon<WindowT, ColorT>::remove(uint _x, uint _y) {
	Point ** tabTempo = new Point * [maxPoints];
	for(uint i = 0, y = 0; i < nbPoints; i++) {
		if(!(tabPoints[i]->isOver(_x, _y))) {
			tabTempo[y] = tabPoints[i];
			y++;
		} else
			delete tabShapes[i];
	}
	nbShapes--;
	tabPoints = tabTempo;
}

#endif