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
		Polygon(Point * _anchor, ColorT _color, uint _maxPoints = 10);
		~Polygon();

		inline uint getNbPoints() const { return nbPoints;}
		inline uint getMaxPoints() const { return maxPoints;}

		bool isOver(uint _x, uint _y) const override;
		void add(Point * _point) override;
		void remove(uint _x, uint _y);
		Point * browse(uint _i) const;
		inline virtual void draw(WindowT & _window, bool isActive) const override { }
};

template <typename WindowT, typename ColorT>
Polygon<WindowT, ColorT>::Polygon(Point * _point, ColorT _color, uint _maxPoints)
:Shape<WindowT, ColorT>(_point, _color), maxPoints(_maxPoints), nbPoints(0) {
	tabPoints = new Point * [maxPoints];
}

template <typename WindowT, typename ColorT>
Polygon<WindowT, ColorT>::~Polygon() {
	for(uint i = 0; i < nbPoints; i++)
		delete tabPoints[i];

	delete [] tabPoints;
}

template <typename WindowT, typename ColorT>
bool Polygon<WindowT, ColorT>::isOver(uint _x, uint _y) const {
	return false;
}

template <typename WindowT, typename ColorT>
void Polygon<WindowT, ColorT>::add(Point * _point) {
	if(nbPoints >= maxPoints)
		throw std::runtime_error("Plus de places");
	else
		tabPoints[nbPoints++] = _point;
}

template <typename WindowT, typename ColorT>
void Polygon<WindowT, ColorT>::remove(uint _x, uint _y) {
	Point ** tabTempo = new Point * [maxPoints];
	for(uint i = 0, y = 0; i < nbPoints; i++) {
		if(!(tabPoints[i]->isOver(_x, _y))) {
			tabTempo[y] = tabPoints[i];
			y++;
		} else
			delete tabPoints[i];
	}
	nbPoints--;
	tabPoints = tabTempo;
}

template <typename WindowT, typename ColorT>
Point * Polygon<WindowT, ColorT>::browse(uint _i) const {
	if(_i > (nbPoints - 1))
		return tabPoints[0];

	return tabPoints[_i];
}

#endif