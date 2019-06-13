#ifndef POINTS_DRAWABLE_HPP
#define POINTS_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <EDF/Points.hpp>

class PointsDrawable : public Points<sf::RenderWindow> {
	public:
		PointsDrawable(uint size = 200);
		~PointsDrawable();

		void draw(sf::RenderWindow & window, uint _mX, uint _mY) const override;
};

#endif