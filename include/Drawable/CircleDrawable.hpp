#ifndef CIRCLE_DRAWABLE_HPP
#define CIRCLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <Drawable/Color.hpp>
#include <EDF/Circle.hpp>

class CircleDrawable : public Circle<sf::RenderWindow, edf::Color> {
	public:
		CircleDrawable(uint _x, uint _y, uint _radius, edf::Color _color);
		CircleDrawable(Point * _anchor, uint _radius, edf::Color _color);
		CircleDrawable(const CircleDrawable & _origin);
		CircleDrawable(std::istream & is);
		~CircleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif