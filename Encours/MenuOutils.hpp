

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Formes.hpp"  
#include "Rectangle.hpp"
#include "Draw.hpp"

class MenuOutils{
		Formes BarreOutil=Formes(3);
	public:
		MenuOutils(uint _x,uint _y,uint _mousex, uint _mousey,bool isPushLeft,sf::RenderWindow &w);
		MenuOutils()=delete;
		~MenuOutils();
};
