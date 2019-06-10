#include <SFML/Graphics.hpp>
#include "ShapesDrawable.hpp"
#include "PointsDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "Text.hpp"

class menuOutils{
		ShapesDrawable tabMenuOutil=ShapesDrawable(10);
	public:
		menuOutils(sf::Event &e,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable &PointsD,ShapesDrawable &SD,sf::Font font);
		~menuOutils();
		void moveMenu(uint mouse_X,uint mouse_y,sf::RenderWindow &w);
		bool getIsOvertabMenuOutil(uint index,uint mouse_x,uint mouse_y){return tabMenuOutil.browse(index)->isOver(mouse_x,mouse_y);};
	
};
