#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Ellipse.hpp"

class EllipseDrawable : public Ellipse<sf::RenderWindow, sf::Color> {
	public:
		EllipseDrawable(uint _x, uint _y, uint _width, uint _height, sf::Color _color);
		EllipseDrawable(Point * _anchor, uint _width, uint _height, sf::Color _color);
		EllipseDrawable(const EllipseDrawable & _origin);
		EllipseDrawable(std::istream & is);
		~EllipseDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif