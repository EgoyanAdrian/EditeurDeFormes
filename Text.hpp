#include <iostream>
#include <SFML/Graphics.hpp>

class Text{
		std::string string;
		sf::Color Color;
	
	public:
		Text(sf::Color _color=sf::Color::Black);//constructor of text
		Text()=delete;
		~Text();
		//Setteur & Getteur String
		inline std::string getString(){return string;};
		inline void setString(std::string s){string=s;};
		//Setteur & Getteur Color
		inline sf::Color getColor(){return Color;};
		inline void setColor(sf::Color c){Color=c;};
};
