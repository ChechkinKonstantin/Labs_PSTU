#include "Table.h"


Table::Table(sf::Vector2f position, sf::Vector2i size, std::vector<std::string> names, sf::Font& font, float cellWidth, float cellHeight)
{
	this->position = position;
	this->size = size;
	this->font = font;
	this->cellHeight = cellHeight;
	this->cellWidth = cellWidth;
	this->names = names;

	this->data = new std::vector<std::vector<int>>(this->size.x, std::vector<int>(this->size.y, INT_MAX));
}

void Table::draw(sf::RenderWindow& window)
{
	sf::Color OutLineColor;
	OutLineColor.r = 30;
	OutLineColor.g = 159;
	OutLineColor.b = 225;
	
	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;

	sf::RectangleShape cell(sf::Vector2f(this->cellWidth, this->cellHeight));
	cell.setFillColor(bgColor);
	cell.setOutlineThickness(3);
	cell.setOutlineColor(OutLineColor);



	sf::Text cellText("", this->font);
	cellText.setFillColor(sf::Color::White);


	for (int i = 0; i < this->names.size(); i++)
	{
		cellText.setString(this->names[i]);
		cellText.setPosition(sf::Vector2f(this->position.x + (i + 1) * this->cellWidth, this->position.y));
		cell.setPosition(sf::Vector2f(this->position.x + (i + 1) * this->cellWidth, this->position.y));
		window.draw(cell);
		window.draw(cellText);

		cellText.setPosition(sf::Vector2f(this->position.x, this->position.y + (i + 1) * this->cellHeight));
		cell.setPosition(sf::Vector2f(this->position.x, this->position.y + (i + 1) * this->cellHeight));
		window.draw(cell);
		window.draw(cellText);
	}

	for (int i = 0; i < this->data->size(); i++)
	{
		for (int j = 0; j < this->data->operator[](0).size(); j++)
		{
			cellText.setString(std::to_string(this->data->operator[](i)[j]));
			cellText.setPosition(sf::Vector2f(this->position.x + (j + 1) * this->cellWidth, this->position.y + (i + 1) * this->cellHeight));
			cell.setPosition(sf::Vector2f(this->position.x + (j + 1) * this->cellWidth, this->position.y + (i + 1) * this->cellHeight));
			window.draw(cell);
			window.draw(cellText);
		
		}
	}
}


std::vector<int>& Table::operator[](int index)
{
	return this->data->operator[](index);
}

Table& Table::operator=(std::vector<std::vector<int>> data)
{
	*(this->data) = data;
	return (*this);
}

Table::~Table()
{
	delete this->data;
}