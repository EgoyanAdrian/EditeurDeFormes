#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Rectangle.hpp"

class RectangleDrawable : public Rectangle<sf::RenderWindow, edf::Color> {
	public:
		RectangleDrawable(uint _x, uint _y, uint _width, uint _height, edf::Color _color);
		RectangleDrawable(Point * _anchor, uint _width, uint _height, edf::Color _color);
		RectangleDrawable(const RectangleDrawable & _origin);
		RectangleDrawable(std::istream & is);
		~RectangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;

		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif