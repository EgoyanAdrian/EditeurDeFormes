#ifndef SHAPES_DRAWABLE_HPP
#define SHAPES_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Shapes.hpp"

class ShapesDrawable : public Shapes<sf::RenderWindow, edf::Color> {
	public:
		ShapesDrawable(uint size = 200);
		~ShapesDrawable();

		void draw(sf::RenderWindow & window, uint _mX, uint _mY) const override;
};

#endif