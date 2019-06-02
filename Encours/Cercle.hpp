#ifndef CERCLE_HPP
#define CERCLE_HPP
#include <SFML/Graphics.hpp>
#include "Forme.hpp"

class Cercle:public Forme{
		
		uint radius;
		uint nombPoint;
		
		public:
			Cercle(std::string _couleur,uint radius,uint _x,uint _y, std::size_t nombPoint=30);
			Cercle(Cercle &orig);
			Cercle()=delete;
			~Cercle();
			inline uint getRadius(){return radius;};
			inline void setRadius(uint _radius){radius=_radius;};
			inline uint getNombPoint(){return nombPoint;};
			inline void setNombPoint(uint _nombPoint){nombPoint=_nombPoint;};
			inline double perimetre() const  {return radius;};
			bool isOver(uint _x,uint _y)const;

};
#endif
