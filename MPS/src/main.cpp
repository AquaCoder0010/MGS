#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath> 	

std::vector<sf::Vector2f> CalcCubicBezier(
        const sf::Vector2f &start,
        const sf::Vector2f &end,
        const sf::Vector2f &startControl,
        const sf::Vector2f &endControl,
        const size_t numSegments)
{
    std::vector<sf::Vector2f> ret;
    if (!numSegments) // Any points at all?
        return ret;

    ret.push_back(start); // First point is fixed
    float p = 1.f / numSegments;
    float q = p;
    for (size_t i = 1; i < numSegments; i++, p += q) // Generate all between
        ret.push_back(p * p * p * (end + 3.f * (startControl - endControl) - start) +
                      3.f * p * p * (start - 2.f * startControl + endControl) +
                      3.f * p * (startControl - start) + start);
    ret.push_back(end); // Last point is fixed
    return ret;
	
}



int main(){
	sf::RenderWindow window(sf::VideoMode(600, 400), "MAPL");


	sf::Event event;
	sf::Texture texture;
	if(!texture.loadFromFile("rsrc/img.png")){
	//
	}	

	sf::Sprite sprite;
	sprite.setTexture(texture);

	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear();
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		std::cout << mousePos.x << "  " << mousePos.y << std::endl;
		sf::VertexArray vertices(sf::LinesStrip, 0);

// Calculate the points on the curve (10 segments)
	std::vector<sf::Vector2f> points =
    	CalcCubicBezier(
        	sf::Vector2f(600, 0),
        	sf::Vector2f(0, 0),
        	sf::Vector2f(200, 200),
        	sf::Vector2f(200, 200),
        	100);

// Append the points as vertices to the vertex array
	for (std::vector<sf::Vector2f>::const_iterator a = points.begin(); a != points.end(); ++a)
    	vertices.append(sf::Vertex(*a, sf::Color::Red));
		window.draw(sprite);
		window.draw(vertices);
		window.display();
	}
}