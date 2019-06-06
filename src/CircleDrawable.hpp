#ifndef CIRCLE_DRAWABLE_HPP
#define CIRCLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Circle.hpp"

class CircleDrawable : public Circle<sf::RenderWindow, sf::Color> {
	public:
		CircleDrawable(uint _x, uint _y, sf::Color _color, uint _radius);
		~CircleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

#endif