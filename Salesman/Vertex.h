#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Vertex
{
public:
	sf::CircleShape circle;
		sf::Text text;
public:
	Vertex(sf::Vector2f coords, std::string name, sf::Font& font);
	std::string getText();
	sf::Vector2f getPosition();
	int getRadius();
	void draw(sf::RenderWindow& window);

public:
	bool operator==(Vertex);
};


