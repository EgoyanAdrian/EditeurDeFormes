#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Ellipse.hpp"

class EllipseDrawable : public Ellipse<sf::RenderWindow, sf::Color> {
	public:
		EllipseDrawable(uint _x, uint _y, sf::Color _color, uint _width, uint _height);
		~EllipseDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif