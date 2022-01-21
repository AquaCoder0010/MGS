#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


class Function{
public:
	sf::VertexArray m_Function;
	Function()
	:x(0), y(0)
	{
	} 
	bool drawParabola(bool draw, unsigned int m_x, unsigned int m_y)
		{
		m_Function.setPrimitiveType(sf::LineStrip);
		if(!draw)
			return 0;
		else{
			for(x = -50; x <= 50; x += 0.25)
			m_Function.append(sf::Vertex(sf::Vector2f(x*20.f + m_x/2, -1*pow(x,2)*20.f+m_y/2)));
			return 1;	
			}
		return 0;
		}
	bool drawSin(bool draw, unsigned int m_x, unsigned int m_y)
		{
		m_Function.setPrimitiveType(sf::LineStrip);
		if(!draw)
			return 0;
		else{
			for(x = -50; x <= 50; x += 0.25)
			m_Function.append(sf::Vertex(sf::Vector2f(x*20.f, -1*sin(x)*20.f+m_y/2)));
			return 1;	
			}
		return 0;
		}
	
private:
	float x, y;
};

unsigned int height = 400;
unsigned int width = 600;

int main(){
	sf::RenderWindow window(sf::VideoMode(width, height), "MPS");	
	sf::Event event;
	Function func;

	sf::Clock clock;
	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);	
		func.drawParabola(true, width, height);
		func.drawSin(true, width, height);
		window.draw(func.m_Function);
		window.display();
	}
	return 0;
}
