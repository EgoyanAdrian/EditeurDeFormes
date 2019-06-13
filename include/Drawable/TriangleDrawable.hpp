#ifndef TRIANGLE_DRAWABLE_HPP
#define TRIANGLE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <Drawable/Color.hpp>
#include <EDF/Triangle.hpp>

class TriangleDrawable : public Triangle<sf::RenderWindow, edf::Color> {
	public:
		TriangleDrawable(uint _x, uint _y, uint _x1, uint _y1, uint _x2, uint _y2, edf::Color _color);
		TriangleDrawable(Point * _anchor, Point * _anchor1, Point * _anchor2, edf::Color _color);
		TriangleDrawable(const TriangleDrawable & _origin);
		TriangleDrawable(std::istream & is);
		~TriangleDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif