#ifndef POINTS_HPP
#define POINTS_HPP

#include <EDF/Point.hpp>

template <typename ...> class Points;

template <typename WindowT>
class Points<WindowT> {
		uint maxPoints, nbPoints;
		Point ** tabPoints;

	public:
		Points(uint size = 200);
		~Points();

		inline uint getNbPoints() const { return nbPoints;}

		void add(Point * _point);
		void remove();

		inline virtual void draw(WindowT & window, uint _mX, uint _mY) const { };
		
		Point * isOver(uint _x, uint _y);
		Point * browse(uint nb) const;

		virtual void save(std::ostream & os) const;
		virtual void load(std::istream & is);
};

template <typename WindowT>
Points<WindowT>::Points(uint size)
:maxPoints(size), nbPoints(0), tabPoints(0) {
	tabPoints = new Point * [maxPoints];
}

template <typename WindowT>
Points<WindowT>::~Points() {
	for(uint i = 0; i < nbPoints; i++)
		delete tabPoints[i];

	delete [] tabPoints;
}

template <typename WindowT>
void Points<WindowT>::add(Point * _point) {
	if(nbPoints >= maxPoints)
		throw std::runtime_error("plus de places");
	else
		tabPoints[nbPoints++] = _point;
}

template <typename WindowT>
void Points<WindowT>::remove() {
	Point ** tabTempo = new Point * [maxPoints];
	for(uint i = 0, y = 0; i < nbPoints; i++) {
		if(!(tabPoints[i]->getSelected())) {
			tabTempo[y] = tabPoints[i];
			y++;
		} else
			delete tabPoints[i];
	}
	nbPoints--;
	tabPoints = tabTempo;
}

template <typename WindowT>
Point * Points<WindowT>::isOver(uint _x, uint _y) {
	for(uint i = 0; i < nbPoints; i++) {
		if(tabPoints[i]->isOver(_x, _y))
			return tabPoints[i];
	}

	return nullptr;
}

template <typename WindowT>
Point * Points<WindowT>::browse(uint nb) const {
	return tabPoints[nb];
}

template <typename WindowT>
void Points<WindowT>::save(std::ostream & os) const {
	os << maxPoints << std::endl;
	os << nbPoints << std::endl;
	for (uint i = 0; i < nbPoints; i++) {
		os << tabPoints[i]->getX() << std::endl << tabPoints[i]->getY() << std::endl;
	}
}

template <typename WindowT>
void Points<WindowT>::load(std::istream & is) {
	is >> maxPoints;
	is >> nbPoints;
	for (uint i = 0; i < nbPoints; i++) {
		tabPoints[i] = new Point(is);
	}
}

#endif