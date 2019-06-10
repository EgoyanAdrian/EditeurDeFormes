#include "TriangleDrawable.hpp"

TriangleDrawable::TriangleDrawable(uint _x, uint _y, uint _x1, uint _y1, uint _x2, uint _y2, sf::Color _color)
:Triangle<sf::RenderWindow, sf::Color>(_x, _y, _x1, _y1, _x2, _y2, _color)
{ }

TriangleDrawable::TriangleDrawable(Point * _anchor, Point * _anchor1, Point * _anchor2, sf::Color _color)
:Triangle<sf::RenderWindow, sf::Color>(_anchor, _anchor1, _anchor2, _color)
{ }

TriangleDrawable::TriangleDrawable(const TriangleDrawable & _origin)
:Triangle<sf::RenderWindow, sf::Color>(_origin)
{ }

TriangleDrawable::TriangleDrawable(std::istream & is)
:Triangle<sf::RenderWindow, sf::Color>(is)
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

	sf::Vertex triangle[]={
		sf::Vertex(sf::Vector2f(this->getAnchor()->getX(), this->getAnchor()->getY()), color),
		sf::Vertex(sf::Vector2f(this->getAnchor1()->getX(), this->getAnchor1()->getY()), color),
		sf::Vertex(sf::Vector2f(this->getAnchor2()->getX(), this->getAnchor2()->getY()), color)
	};
	window.draw(triangle, 3, sf::TriangleStrip);
}