#ifndef POINTS_DRAWABLE_HPP
#define POINTS_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Points.hpp"

class PointsDrawable : public Points<sf::RenderWindow> {
	public:
		PointsDrawable(uint size = 200);
		~PointsDrawable();

		void draw(sf::RenderWindow & window, uint _mX, uint _mY) const override;
};

PointsDrawable::PointsDrawable(uint size)
:Points(size)
{ }

PointsDrawable::~PointsDrawable()
{ }

void PointsDrawable::draw(sf::RenderWindow & window, uint _mX, uint _mY) const {
	sf::CircleShape circle;
	for(uint i = 0; i < this->getNbPoints(); i++) {
		circle.setRadius(this->browse(i)->getRadius());
		circle.setPosition(this->browse(i)->getX(), this->browse(i)->getY());

		if(this->browse(i)->isOver(_mX, _mY))
			circle.setFillColor(sf::Color::Blue);
		else
			circle.setFillColor(sf::Color::Black);

		window.draw(circle);
	}
}

#endif