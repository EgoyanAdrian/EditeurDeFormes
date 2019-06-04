#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "Point.hpp"

class PointDrawable : public Point<sf::RenderWindow, sf::Color> {
	public:
		PointDrawable(uint _x, uint _Y, sf::Color _color);
		PointDrawable(const PointDrawable & _orig);
		PointDrawable(std::istream & is);
		~PointDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

PointDrawable::PointDrawable(uint _x, uint _y, sf::Color _color)
:Point<sf::RenderWindow, sf::Color>(_x, _y, _color)
{ }

PointDrawable::PointDrawable(const PointDrawable & _orig)
:Point<sf::RenderWindow, sf::Color>(_orig.getX(), _orig.getY(), _orig.getCol())
{ }

PointDrawable::PointDrawable(std::istream & is)
:Point<sf::RenderWindow, sf::Color>(is)
{ }

PointDrawable::~PointDrawable()
{ }

void PointDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::CircleShape shape;
	shape.setRadius(this->getRad());
	shape.setPosition(this->getX(), this->getY());

	if(this->getSel())
		shape.setFillColor(sf::Color::Red);
	else if(isActive)
		shape.setFillColor(sf::Color::Blue);
	else
		shape.setFillColor(this->getCol());
	
	window.draw(shape);
}

#endif