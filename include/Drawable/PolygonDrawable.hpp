#ifndef POLYGON_DRAWABLE_HPP
#define POLYGON_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <Drawable/Color.hpp>
#include <EDF/Polygon.hpp>

class PolygonDrawable : public Polygon<sf::RenderWindow, edf::Color> {
	public:
		PolygonDrawable(Point * _anchor, edf::Color _color, uint _maxPoints = 10);
		~PolygonDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif