#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <EDF/Point.hpp>

/*! Classe initiale de toutes les formes, utilisation des templates pour faciliter la portabilite que ce soit pour les fenetres ou la facon dont est gere la couleur. Les methodes sont prototype et definit dans le .hpp pour les templates */

template <typename ...> class Shape;

template <typename WindowT, typename ColorT> //WindowT est le type que possedera la fenetre et ColorT le type de la couleur
class Shape<WindowT, ColorT> {
		Point * anchor;
		ColorT color;
		bool selected = false, filled = true;
		int borderSize = -1;

	public:
		Shape(uint _x, uint _y, ColorT _color);
		Shape(Point * _anchor, ColorT _color);
		//!
		//! L'utilisation d'un pointeur sur une ancre Point pour construire une Shape<WindowT, ColorT> permet d'utiliser les points partages
		//!
		Shape(const Shape<WindowT, ColorT> & _origin);
		Shape(std::istream & is);
		virtual ~Shape();

		inline Point * getAnchor() const { return anchor;}
		inline virtual void setAnchorXY(uint _x, uint _y) { anchor->setX(_x); anchor->setY(_y);}
		inline void setAnchor(Point * _anchor) { anchor = _anchor;}

		inline ColorT getColor() const { return color;}
		inline void setColor(ColorT _color) { color = _color;}

		inline bool getSelected() const { return selected;}
		inline void setSelected(bool _selected) { selected = _selected;}

		inline bool getFilled() const { return filled;}
		inline void setFilled(bool _filled) { filled = _filled;}

		inline int getBorderSize() const { return borderSize;}
		inline void setBorderSize(int _borderSize) { borderSize = _borderSize;}

		inline virtual bool isOver(uint _x, uint _y) const { return anchor->isOver(_x, _y);}
		//!
		//! Methode qui recoit des coordonnes et utilise la methode isOver de Point pour savoir si les coordonnes se superposent avec les valeurs de l'ancre
		//!
		inline virtual void draw(WindowT & window, bool isActive) const { }
		//!
		//! Override par toutes les formes Drawable, elle est necessaire ici puisque la classe Shapes utilise un tableau de Shape, la mathode etant override dans les Drawable, elle permet d'afficher les formes sur une fenetre donnees en parametres
		//!
		inline virtual void save(std::ostream & os) const { }
		inline virtual void load(std::istream & is) { }
};

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(uint _x, uint _y, ColorT _color)
:color(_color) {
	this->anchor = new Point(_x, _y);
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(Point * _anchor, ColorT _color)
:anchor(_anchor), color(_color)
{ }

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(const Shape<WindowT, ColorT> & _origin)
:Shape(_origin.getAnchor()->getX(), _origin.getAnchor()->getY(), _origin.getColor())
{ }

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::Shape(std::istream & is) {
	uint _x, _y;
	is >> _x;
	is >> _y;
	this->setAnchorXY(_x, _y);
}

template <typename WindowT, typename ColorT>
Shape<WindowT, ColorT>::~Shape()
{ }

#endif
