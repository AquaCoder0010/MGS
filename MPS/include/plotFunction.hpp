#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Plot{
public:
	Plot();
	void drawFunction(unsigned int m_x, unsigned int m_y);
	sf::VertexArray m_Function;
private:
	float x, y; 
	const float euler =  2.78182372;
};