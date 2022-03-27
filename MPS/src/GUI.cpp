#include "GUI.hpp"

GUI::GUI()
:textBox(20, sf::Color::White, true), text_font()
{
    textBox.setLimit(true, 60);
	textBox.setPosition(sf::Vector2f(20.f, 20.f));
    if(text_font.loadFromFile("calibri.ttf"))
    {
		textBox.setFont(text_font);
	}
}

