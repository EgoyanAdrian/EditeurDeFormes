#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Ellipse.hpp"

class EllipseDrawable : public Ellipse<sf::RenderWindow, edf::Color> {
	public:
		EllipseDrawable(uint _x, uint _y, uint _width, uint _height, edf::Color _color);
		EllipseDrawable(Point * _anchor, uint _width, uint _height, edf::Color _color);
		EllipseDrawable(const EllipseDrawable & _origin);
		EllipseDrawable(std::istream & is);
		~EllipseDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif