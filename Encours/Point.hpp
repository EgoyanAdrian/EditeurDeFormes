#ifndef POINT_HPP
#define POINT_HPP


#include <iostream>
#include <SFML/Graphics.hpp>


class Point {
		static const uint taille=3;
		uint x;
		uint y;
	public:
		Point(uint x,uint y);
		Point(const Point & orig);
		Point(std::istream & is);
		Point()=delete;//le construteur point() est bloquer pour le compilateur le creer pas
		~Point();
		inline uint getX() const {return x;};
		inline uint getY() const {return y;};
		bool isOver(uint _x, uint _y) const;
		inline void SetXY(uint _x, uint _y){x=_x;y=_y;};
		friend std::ostream &operator<<(std::ostream &os, const Point & p);
		friend std::istream &operator>>(std::istream &is, Point &p);
};

#endif

