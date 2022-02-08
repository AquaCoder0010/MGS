#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>


#include "plotFunction.hpp"
#include "TextBox.hpp"
// Static Variables
static unsigned int height = 500;
static unsigned int width = 1000;
static std::string f_str;
static int fps = 0;
static float currentTime = 0;
static float lastTime = 0;

int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;	// antianalising to 8.0 Level MAX
	// creating window
	sf::RenderWindow window(sf::VideoMode(width, height), "MPS", sf::Style::Default, settings);	
	sf::Event event;
	// creating Objects for the change Function and the Plot Function
	Plot plot;
	sf::Font font;
	if(!(font.loadFromFile("calibri.ttf"))){
		std::cout << "error!" << std::endl;
	}
	sf::Text text;
	Textbox text1(20, sf::Color::White, true);
	text1.setPosition(sf::Vector2f(40.f, 50.f));
	text1.setLimit(true, 30);
	text1.setFont(font);
	// Drawing the X_Y Plane
	sf::VertexArray y_axis(sf::Quads, 4);
	y_axis[0].position = sf::Vector2f(width/2 + 0.5, height);
	y_axis[1].position = sf::Vector2f(width/2 - 0.5, height);
	y_axis[2].position = sf::Vector2f(width/2 - 0.5, 0);
	y_axis[3].position = sf::Vector2f(width/2 + 0.5, 0);

	sf::VertexArray x_axis(sf::Quads, 4);
	x_axis[0].position = sf::Vector2f(0, height/2 + 0.5);
	x_axis[1].position = sf::Vector2f(0, height/2 - 0.5);
	x_axis[2].position = sf::Vector2f(width, height/2 - 0.5);
	x_axis[3].position = sf::Vector2f(width, height/2 + 0.5);


	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	

	while(window.isOpen()){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			text1.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
		}
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::TextEntered){
				text1.typedOn(event);
			}

		}// starts clock
		window.clear();	 // Clears Window
		plot.drawFunction(width, height); // Create Function
		text1.drawTo(window);
		window.draw(plot.m_Function);// Draw Function
		window.draw(y_axis); // Draw the X_Y Plane
		window.draw(x_axis);
		//calculating FPS
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); 
		previousTime = currentTime;
		// Change Float Value to string
		f_str = std::to_string(fps);
		text.setString(f_str);
		window.draw(text);	
		window.display();
	}
	return 0;
}