#include "Plot.hpp"

Plot::Plot()
:circle(), line(), y_axis(), x_axis(), grid_tex(), grid_sprite()
{
    if(grid_tex.loadFromFile("rsrc/grid.png"))
    {
            grid_sprite.setTexture(grid_tex);
            grid_sprite.setColor(sf::Color(128, 128, 128, 115));
            grid_sprite.setPosition(sf::Vector2f(-208.f, -2.f));
    }
    win_x = 0;
    win_y = 0;
    t = -30;
    drawing = false;
    vertexNo = 0;
    circle.setRadius(3.5f);
    circle.setOrigin(3.5, 3.5);
    line.setPrimitiveType(sf::LineStrip);
    y_axis.setPrimitiveType(sf::Quads);
    x_axis.setPrimitiveType(sf::Quads);
    x_axis.resize(4);
    y_axis.resize(4);
}

void Plot::getWindowSize(float x, float y)
{
    win_x = x;
    win_y = y;
}

void Plot::startDrawing(bool state)
{
    drawing = state;
    if(drawing = true)
    {
        line.clear();
    }   
}

void Plot::processEvents(sf::Keyboard::Key key, bool isPressed)
{

}

void Plot::update()
{
    if(t < 30 && t >= -30 && drawing == true)
    {
        circle.setPosition(sf::Vector2f(t*20.f + win_x/2, -1.f*(cos(t))*20.f + win_y/2));
        colorFunction(sf::Color::White);
        line.append(circle.getPosition());
        t += 0.15;
        std::cout << line.getVertexCount() << std::endl;
    }
    if(t >= 30 && drawing == true)
    {
        t = -30;
        drawing = false;
    }

    if(t < 30 && t > -30 && drawing == false)
    {
        line.clear();
        t = -30;
    }
}

void Plot::drawTo(sf::RenderWindow& window)
{
    window.draw(grid_sprite);
    window.draw(y_axis);
    window.draw(x_axis);
    window.draw(circle);
    window.draw(line);
}

void Plot::drawPlane(int width, int height)
{
    y_axis[0].position = sf::Vector2f(width/2 + 1, height);
    y_axis[1].position = sf::Vector2f(width/2 - 1, height);
    y_axis[2].position = sf::Vector2f(width/2 - 1, 0);
    y_axis[3].position = sf::Vector2f(width/2 + 1, 0);


    x_axis[0].position = sf::Vector2f(0, height/2 + 1);
    x_axis[1].position = sf::Vector2f(0, height/2 - 1);
    x_axis[2].position = sf::Vector2f(width, height/2 - 1);
    x_axis[3].position = sf::Vector2f(width, height/2 + 1);

    for(int i = 0; i < 4; i++)
    {
        x_axis[i].color = sf::Color(128, 128, 128);
        y_axis[i].color = sf::Color(128, 128, 128);
    }
}

void Plot::colorFunction(const sf::Color& color)
{
    circle.setFillColor(color);
    vertexNo = line.getVertexCount();
    for(int i = 0; i < vertexNo; i++)
    {
        line[i].color = color;
    }
}