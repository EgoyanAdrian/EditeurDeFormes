#ifndef SHAPES_DRAWABLE_HPP
#define SHAPES_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Shapes.hpp"

class ShapesDrawable : public Shapes<sf::RenderWindow, sf::Color> {
	public:
		ShapesDrawable(uint size = 200);
		~ShapesDrawable();

		void draw(sf::RenderWindow & window, uint _mX, uint _mY) const override;
};

ShapesDrawable::ShapesDrawable(uint size)
:Shapes<sf::RenderWindow, sf::Color>(size)
{ }

ShapesDrawable::~ShapesDrawable()
{ }

void ShapesDrawable::draw(sf::RenderWindow & window, uint _mX, uint _mY) const {
	for(uint i = 0; i < this->getNbShapes(); i++)
		this->browse(i)->draw(window, this->browse(i)->isOver(_mX, _mY));
}

#endif