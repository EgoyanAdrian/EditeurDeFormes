#ifndef CIRCLE_DRAWABLE_HPP
#define CIRCLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Circle.hpp"

class CircleDrawable : public Circle<sf::RenderWindow, edf::Color> {
	public:
		CircleDrawable(uint _x, uint _y, uint _radius, edf::Color _color);
		CircleDrawable(Point * _anchor, uint _radius, edf::Color _color);
		CircleDrawable(const CircleDrawable & _origin);
		CircleDrawable(std::istream & is);
		~CircleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif