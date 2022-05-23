#include "Button.h"

Button::Button(std::string inscription, sf::Vector2f position, sf::Vector2f size, sf::Font& font)
{
	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;

	sf::Color OutLineColor;
	OutLineColor.r = 30;
	OutLineColor.g = 159;
	OutLineColor.b = 225;

	this->inscription.setString(inscription);
	this->inscription.setPosition(position);
	this->inscription.setFont(font);
	this->inscription.setFillColor(sf::Color::White);
	this->form.setSize(size);
	this->form.setFillColor(bgColor);
	this->form.setOutlineColor(OutLineColor);
	this->form.setOutlineThickness(2);
	this->form.setPosition(position);
}

bool Button::checkCollision(const sf::Vector2i& position)
{
	return (position.x >= this->form.getPosition().x && position.x <= this->form.getPosition().x + this->form.getSize().x
		&& position.y >= this->form.getPosition().y && position.y <= this->form.getPosition().y + this->form.getSize().y);
}


void Button::draw(sf::RenderWindow& window)
{
	window.draw(this->form);
	window.draw(this->inscription);
}

std::string Button::getString() const
{
	return this->inscription.getString();
}

void Button::setString(std::string& str) const
{
	this->inscription.setString(str);
}

bool Button::checkCollision(sf::Vector2f position)
{
	return (position.x >= this->form.getPosition().x && position.x <= this->form.getPosition().x + this->form.getSize().x
		&& position.y >= this->form.getPosition().y && position.y <= this->form.getPosition().y + this->form.getSize().y);
}

