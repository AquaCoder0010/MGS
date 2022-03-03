#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "sleep.hpp"

#define e 2.71828 
#define pi 3.14159


class Plot
{
    public:
        Plot()
        :grid_tex(), sprite(), function(), x_axis(), y_axis(), drawing(false), curve()
        {
            if(grid_tex.loadFromFile("rsrc/grid.png"))
            {
                sprite.setTexture(grid_tex);
                sprite.setPosition(sf::Vector2f(0.f, -1.f));
                sprite.setColor(sf::Color(128, 128, 128, 128));
            }
            else
            {
                std::cout << "Error loading texture" << std::endl;
            }
            function.setPrimitiveType(sf::LineStrip);
           
            x_axis.setPrimitiveType(sf::Quads);
            y_axis.setPrimitiveType(sf::Quads);
            x_axis.resize(4);
            y_axis.resize(4);

            curve.setRadius(5.f);
            curve.setOrigin(sf::Vector2f(5.f, 5.f));
            curve.setFillColor(sf::Color(255, 255, 255));
            x = -25;
        }

        void drawPlane(float width, float height)
        {
	        y_axis[0].position = sf::Vector2f(width/2 + 1, height);
	        y_axis[1].position = sf::Vector2f(width/2 - 1, height);
	        y_axis[2].position = sf::Vector2f(width/2 - 1, 0);
	        y_axis[3].position = sf::Vector2f(width/2 + 1, 0);

	        x_axis[0].position = sf::Vector2f(0, height/2 + 1);
	        x_axis[1].position = sf::Vector2f(0, height/2 - 1);
	        x_axis[2].position = sf::Vector2f(width, height/2 - 1);
	        x_axis[3].position = sf::Vector2f(width, height/2 + 1);

        }
        void startDrawing()
        {
            drawing = true;
        }
        bool drawingState()
        {
            return drawing;
        }
        void drawFunction(sf::RenderWindow &window)
        {
            while(x < 25 && drawing == true)
            {
                aq::sleep(0.01);
                x += 0.2;
                window.clear();
                curve.setPosition(sf::Vector2f(x*20.f + window.getSize().x/2,  
                    -1*( sin(x) )*20.f + window.getSize().y/2));
                function.append(
                    sf::Vertex(sf::Vector2f
			(x*20.f + window.getSize().x/2,  
                    -1*( sin(x) )*20.f + window.getSize().y/2)));
               
                window.draw(function);
                window.draw(curve);
                window.draw(sprite);
                window.draw(x_axis);
                window.draw(y_axis);
                window.display();
            }
            if(x > 15 || drawing == false || (x > 15 && drawing == false))
            {
                drawing = false;
                window.clear();
                window.draw(function);
                window.draw(sprite);
                window.draw(x_axis);
                window.draw(y_axis);
                window.display();
            }
        }
    private:
        sf::Texture grid_tex;
        sf::Sprite sprite;
        sf::VertexArray function;
        sf::VertexArray x_axis;
        sf::VertexArray y_axis;
        sf::CircleShape curve;
    private:
        bool drawing;
        float x;
    
};

 //m_Function.append(sf::Vertex(sf::Vector2f(x*20.f + m_x/2,  -1*(-1*x)*20.f+m_y/2)));