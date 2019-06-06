#include "CircleDrawable.hpp"

CircleDrawable::CircleDrawable(uint _x, uint _y, sf::Color _color, uint _radius)
:Circle<sf::RenderWindow, sf::Color>(_x, _y, _color, _radius)
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