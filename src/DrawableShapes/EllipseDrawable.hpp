#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "../BaseShapes/Ellipse.hpp"

class EllipseDrawable : public Ellipse<sf::RenderWindow, edf::Color> {
	public:
		EllipseDrawable(uint _x, uint _y, uint _width, uint _height, edf::Color _color);
		EllipseDrawable(Point * _anchor, uint _width, uint _height, edf::Color _color);
		EllipseDrawable(const EllipseDrawable & _origin);
		EllipseDrawable(std::istream & is);
		~EllipseDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif