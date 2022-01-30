#include "plotFunction.hpp"

Plot::Plot()
:x(0), y(0)
{}

void Plot::drawParabola(unsigned int m_x, unsigned int m_y)
{
    m_Function.setPrimitiveType(sf::LineStrip);
    for(x = -50; x <= 50; x += 0.25){
	    m_Function.append(
            sf::Vertex(sf::Vector2f(x*20.f + m_x/2, -1*pow(x,2)*20.f+m_y/2)));
    }
    if(x >= 50){
        x = 0;
    }
}

void Plot::drawSin(unsigned int m_x, unsigned int m_y)
{
    m_Function.setPrimitiveType(sf::LineStrip);
	for(x = -50; x <= 50; x += 0.25){
    m_Function.append(sf::Vertex(sf::Vector2f(x*20.f, -1*sin(x)*20.f+m_y/2)));    
  }
    if(x >= 50){
        x = 0;
    }
}

void Plot::drawCos(unsigned int m_x, unsigned int m_y)
{
    m_Function.setPrimitiveType(sf::LineStrip);
	for(x = -50; x <= 50; x += 0.25){
    m_Function.append(sf::Vertex(sf::Vector2f(x*20.f, -1*cos(x)*20.f+m_y/2)));    
  }
    if(x >= 50){
        x = 0;
    }
}

void Plot::drawTan(unsigned int m_x, unsigned int m_y)
{
    m_Function.setPrimitiveType(sf::LineStrip);
	for(x = -200; x <= 200; x += 0.25){
    m_Function.append(sf::Vertex(sf::Vector2f(x*20.f + m_x/2, -1*tan(x)*20.f+m_y/2)));    
  }
    if(x >= 200){
        x = 0;
    }
}

void Plot::drawLog(unsigned int m_x, unsigned int m_y)
{
    m_Function.setPrimitiveType(sf::LineStrip);
	for(x = -200; x <= 200; x += 0.25){
    m_Function.append(sf::Vertex(sf::Vector2f(x*19.f + m_x/2, -1*log(x)*20.f+m_y/2)));    
  }
    if(x >= 200){
        x = 0;
    }
}

void Plot::drawExp(unsigned int m_x, unsigned int m_y)
{
     m_Function.setPrimitiveType(sf::LineStrip);
	for(x = -200; x <= 200; x += 0.25){
    m_Function.append(sf::Vertex(sf::Vector2f(x*20.f + m_x/2, -1*pow(2, x)*20.f+m_y/2)));    
  }
    if(x >= 200){
        x = 0;
    }
}




void Plot::drawFunction(unsigned int m_x, unsigned int m_y, int value)
{
  if(value == 0){
    m_Function.clear();
    drawParabola(m_x, m_y);
  }
  if(value == 1){
    m_Function.clear();
    drawExp(m_x, m_y);
  }
  if(value == 2){
    m_Function.clear();
    drawLog(m_x, m_y);
  }
  if(value == 3){
    m_Function.clear();
    drawSin(m_x, m_y);
  }
  if(value == 4){
    m_Function.clear();
    drawCos(m_x, m_y);
  }
  if(value == 5){
    m_Function.clear();
    drawTan(m_x, m_y);
  }
}