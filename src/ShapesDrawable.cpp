#include "ShapesDrawable.hpp"

ShapesDrawable::ShapesDrawable(uint size)
:Shapes<sf::RenderWindow, edf::Color>(size)
{ }

ShapesDrawable::~ShapesDrawable()
{ }

void ShapesDrawable::draw(sf::RenderWindow & window, uint _mX, uint _mY) const {
	for(uint i = 0; i < this->getNbShapes(); i++)
		this->browse(i)->draw(window, this->browse(i)->isOver(_mX, _mY));
}

void ShapesDrawable::save(std::ostream & os) const {
	os << this->getNbShapes() << std::endl;
	for(uint i = 0; i < this->getNbShapes(); i++) {
		this->browse(i)->save(os);
	}
}

void ShapesDrawable::load(std::istream & is, PointsDrawable & _gestPoints) {
	uint _nbShapes;
	is >> _nbShapes;
	std::string shapeType;
	for(uint i = 0; i < _nbShapes; i++) {
		is >> shapeType;
		Point * p; p = new Point(is);
		_gestPoints.add(p);

		if(shapeType == "Rectangle") {
			this->add(new RectangleDrawable(p, 0, 0, sf::Color::Black));
			this->browse(this->getNbShapes() - 1)->load(is);
		} else if(shapeType == "Square") {
			this->add(new SquareDrawable(p, 0, sf::Color::Black));
			this->browse(this->getNbShapes() - 1)->load(is);
		} else if(shapeType == "Ellipse") {
			this->add(new EllipseDrawable(p, 0, 0, sf::Color::Black));
			this->browse(this->getNbShapes() - 1)->load(is);
		} else if(shapeType == "Circle") {
			this->add(new CircleDrawable(p, 0, sf::Color::Black));
			this->browse(this->getNbShapes() - 1)->load(is);
		} else if(shapeType == "Triangle") {
			Point * p1; p1 = new Point(is);
			_gestPoints.add(p1);
			Point * p2; p2 = new Point(is);
			_gestPoints.add(p2);
			this->add(new TriangleDrawable(p, p1, p2, sf::Color::Black));
			this->browse(this->getNbShapes() - 1)->load(is);
		} else {
			std::cerr << "Forme Inconnue" << std::endl;
		}
	}
}