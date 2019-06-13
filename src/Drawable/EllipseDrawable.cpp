#include <Drawable/EllipseDrawable.hpp>

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

void EllipseDrawable::save(std::ostream & os) const {
	os << "Ellipse" << std::endl;
	os << this->getAnchor()->getX() << std::endl;
	os << this->getAnchor()->getY() << std::endl;
	os << this->getWidth() << std::endl;
	os << this->getHeight() << std::endl;
	os << this->getColor() << std::endl;
	os << this->getFilled() << std::endl;
	os << this->getBorderSize() << std::endl;
}

void EllipseDrawable::load(std::istream & is) {
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