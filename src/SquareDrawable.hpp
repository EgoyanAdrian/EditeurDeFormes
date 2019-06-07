#ifndef SQUARE_DRAWABLE_HPP
#define SQUARE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Square.hpp"

class SquareDrawable : public Square<sf::RenderWindow, sf::Color> {
	public:
		SquareDrawable(uint _x, uint _y, sf::Color _color, uint _side);
		~SquareDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif