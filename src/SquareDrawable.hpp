#ifndef SQUARE_DRAWABLE_HPP
#define SQUARE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Square.hpp"

class SquareDrawable : public Square<sf::RenderWindow, edf::Color> {
	public:
		SquareDrawable(uint _x, uint _y, uint _side, edf::Color _color);
		SquareDrawable(Point * _anchor, uint _side, edf::Color _color);
		SquareDrawable(const SquareDrawable & _origin);
		SquareDrawable(std::istream & is);
		~SquareDrawable();

		void draw(sf::RenderWindow & window, bool isActive) const override;
		void save(std::ostream & os) const override;
		void load(std::istream & is) override;
};

#endif