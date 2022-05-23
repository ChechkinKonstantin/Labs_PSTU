#include "TextInput.h"


std::string TextInput::getInput(sf::Font& font)
{
	sf::RenderWindow window(sf::VideoMode(500, 200), "Input", sf::Style::Titlebar | sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;
	
	this->border.setSize(sf::Vector2f(400, 80));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				this->setSelected(true);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				this->setSelected(false);
			}
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				this->setSelected(false);
				window.close();
			}

			switch (event.type)
			{
			case sf::Event::Closed:
				this->setSelected(false);
				window.close();

			case sf::Event::TextEntered:
				this->typedOn(event);
			}
		}
		window.clear(bgColor);
		this->draw(window);
		window.display();

	}
	return this->getText();
}

TextInput::TextInput()
{

}

TextInput::TextInput(int size, sf::Color color, bool sel)
{

	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;

	sf::Color OutLineColor;
	OutLineColor.r = 30;
	OutLineColor.g = 159;
	OutLineColor.b = 225;

	this->inscription.setCharacterSize(size);
	this->inscription.setFillColor(color);
	this->inscription.setString("Output: ");
	this->textbox.setCharacterSize(size);
	this->textbox.setFillColor(color);

	this->border.setFillColor(bgColor);
	this->border.setOutlineColor(OutLineColor);
	this->border.setOutlineThickness(3);
	this->border.setSize(sf::Vector2f(400, 80));

	this->isSelected = sel;
	if (sel)
	{
		this->textbox.setString("_");
	}
	else
	{
		this->textbox.setString("");
	}
}

void TextInput::typedOn(sf::Event input)
{
	if (this->isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (this->hasLimit)
			{
				if (this->text.str().length() <= this->limit)
				{
					inputLogic(charTyped);
				}
				else if (this->text.str().length() > this->limit && charTyped == DELETE_KEY)
				{
					deleteLastChar();
				}
			}
			else
			{
				inputLogic(charTyped);
			}
		}
	}
}

void TextInput::setFont(sf::Font& font)
{
	this->textbox.setFont(font);
	this->inscription.setFont(font);

}

void TextInput::setPosition(sf::Vector2f pos)
{
	this->textbox.setPosition(sf::Vector2f(pos.x + 120 , pos.y + this->border.getSize().y / 3.5));
	this->border.setPosition(pos);
	this->inscription.setPosition(sf::Vector2f(pos.x + 20, pos.y + this->border.getSize().y / 3.5));
}


void TextInput::setLimit(bool ToF)
{
	this->hasLimit = ToF;
}

void TextInput::setLimit(bool ToF, int lim)
{
	this->hasLimit = ToF;
	this->limit = lim - 1;
}

void TextInput::setSelected(bool sel)
{
	this->isSelected = sel;
	if (!sel)
	{
		std::string t = this->text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		this->textbox.setString(newT);
	}
}

void TextInput::draw(sf::RenderWindow& window)
{
	window.draw(this->border);
	window.draw(this->textbox);
	window.draw(this->inscription);
}

std::string TextInput::getText()
{
	return this->text.str();
}

void TextInput::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		this->text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (this->text.str().length() > 0)
		{
			this->deleteLastChar();
		}
	}
	this->textbox.setString(this->text.str() + "_");
}


void TextInput::deleteLastChar()
{
	std::string t = this->text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	this->text.str("");
	this->text << newT;
	this->textbox.setString(this->text.str());
}
