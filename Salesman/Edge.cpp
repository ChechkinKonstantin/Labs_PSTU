#include "Edge.h"
#include <iostream>
#include <cmath>

int Edge::getLen()
{
	return sqrt(pow(this->first_point.x - this->second_point.x, 2) + pow(this->first_point.y - this->second_point.y, 2));
}

Edge::Edge(int weight, Vertex first_vertex, Vertex second_vertex, sf::Font& font)
{
	this->text.setString(std::to_string(weight));
	this->text.setFillColor(sf::Color::White);
	this->first_point = first_vertex.getPosition();
	this->second_point = second_vertex.getPosition();
	this->text.setFont(font);
	this->circleRadius = first_vertex.getRadius();
	this->text.setPosition((this->first_point.x + this->circleRadius + this->second_point.x + this->circleRadius) / 2, (this->first_point.y + this->circleRadius + this->second_point.y  + this->circleRadius) / 2 );
	this->verticiesNames.push_back(first_vertex.getText());
	this->verticiesNames.push_back(second_vertex.getText());
}


std::vector<std::string> Edge::getVerticiesNames()
{
	return this->verticiesNames;
}


void Edge::draw(sf::RenderWindow& window)
{

	int k = 10;
	sf::Vector2f end = this->second_point;
	sf::Vector2f v1((this->second_point.x - this->first_point.x) / this->getLen(), (this->second_point.y - this->first_point.y) / this->getLen());
	sf::Vector2f v2((-this->first_point.y + this->second_point.y) / this->getLen(), (this->first_point.x - this->second_point.x) / this->getLen());
	sf::Vector2f v3((v1.x + v2.x) * k, (v1.y + v2.y) * k);
	sf::Vector2f v4((v1.x - v2.x) * k, (v1.y - v2.y) * k);
	end = sf::Vector2f(end.x - v1.x * this->circleRadius, end.y - v1.y * this->circleRadius);

	sf::VertexArray v(sf::Triangles, 3);
	v[0] = sf::Vertex({ end.x + this->circleRadius,end.y + this->circleRadius}, sf::Color::White);
	v[1] = sf::Vertex({ end.x - v3.x + this->circleRadius,end.y - v3.y + this->circleRadius}, sf::Color::White);
	v[2] = sf::Vertex({ end.x - v4.x + this->circleRadius,end.y - v4.y  + this->circleRadius}, sf::Color::White);

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(this->first_point.x + this->circleRadius, this->first_point.y + this->circleRadius)),
		sf::Vertex(sf::Vector2f(this->second_point.x + this->circleRadius, this->second_point.y + this->circleRadius))
	};
	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;
	window.draw(v, sf::RenderStates::Default);
	window.draw(this->text);
	window.draw(line, 2, sf::Lines);
}





