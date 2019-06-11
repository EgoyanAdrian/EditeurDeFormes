#include "CircleDrawable.hpp"

CircleDrawable::CircleDrawable(uint _x, uint _y, uint _radius, edf::Color _color)
:Circle<sf::RenderWindow, edf::Color>(_x, _y, _radius, _color)
{ }

CircleDrawable::CircleDrawable(Point * _anchor, uint _radius, edf::Color _color)
:Circle<sf::RenderWindow, edf::Color>(_anchor, _radius, _color)
{ }

CircleDrawable::CircleDrawable(const CircleDrawable & _origin)
:Circle<sf::RenderWindow, edf::Color>(_origin)
{ }

CircleDrawable::CircleDrawable(std::istream & is)
:Circle<sf::RenderWindow, edf::Color>(is)
{ }

CircleDrawable::~CircleDrawable()
{ }

void CircleDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::CircleShape circle;
	sf::Vector2f pos(this->getAnchor()->getX(), this->getAnchor()->getY());

	circle.setPosition(pos);
	circle.setRadius(this->getRadius());
	circle.setOutlineThickness(this->getBorderSize());

	if(this->getSelected()) {
		circle.setFillColor(sf::Color::Red);
		circle.setOutlineColor(sf::Color::Red);
	} else if(isActive) {
		circle.setFillColor(sf::Color::Blue);
		circle.setOutlineColor(sf::Color::Blue);
	} else {
		circle.setFillColor(this->getColor());
		circle.setOutlineColor(this->getColor());
	}

	if(!this->getFilled())
		circle.setFillColor(sf::Color::White);

	window.draw(circle);
}