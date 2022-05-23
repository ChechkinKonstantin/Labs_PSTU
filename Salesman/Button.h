#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>


class Button
{
private:
	sf::RectangleShape form;
	mutable sf::Text inscription;
public:
	Button(std::string inscription, sf::Vector2f position, sf::Vector2f size, sf::Font& font);
	bool checkCollision(const sf::Vector2i& position);
	bool checkCollision(sf::Vector2f position);
	void draw(sf::RenderWindow&);
	std::string getString() const;
	void setString(std::string& str) const;
};

