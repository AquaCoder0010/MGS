#include <iostream>
#include <string>
#include <SFML/System.hpp>

#include "plotFunction.hpp"
#include "TextBox.hpp"
#include "Parser.hpp"

static short stateSelected = 0;




int main(int argc, char* argv[])
{	
	sf::ContextSettings settings;
    settings.antialiasingLevel = 0.0;
	sf::RenderWindow window(sf::VideoMode(1000, 500), "MPS",  sf::Style::Close, settings);
	window.setActive(false); 
	Plot plot;

	sf::Font font;
	Textbox textBox(20, sf::Color::White, true);
	textBox.setLimit(true, 10);
	textBox.setPosition(sf::Vector2f(20.f, 20.f));

	if(font.loadFromFile("calibri.ttf"))
	{
		textBox.setFont(font);
		
	}
	else
	{
		std::cout << "error loading" << std::endl;
	}

	plot.drawPlane(window.getSize().x, window.getSize().y);


	textBox.setSelected(true);
	sf::Event event;
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(plot.drawingState() == false)
			{
				textBox.setSelected(true);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				textBox.setSelected(true);
				
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				textBox.setSelected(false);
				plot.startDrawing(textBox.getText());
			}

			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::TextEntered)
			{
				textBox.typedOn(event);
			}
		}
		
		window.clear();

		plot.drawFunction(window);
		textBox.drawTo(window);
		window.display();		
		
	}
	return 0;
}

