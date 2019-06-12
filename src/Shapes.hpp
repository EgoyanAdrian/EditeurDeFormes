#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "Shape.hpp"

template <typename ...> class Shapes;

template <typename WindowT, typename ColorT>
class Shapes<WindowT, ColorT> {
		uint maxShapes, nbShapes;
		Shape<WindowT, ColorT> ** tabShapes;

	public:
		Shapes(uint size = 200);
		~Shapes();

		inline uint getNbShapes() const { return nbShapes;}

		void add(Shape<WindowT, ColorT> * _shape);
		void remove();

		inline virtual void draw(WindowT & window, uint _mX, uint _mY) const { }
		
		Shape<WindowT, ColorT> * isOver(uint _x, uint _y);
		Shape<WindowT, ColorT> * browse(uint nb) const;
};

template <typename WindowT, typename ColorT>
Shapes<WindowT, ColorT>::Shapes(uint size)
:maxShapes(size), nbShapes(0), tabShapes(nullptr) {
	tabShapes = new Shape<WindowT, ColorT> * [maxShapes];
}

template <typename WindowT, typename ColorT>
Shapes<WindowT, ColorT>::~Shapes() {
	for(uint i = 0; i < nbShapes; i++)
		delete tabShapes[i];

	delete [] tabShapes;
}

template <typename WindowT, typename ColorT>
void Shapes<WindowT, ColorT>::add(Shape<WindowT, ColorT> * _shape) {
	if(nbShapes >= maxShapes)
		throw std::runtime_error("Plus de places");
	else
		tabShapes[nbShapes++] = _shape;
}

template <typename WindowT, typename ColorT>
void Shapes<WindowT, ColorT>::remove() {
	Shape<WindowT, ColorT> ** tabTempo = new Shape<WindowT, ColorT> * [maxShapes];
	for(uint i = 0, y = 0; i < nbShapes; i++) {
		if(!(tabShapes[i]->getSelected())) {
			tabTempo[y] = tabShapes[i];
			y++;
		} else
			delete tabShapes[i];
	}
	nbShapes--;
	tabShapes = tabTempo;
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT> * Shapes<WindowT, ColorT>::isOver(uint _x, uint _y) {
	for(uint i = 0; i < nbShapes; i++) {
		if(tabShapes[i]->isOver(_x, _y)) {
			return tabShapes[i];
		}
	}

	return nullptr;
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT> * Shapes<WindowT, ColorT>::browse(uint nb) const {
	return tabShapes[nb];
}
#endif