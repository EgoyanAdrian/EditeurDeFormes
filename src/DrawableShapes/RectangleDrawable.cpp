#include "RectangleDrawable.hpp"

RectangleDrawable::RectangleDrawable(uint _x, uint _y, uint _width, uint _height, edf::Color _color)
:Rectangle<sf::RenderWindow, edf::Color>(_x, _y, _width, _height, _color)
{ }

RectangleDrawable::RectangleDrawable(Point * _anchor, uint _width, uint _height, edf::Color _color)
:Rectangle<sf::RenderWindow, edf::Color>(_anchor, _width, _height, _color)
{ }

RectangleDrawable::RectangleDrawable(const RectangleDrawable & _origin)
:Rectangle<sf::RenderWindow, edf::Color>(_origin)
{ }

RectangleDrawable::RectangleDrawable(std::istream & is)
:Rectangle<sf::RenderWindow, edf::Color>(is)
{ }

RectangleDrawable::~RectangleDrawable()
{ }

void RectangleDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::RectangleShape rectangle;
	sf::Vector2f pos(this->getAnchor()->getX(), this->getAnchor()->getY());
	sf::Vector2f siz(this->getWidth(), this->getHeight());

	rectangle.setPosition(pos);
	rectangle.setSize(siz);
	rectangle.setOutlineThickness(this->getBorderSize());

	if(this->getSelected()) {
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setOutlineColor(sf::Color::Red);
	} else if(isActive) {
		rectangle.setFillColor(sf::Color::Blue);
		rectangle.setOutlineColor(sf::Color::Blue);
	} else {
		rectangle.setFillColor(this->getColor());
		rectangle.setOutlineColor(this->getColor());
	}

	if(!this->getFilled())
		rectangle.setFillColor(sf::Color::White);

	window.draw(rectangle);
}

void RectangleDrawable::save(std::ostream & os) const {
	os << "Rectangle" << std::endl;
	os << this->getAnchor()->getX() << std::endl;
	os << this->getAnchor()->getY() << std::endl;
	os << this->getWidth() << std::endl;
	os << this->getHeight() << std::endl;
	os << this->getColor() << std::endl;
	os << this->getFilled()<< std::endl;
	os << this->getBorderSize() << std::endl;
}

void RectangleDrawable::load(std::istream & is) {
	uint _width, _height, _borderSize;
	edf::Color _color;
	bool _filled;

	is >> _width;
	is >> _height;
	is >> _color;
	is >> _filled;
	is >> _borderSize;

	this->setWidth(_width);
	this->setHeight(_height);
	this->setColor(_color);
	this->setFilled(_filled);
	this->setBorderSize(_borderSize);
}