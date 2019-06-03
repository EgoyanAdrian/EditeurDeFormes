#ifndef DRAWABLE_POINT_HPP
#define DRAWABLE_POINT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class DrawablePoint : public Point<sf::RenderWindow, sf::Color> {
	public:
	// Constructor and Destructor
		DrawablePoint(uint _x, uint _y, sf::Color _def, sf::Color _hov, sf::Color _sel);
		DrawablePoint(uint _x, uint _y); // Simpler usage but color need to be set separatly
		DrawablePoint(DrawablePoint & _orig);
		//DrawablePoint(istream & is); TO DO
		DrawablePoint() = delete;
		~DrawablePoint();

	//  Other methods
		void draw(sf::RenderWindow & fenetre, bool isActive = false) const override;
};

DrawablePoint::DrawablePoint(uint _x, uint _y, sf::Color _def, sf::Color _hov, sf::Color _sel)
:Point<sf::RenderWindow, sf::Color>(_x, _y, _def, _hov, _sel)
{ }

DrawablePoint::DrawablePoint(uint _x, uint _y)
:Point<sf::RenderWindow, sf::Color>(_x, _y)
{ }

DrawablePoint::DrawablePoint(DrawablePoint & _orig)
:Point<sf::RenderWindow, sf::Color>(_orig.getX(), _orig.getY(), _orig.getDef(), _orig.getHov(), _orig.getSel())
{ }

void DrawablePoint::draw(sf::RenderWindow & fenetre, bool isActive) const {
	sf::CircleShape circle;
	circle.setPosition(this->getX(), this->getY());
	circle.setRadius(this->getSize());

	if (this->getSelected())
		circle.setFillColor(this->getSel());
	else if (isActive)
		circle.setFillColor(this->getHov());
	else
		circle.setFillColor(this->getDef());

	fenetre.draw(circle);
}

DrawablePoint::~DrawablePoint()
{ }

#endif