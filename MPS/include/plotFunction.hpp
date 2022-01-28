#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class Plot{
public:
	Plot();
	void drawParabola(unsigned int m_x, unsigned int m_y);
    void drawSin(unsigned int m_x, unsigned int m_y);
    void drawLog(unsigned int m_x, unsigned int m_y);
    void drawExp(unsigned int m_x, unsigned int m_y);
	sf::VertexArray m_Function;
    float t;
private:
	float x, y;
    
};