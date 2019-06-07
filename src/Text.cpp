#include "Text.hpp"

Text::Text(sf::Color _color):string(" "),Color(_color){}

Text::~Text(){}

void Text::textSaisie(sf::Event &e,sf::RenderWindow &w)
{
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		// erreur...
	}
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
			if(e.key.code==sf::Keyboard::C){
				string=string+"c";
			}
			if(e.key.code==sf::Keyboard::D){
				string=string+"d";
			}
			if(e.key.code==sf::Keyboard::E){
				string=string+"e";
			}
			if(e.key.code==sf::Keyboard::F){
				string=string+"f";
			}
			if(e.key.code==sf::Keyboard::G){
				string=string+"g";
			}
			if(e.key.code==sf::Keyboard::H){
				string=string+"h";
			}
			if(e.key.code==sf::Keyboard::I){
				string=string+"i";
			}
			if(e.key.code==sf::Keyboard::J){
				string=string+"j";
			}
			if(e.key.code==sf::Keyboard::K){
				string=string+"k";
			}
			if(e.key.code==sf::Keyboard::L){
				string=string+"l";
			}
			if(e.key.code==sf::Keyboard::M){
				string=string+"m";
			}
			if(e.key.code==sf::Keyboard::n){
				string=string+"n";
			}
			if(e.key.code==sf::Keyboard::O){
				string=string+"o";
			}
			if(e.key.code==sf::Keyboard::P){
				string=string+"p";
			}
			if(e.key.code==sf::Keyboard::Q){
				string=string+"q";
			}
			if(e.key.code==sf::Keyboard::R){
				string=string+"r";
			}
			if(e.key.code==sf::Keyboard::S){
				string=string+"s";
			}
			if(e.key.code==sf::Keyboard::T){
				string=string+"t";
			}
			if(e.key.code==sf::Keyboard::U){
				string=string+"u";
			}
			if(e.key.code==sf::Keyboard::V){
				string=string+"v";
			}
			if(e.key.code==sf::Keyboard::W){
				string=string+"w";
			}
			if(e.key.code==sf::Keyboard::X){
				string=string+"x";
			}
			if(e.key.code==sf::Keyboard::Y){
				string=string+"y";
			}
			if(e.key.code==sf::Keyboard::Z){
				string=string+"z";
			}
			break;
		default:
		break;
	
	}
	
}

