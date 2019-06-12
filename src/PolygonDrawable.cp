#include "PolygonDrawable.hpp"

PolygonDrawable::PolygonDrawable(Point * _anchor, edf::Color _color, uint _maxPoints)
:Polygon<sf::RenderWindow, edf::Color>(_anchor, _color, _maxPoints)
{ }

PolygonDrawable::~PolygonDrawable()
{ }

void PolygonDrawable::draw(sf::RenderWindow & window, bool isActive) const {
	sf::Color color;

	if(this->getSelected())
		color = sf::Color::Red;
	else if(isActive)
		color = sf::Color::Blue;
	else
		color = this->getColor();

	for(uint i = 0; i < this->getNbPoints(); i++) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(this->browse(i)->getX(), this->browse(i)->getY()), color),
				sf::Vertex(sf::Vector2f(this->browse(i + 1)->getX(), this->browse(i + 1)->getY()), color)
			};

			window.draw(line, 2, sf::Lines);
	}
}

void PolygonDrawable::save(std::ostream & os) const {
	os << "Polygon" << std::endl;
	os << this->getAnchor()->getX() << std::endl;
	os << this->getAnchor()->getY() << std::endl;
	os << this->getNbPoints() << std::endl;
	for(uint i = 0; i < this->getNbPoints(); i++) {
		os << this->browse(i)->getX() << std::endl;
		os << this->browse(i)->getY() << std::endl;
	}
	os << this->getColor() << std::endl;
	os << this->getFilled() << std::endl;
	os << this->getBorderSize() << std::endl;
}

void PolygonDrawable::load(std::istream & is) {
	uint _nbPoints, _borderSize;
	edf::Color _color;
	bool _filled;

	is >> _nbPoints;
	for(uint i = 0; i < _nbPoints; i++) {
		Point * p; p = new Point(is);
		this->add(p);
	}

	is >> _color;
	is >> _filled;
	is >> _borderSize;

	this->setColor(_color);
	this->setFilled(_filled);
	this->setBorderSize(_borderSize);
}