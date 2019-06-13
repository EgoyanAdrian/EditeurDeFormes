#ifndef SHAPES_DRAWABLE_HPP
#define SHAPES_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <Drawable/Color.hpp>
#include <EDF/Shapes.hpp>
#include <Drawable/PointsDrawable.hpp>
#include <Drawable/RectangleDrawable.hpp>
#include <Drawable/SquareDrawable.hpp>
#include <Drawable/EllipseDrawable.hpp>
#include <Drawable/CircleDrawable.hpp>
#include <Drawable/TriangleDrawable.hpp>
//#include <Drawable/PolygonDrawable.hpp> !!INCOMPLET

class ShapesDrawable : public Shapes<sf::RenderWindow, edf::Color> {
	public:
		ShapesDrawable(uint size = 200);
		~ShapesDrawable();

		void draw(sf::RenderWindow & window, uint _mX, uint _mY) const override;

		void save(std::ostream & os) const;
		void load(std::istream & is, PointsDrawable & _gestPoints);
};

#endif