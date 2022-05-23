#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27


class TextInput
{	
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;
	std::string getText();
	sf::Text inscription;
	sf::RectangleShape border;



private:
	void inputLogic(int charTyped);
	void deleteLastChar();

public:
	TextInput();
	TextInput(int size, sf::Color color, bool sel);

	void setFont(sf::Font& font);
	void setPosition(sf::Vector2f pos);

	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelected(bool sel);

	void draw(sf::RenderWindow& window);

	std::string getInput(sf::Font& font);

	void typedOn(sf::Event input);
};


