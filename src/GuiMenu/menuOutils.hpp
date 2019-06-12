#include <SFML/Graphics.hpp>
#include "../DrawableShapes/ShapesDrawable.hpp"
#include "../DrawableShapes/PointsDrawable.hpp"
#include "../DrawableShapes/RectangleDrawable.hpp"
#include "../DrawableShapes/SquareDrawable.hpp"
#include "../DrawableShapes/CircleDrawable.hpp"
#include "../DrawableShapes/EllipseDrawable.hpp"
#include "../DrawableShapes/TriangleDrawable.hpp"

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
