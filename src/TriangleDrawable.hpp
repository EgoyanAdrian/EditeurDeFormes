#ifndef TRIANGLE_DRAWABLE_HPP
#define TRIANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Triangle.hpp"

class TriangleDrawable : public Triangle<sf::RenderWindow, sf::Color> {
	public:
		TriangleDrawable(uint _x, uint _y, sf::Color _color, uint _x1, uint _y1, uint _x2, uint _y2);
		TriangleDrawable(Point * _anchor, sf::Color _color, Point * _anchor1, Point * _anchor2);
		~TriangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif