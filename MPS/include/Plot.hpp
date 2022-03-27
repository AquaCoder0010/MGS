#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class Plot
{
    public:
        Plot();
        void getWindowSize(float x, float y);
        void startDrawing(bool state);
        void processEvents(sf::Keyboard::Key key, bool isPressed);
        void update();
        void drawTo(sf::RenderWindow& window);
        void drawPlane(int width, int height);
    private:
        sf::CircleShape circle;
        sf::VertexArray line;
        sf::VertexArray y_axis;
        sf::VertexArray x_axis;
        sf::Texture grid_tex;
        sf::Sprite grid_sprite;
    private:
        bool drawing;
        float t;
        int win_x;
        int win_y;
        int vertexNo;
    private:
        void colorFunction(const sf::Color& color);
};