#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"

class RectangleDrawable : public Rectangle<sf::RenderWindow, sf::Color> {
	public:
		RectangleDrawable(uint _x, uint _y, sf::Color _color, uint _width, uint _height);
		~RectangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif