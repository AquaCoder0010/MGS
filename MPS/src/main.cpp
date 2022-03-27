#include <SFML/Graphics.hpp>
#include "Plot.hpp"
#include "TextBox.hpp"

int main()
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;
	sf::RenderWindow window(sf::VideoMode(1000, 500), "MPS",  sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);

	sf::Event event;

	Plot plot;
	plot.drawPlane(window.getSize().x - 200, window.getSize().y);
	plot.getWindowSize(window.getSize().x - 200, window.getSize().y);

		
	Textbox textBox(20, sf::Color::White, true);
	textBox.setLimit(true, 60);
	textBox.setPosition(sf::Vector2f(20.f, 20.f));
	sf::Font font;
	if(font.loadFromFile("calibri.ttf")){
		textBox.setFont(font);
	}
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed)
			{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
					textBox.setSelected(true);				

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
					textBox.setSelected(false);

				if(event.key.code == sf::Keyboard::Enter)
					plot.startDrawing(true);
					
				if(!event.key.code == sf::Keyboard::Enter)
					plot.startDrawing(false);

				plot.processEvents(event.key.code, true);
			}
			if(event.type == sf::Event::KeyReleased)
				plot.processEvents(event.key.code, false);
			if(event.type == sf::Event::TextEntered)
				textBox.typedOn(event);
			
		}
		window.clear();
		plot.update();
		plot.drawTo(window);
		textBox.drawTo(window);
		window.display();
	}
}