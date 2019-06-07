#include <SFML/Graphics.hpp>
#include "ShapesDrawable.hpp"
#include "PointsDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "Text.hpp"

class menuOutils{
		ShapesDrawable tabMenuOutil=ShapesDrawable(10);
	public:
		menuOutils(sf::Event &e,uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w,PointsDrawable &PointsD,ShapesDrawable &SD);
		~menuOutils();
		void moveMenu(uint mouse_X,uint mouse_y,sf::RenderWindow &w);
	
};
