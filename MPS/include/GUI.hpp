#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.hpp"
#include "Button.hpp"

class GUI
{
    public:
        GUI();
        void processEvents();
        void update();
        void drawTo(sf::RenderWindow& window)
        {
            window.draw(gui_tex);
        }
    private:
        sf::Texture gui_tex;
        sf::Font text_font;
        TextBox textBox;
};