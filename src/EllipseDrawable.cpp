#include "EllipseDrawable.hpp"

EllipseDrawable::EllipseDrawable(uint _x, uint _y, uint _width, uint _height, edf::Color _color)
:Ellipse<sf::RenderWindow, edf::Color>(_x, _y, _width, _height, _color)
{ }

EllipseDrawable::EllipseDrawable(Point * _anchor, uint _width, uint _height, edf::Color _color)
:Ellipse<sf::RenderWindow, edf::Color>(_anchor, _width, _height, _color)
{ }

EllipseDrawable::EllipseDrawable(const EllipseDrawable & _origin)
:Ellipse<sf::RenderWindow, edf::Color>(_origin)
{ }

EllipseDrawable::EllipseDrawable(std::istream & is)
:Ellipse<sf::RenderWindow, edf::Color>(is)
{ }

EllipseDrawable::~EllipseDrawable()
{ }

void EllipseDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::Vector2f pos(this->getAnchor()->getX(), this->getAnchor()->getY());
	sf::CircleShape ellipse;

	ellipse.setPosition(pos);
	ellipse.setRadius(1);
	ellipse.setScale(this->getWidth(), this->getHeight());
	ellipse.setOutlineThickness(this->getBorderSize());

	if(this->getSelected()) {
		ellipse.setFillColor(sf::Color::Red);
		ellipse.setOutlineColor(sf::Color::Red);
	} else if(isActive) {
		ellipse.setFillColor(sf::Color::Blue);
		ellipse.setOutlineColor(sf::Color::Blue);
	} else {
		ellipse.setFillColor(this->getColor());
		ellipse.setOutlineColor(this->getColor());
	}

	if(!this->getFilled())
		ellipse.setFillColor(sf::Color::White);

	window.draw(ellipse);
}