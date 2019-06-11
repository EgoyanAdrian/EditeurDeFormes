#include <SFML/Graphics.hpp>
#include "ShapesDrawable.hpp"
#include "PointsDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "SquareDrawable.hpp"
#include "CircleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "Text.hpp"

class menuOutils{
		ShapesDrawable tabMenuOutil=ShapesDrawable(10);
		ShapesDrawable tabMenuModif=ShapesDrawable(10);
		uint nbrectangle=0;
		uint nbcarre;
		uint nbcercle;
		uint nbelipse;
		uint nbtriangle;
		
	public:
		menuOutils(sf::Event &e,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable &PointsD,ShapesDrawable &SD,sf::Font font);
		~menuOutils();
		bool getIsOvertabMenuOutil(uint index,uint mouse_x,uint mouse_y){return tabMenuOutil.browse(index)->isOver(mouse_x,mouse_y);};
	
};
