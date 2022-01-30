#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>


#include "plotFunction.hpp"
#include "changeFunction.hpp"


static unsigned int height = 500;
static unsigned int width = 1000;
static std::string f_str;

static short value_FunctionT = 0;
static float fps;
int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;	
	sf::RenderWindow window(sf::VideoMode(width, height), "MPS", sf::Style::Default, settings);	

	sf::Event event;
	Plot plot;
	changeFunction c_Function;

	sf::Font font;
	if(!font.loadFromFile("calibri.ttf"))
	{
		std::cout << "Error Loading Font" << std::endl;
	}

	sf::Text text;
	text.setFont(font);

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
			if(event.type == sf::Event::KeyPressed)
			{
				c_Function.inputChange(event.key.code);
				std::cout << c_Function.returnVar() << std::endl;
			}
		}
		sf::Clock clock;
		float fps;
		window.clear();	
		plot.drawFunction(width, height, c_Function.returnVar());
		window.draw(plot.m_Function);
		window.draw(y_axis);
		window.draw(x_axis);
		window.draw(text);
		window.display();
		float currentTime = clock.restart().asSeconds();
        fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
		fps = 1.f/lastTime;
		f_str = std::to_string(fps);
		text.setString(f_str);
	}
	return 0;
}