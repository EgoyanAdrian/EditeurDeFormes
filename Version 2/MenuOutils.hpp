//liste des action lors des touche sont actionner

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <utility>
#include "Rectangle.hpp"
#include "Draw.hpp"

typedef std::vector<Rectangle> TableauRectangle;
void menuOutil(uint _x,uint _y,uint _mousex, uint _mousey,bool isPushLeft,sf::RenderWindow &w);
