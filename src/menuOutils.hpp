#include <SFML/Graphics.hpp>
#include "ShapesDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "Text.hpp"

class menuOutils{
		ShapesDrawable tabMenuOutil=ShapesDrawable(10);
	public:
		menuOutils(uint mouse_x, uint mouse_y,bool isPush,sf::RenderWindow &w);
		~menuOutils();
		void moveMenu(uint mouse_X,uint mouse_y,sf::RenderWindow &w);
	
};
