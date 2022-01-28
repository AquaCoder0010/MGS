#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "plotFunction.hpp"

unsigned int height = 500;
unsigned int width = 1000;


float fps;
int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0.0;	
	sf::RenderWindow window(sf::VideoMode(width, height), fps, sf::Style::Default, settings);	
	sf::Event event;
	Plot plot;

	sf::VertexArray y_axis(sf::Quads, 4);
	y_axis[0].position = sf::Vector2f(width/2 + 1.5, height);
	y_axis[1].position = sf::Vector2f(width/2 - 1.5, height);
	y_axis[2].position = sf::Vector2f(width/2 - 1.5, 0);
	y_axis[3].position = sf::Vector2f(width/2 + 1.5, 0);

	sf::VertexArray x_axis(sf::Quads, 4);
	x_axis[0].position = sf::Vector2f(0, height/2 + 1.5);
	x_axis[1].position = sf::Vector2f(0, height/2 - 1.5);
	x_axis[2].position = sf::Vector2f(width, height/2 - 1.5);
	x_axis[3].position = sf::Vector2f(width, height/2 + 1.5);

	plot.drawParabola(width, height);
	sf::Clock clock;
	float lastTime = 0;
	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
   			event.size.width = window.getSize().x;
    		event.size.height = window.getSize().y;
			}
		}
		
        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
		window.clear();	
		window.draw(plot.m_Function);
		window.draw(y_axis);
		window.draw(x_axis);
		window.display();
		std::cout << fps << std::endl;
		
		
	}
	return 0;
}
