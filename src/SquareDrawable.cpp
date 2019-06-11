#include "SquareDrawable.hpp"

SquareDrawable::SquareDrawable(uint _x, uint _y, uint _side, edf::Color _color)
:Square<sf::RenderWindow, edf::Color>(_x, _y, _side, _color)
{ }

SquareDrawable::SquareDrawable(Point * _anchor, uint _side, edf::Color _color)
:Square<sf::RenderWindow, edf::Color>(_anchor, _side, _color)
{ }

SquareDrawable::SquareDrawable(const SquareDrawable & _origin)
:Square<sf::RenderWindow, edf::Color>(_origin)
{ }

SquareDrawable::SquareDrawable(std::istream & is)
:Square<sf::RenderWindow, edf::Color>(is)
{ }

SquareDrawable::~SquareDrawable()
{ }

void SquareDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::RectangleShape square;
	sf::Vector2f pos(this->getAnchor()->getX(), this->getAnchor()->getY());
	sf::Vector2f siz(this->getSide(), this->getSide());

	square.setPosition(pos);
	square.setSize(siz);

	square.setOutlineThickness(this->getBorderSize());

	if(this->getSelected()) {
		square.setFillColor(sf::Color::Red);
		square.setOutlineColor(sf::Color::Red);
	} else if(isActive) {
		square.setFillColor(sf::Color::Blue);
		square.setOutlineColor(sf::Color::Blue);
	} else {
		square.setFillColor(this->getColor());
		square.setOutlineColor(this->getColor());
	}

	if(!this->getFilled())
		square.setFillColor(sf::Color::White);

	window.draw(square);
}