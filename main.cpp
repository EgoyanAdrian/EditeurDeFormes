#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Text.hpp"

void text(sf::Event e,Text &a){
	switch (e.type) {
		case sf::Event::KeyReleased:
			if(e.key.code == sf::Keyboard::Return) {
				std::cout<<a.getString()<<std::endl;
			}
			if(e.key.code==sf::Keyboard::A){
				a.setString(a.getString()+"a");
			}
			if(e.key.code==sf::Keyboard::B){
				a.setString(a.getString()+"b");
			}
			break;
		default:
		break;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "",sf::Style::Default);
	Text adress(sf::Color::Yellow);
	std::string m_saisie;
	sf::Clock time;
	
	// choix de la police à utiliser
	//text.setFont(font); // font est un sf::Font

	// choix de la chaîne de caractères à afficher
	//text.setString("Hello world");

	// choix de la taille des caractères
	//text.setCharacterSize(24); // exprimée en pixels, pas en points !
	// choix de la couleur du texte
	//text.setFillColor(sf::Color::Red);

	// choix du style du texte
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	while (window.isOpen())
    {
	window.setKeyRepeatEnabled(true);
        sf::Event event;
        while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed)
				window.close();
			text(event,adress);
		}
        window.clear(sf::Color::White);

        window.display();
    }
    return 0;
}



