#include <Drawable/SquareDrawable.hpp>

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

void SquareDrawable::save(std::ostream & os) const {
	os << "Square" << std::endl;
	os << this->getAnchor()->getX() << std::endl;
	os << this->getAnchor()->getY() << std::endl;
	os << this->getSide() << std::endl;
	os << this->getColor() << std::endl;
	os << this->getFilled() << std::endl;
	os << this->getBorderSize() << std::endl;
}

void SquareDrawable::load(std::istream & is) {
	uint _side, _borderSize;
	edf::Color _color;
	bool _filled;

	is >> _side;
	is >> _color;
	is >> _filled;
	is >> _borderSize;

	this->setSide(_side);
	this->setColor(_color);
	this->setFilled(_filled);
	this->setBorderSize(_borderSize);
}