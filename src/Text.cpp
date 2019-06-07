#include "Text.hpp"

Text::Text(sf::Color _color):string(" "),Color(_color){}

Text::~Text(){}

void Text::textSaisie(sf::Event &e)
{
	switch (e.type) {
		case sf::Event::KeyReleased:
			if(e.key.code == sf::Keyboard::Return) {
				std::cout<<string<<std::endl;
			}
			if(e.key.code==sf::Keyboard::A){
				string=string+"a";
			}
			if(e.key.code==sf::Keyboard::B){
				string=string+"b";
			}
			break;
		default:
		break;
		
	}
}

