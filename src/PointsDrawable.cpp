#include "PointsDrawable.hpp"

PointsDrawable::PointsDrawable(uint size)
:Points(size)
{ }

PointsDrawable::~PointsDrawable()
{ }

void PointsDrawable::draw(sf::RenderWindow & window, uint _mX, uint _mY) const {
	sf::CircleShape circle;
	for(uint i = 0; i < this->getNbPoints(); i++) {
		circle.setRadius(this->browse(i)->getRadius());
		circle.setPosition(this->browse(i)->getX() - circle.getRadius(), this->browse(i)->getY() - circle.getRadius());

		if(this->browse(i)->getSelected())
			circle.setFillColor(sf::Color::Red);
		else if(this->browse(i)->isOver(_mX, _mY))
			circle.setFillColor(sf::Color::Blue);
		else
			circle.setFillColor(sf::Color::Black);

		window.draw(circle);
	}
}