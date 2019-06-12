#include "TriangleDrawable.hpp"

TriangleDrawable::TriangleDrawable(uint _x, uint _y, uint _x1, uint _y1, uint _x2, uint _y2, edf::Color _color)
:Triangle<sf::RenderWindow, edf::Color>(_x, _y, _x1, _y1, _x2, _y2, _color)
{ }

TriangleDrawable::TriangleDrawable(Point * _anchor, Point * _anchor1, Point * _anchor2, edf::Color _color)
:Triangle<sf::RenderWindow, edf::Color>(_anchor, _anchor1, _anchor2, _color)
{ }

TriangleDrawable::TriangleDrawable(const TriangleDrawable & _origin)
:Triangle<sf::RenderWindow, edf::Color>(_origin)
{ }

TriangleDrawable::TriangleDrawable(std::istream & is)
:Triangle<sf::RenderWindow, edf::Color>(is)
{ }

TriangleDrawable::~TriangleDrawable()
{ }

void TriangleDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::Color color;

	if(this->getSelected())
		color = sf::Color::Red;
	else if(isActive)
		color = sf::Color::Blue;
	else
		color = this->getColor();

	sf::Vertex triangle[] = {
		sf::Vertex(sf::Vector2f(this->getAnchor()->getX(), this->getAnchor()->getY()), color),
		sf::Vertex(sf::Vector2f(this->getAnchor1()->getX(), this->getAnchor1()->getY()), color),
		sf::Vertex(sf::Vector2f(this->getAnchor2()->getX(), this->getAnchor2()->getY()), color)
	};

	if(this->getFilled())
		window.draw(triangle, 3, sf::TriangleStrip);
	else if(!this->getFilled()) {
		sf::Vertex line1[] = {
			sf::Vertex(sf::Vector2f(this->getAnchor()->getX(), this->getAnchor()->getY()), color),
			sf::Vertex(sf::Vector2f(this->getAnchor1()->getX(), this->getAnchor1()->getY()), color)
		};

		sf::Vertex line2[] = {
			sf::Vertex(sf::Vector2f(this->getAnchor1()->getX(), this->getAnchor1()->getY()), color),
			sf::Vertex(sf::Vector2f(this->getAnchor2()->getX(), this->getAnchor2()->getY()), color)
		};

		sf::Vertex line3[] = {
			sf::Vertex(sf::Vector2f(this->getAnchor2()->getX(), this->getAnchor2()->getY()), color),
			sf::Vertex(sf::Vector2f(this->getAnchor()->getX(), this->getAnchor()->getY()), color)
		};

		window.draw(line1, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(line3, 2, sf::Lines);
	}
}

void TriangleDrawable::save(std::ostream & os) const {
	os << "Triangle" << std::endl;
	os << this->getAnchor()->getX() << std::endl;
	os << this->getAnchor()->getY() << std::endl;
	os << this->getAnchor1()->getX() << std::endl;
	os << this->getAnchor1()->getY() << std::endl;
	os << this->getAnchor2()->getX() << std::endl;
	os << this->getAnchor2()->getY() << std::endl;
	os << this->getColor() << std::endl;
	os << this->getFilled() << std::endl;
	os << this->getBorderSize() << std::endl;
}

void TriangleDrawable::load(std::istream & is) {
	uint _borderSize;
	edf::Color _color;
	bool _filled;

	is >> _color;
	is >> _filled;
	is >> _borderSize;

	this->setColor(_color);
	this->setFilled(_filled);
	this->setBorderSize(_borderSize);
}