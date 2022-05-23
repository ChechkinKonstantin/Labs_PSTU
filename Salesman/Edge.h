#pragma once
#include <SFML/Graphics.hpp>
#include "Vertex.h"

class Edge
{
private:
	sf::Text text;
	sf::Vector2f first_point;
	sf::Vector2f second_point;
	std::vector<std::string> verticiesNames;
	int circleRadius;
public:
	Edge(int weight,Vertex first_vertex, Vertex second_vertex, sf::Font&);
	std::vector<std::string> getVerticiesNames();
	void draw(sf::RenderWindow& window);	

private:
	int getLen();
};

