#include "TriangleDrawable.hpp"

TriangleDrawable::TriangleDrawable(uint _x, uint _y, sf::Color _color, uint _x1, uint _y1, uint _x2, uint _y2)
:Triangle<sf::RenderWindow, sf::Color>(_x, _y, _color, _x1, _y1, _x2, _y2)
{ }

TriangleDrawable::TriangleDrawable(Point * _anchor, sf::Color _color, Point * _anchor1, Point * _anchor2)
:Triangle<sf::RenderWindow, sf::Color>(_anchor, _color, _anchor1, _anchor2)
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