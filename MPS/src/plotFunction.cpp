#include "plotFunction.hpp"

Plot::Plot()
:x(0), y(0)
{}

void Plot::drawFunction(unsigned int m_x, unsigned int m_y)
{
    m_Function.clear();
    m_Function.setPrimitiveType(sf::LineStrip);
    for(x = -50; x <= 50; x += 0.01){
	    m_Function.append(sf::Vertex(sf::Vector2f(x*20.f + m_x/2, -1*(log(pow(x, sin(x))))*20.f+m_y/2)));
    }
    if(x >= 50){
        x = 0;
    }
}

