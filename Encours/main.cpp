#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "include.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!",sf::Style::Default);
	Point P(200,200);
	Rectangle R("Red",10,200,50,100);
	Carre C("Blue",10,200,70);


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
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		sf::Vector2i position=sf::Mouse::getPosition(window);
		//std::cout<<position.x<<" "<<position.y<<std::endl;
		bool isPushLeft=false;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			isPushLeft=true;

			//~ std::cout<<sourisClickY<<std::endl;
		}
		bool isPushRight=false;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			isPushRight=true;
		//std::cout<<"position _x: "<<positionSouri(position.x)<<std::endl;
		}
        window.clear(sf::Color::White);
        
        dessiner(window,C,C.isOver(position.x,position.y),position.x,position.y,isPushLeft);
		//ActionTouche(500,500,isPushRight,isPushLeft);
        Menu(30,1000,position.x,position.y,sf::Mouse::isButtonPressed(sf::Mouse::Left),window);
        MenuOutils(500,500,position.x,position.y,sf::Mouse::isButtonPressed(sf::Mouse::Left),window);
        //dessiner(window,P,P.isOver(position.x,position.y),position.x,position.y,isPush);
        window.display();
    }



    return 0;
}
