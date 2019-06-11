#include "ShapesDrawable.hpp"

ShapesDrawable::ShapesDrawable(uint size)
:Shapes<sf::RenderWindow, edf::Color>(size)
{ }

ShapesDrawable::~ShapesDrawable()
{ }

void ShapesDrawable::draw(sf::RenderWindow & window, uint _mX, uint _mY) const {
	for(uint i = 0; i < this->getNbShapes(); i++)
		this->browse(i)->draw(window, this->browse(i)->isOver(_mX, _mY));
}