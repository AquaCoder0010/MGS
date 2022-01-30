#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


class Plot{
public:
	Plot();
	void drawParabola(unsigned int m_x, unsigned int m_y);
    void drawSin(unsigned int m_x, unsigned int m_y);
	void drawCos(unsigned int m_x, unsigned int m_y);
	void drawTan(unsigned int m_x, unsigned int m_y);
    void drawLog(unsigned int m_x, unsigned int m_y);
    void drawExp(unsigned int m_x, unsigned int m_y);
	void drawFunction(unsigned int m_x, unsigned int m_y, int value);
	sf::VertexArray m_Function;
private:
	float x, y;
    
};