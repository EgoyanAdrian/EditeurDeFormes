#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"

class RectangleDrawable : public Rectangle<sf::RenderWindow, sf::Color> {
	public:
		RectangleDrawable(uint _x, uint _y, uint _width, uint _height, sf::Color _color);
		RectangleDrawable(Point * _anchor, uint _width, uint _height, sf::Color _color);
		RectangleDrawable(const RectangleDrawable & _origin);
		RectangleDrawable(std::istream & is);
		~RectangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif