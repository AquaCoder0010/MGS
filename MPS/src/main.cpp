#include <iostream>
#include <SFML/Graphics.hpp>

#include "plotFunction.hpp"




int main()
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 0.0;
	sf::RenderWindow window(sf::VideoMode(1000, 500), "MPS",  sf::Style::Close, settings);
	Plot plot;

	plot.drawPlane(window.getSize().x, window.getSize().y);

	sf::Event event;
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Enter)
					plot.startDrawing();
			}
		}
		
		window.clear();
		plot.drawFunction(window);
		
	}
}

