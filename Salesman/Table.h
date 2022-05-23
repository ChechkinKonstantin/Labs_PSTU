#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <limits>


class Table
{
private:
	std::vector<std::vector<int>>* data;
	sf::Vector2f position;
	sf::Vector2i size;
	sf::Font font;
	float cellWidth;
	float cellHeight;
	std::vector<std::string> names;

public:
	Table(sf::Vector2f position, sf::Vector2i size, std::vector<std::string> names, sf::Font& font, float cellWidth = 100, float cellHeight = 80);
	~Table();
	void draw(sf::RenderWindow& window);


	std::vector<int>& operator[](int index);
	Table& operator=(std::vector<std::vector<int>> data);
};

