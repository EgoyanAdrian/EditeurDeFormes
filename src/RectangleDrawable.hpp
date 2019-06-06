#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"

class RectangleDrawable : public Rectangle<sf::RenderWindow, sf::Color> {
	public:
		RectangleDrawable(uint _x, uint _y, sf::Color _color, uint _width, uint _height);
		~RectangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
};

RectangleDrawable::RectangleDrawable(uint _x, uint _y, sf::Color _color, uint _width, uint _height)
:Rectangle<sf::RenderWindow, sf::Color>(_x, _y, _color, _width, _height)
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
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setOutlineColor(sf::Color::Black);
	}

	if(!this->getFilled())
		rectangle.setFillColor(sf::Color::White);

	window.draw(rectangle);
}

#endif