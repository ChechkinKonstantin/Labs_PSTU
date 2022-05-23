#include "Vertex.h"

sf::Vector2f Vertex::getPosition()
{
	//return sf::Vector2f(this->circle.getGlobalBounds().width + this->circle.getPosition().x, this->circle.getGlobalBounds().height + this->circle.getPosition().y);
	return this->circle.getPosition();
}

bool Vertex::operator==(Vertex other)
{
	return (this->getPosition() == other.getPosition()) && (this->getText() == other.getText()) && (this->getRadius() == other.getRadius());
}

Vertex::Vertex(sf::Vector2f coords, std::string name, sf::Font& font)
{
	sf::Color OutLineColor;
	OutLineColor.r = 30;
	OutLineColor.g = 159;
	OutLineColor.b = 225;

	sf::Color FillColor;
	FillColor.r = 20;
	FillColor.g = 21;
	FillColor.b = 38;

	this->circle.setRadius(50);
	this->circle.setPosition(coords.x, coords.y);
	this->circle.setFillColor(FillColor);
	this->circle.setOutlineThickness(3);
	this->circle.setOutlineColor(OutLineColor);
	this->text.setFont(font);
	this->text.setPosition(sf::Vector2f(coords.x + this->circle.getRadius() - 10, coords.y + this->circle.getRadius() - 18));
	this->text.setString(name);
	this->text.setFillColor(sf::Color::White);

}
int Vertex::getRadius()
{
	return this->circle.getRadius();
}

std::string Vertex::getText()
{
	return this->text.getString();
}

void Vertex::draw(sf::RenderWindow& window)
{
	window.draw(this->circle);
	window.draw(this->text);
}