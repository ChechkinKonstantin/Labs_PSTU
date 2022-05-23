#include "Window.h"
#include "Vertex.h"
#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include "Button.h"
#include <limits>
#include "Table.h"
#include "TextInput.h"

#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 60


Window::Window()
{

}

Window::Window(Graph graph)
{
	sf::ContextSettings settings(0, 0, 10);
	this->arial.loadFromFile("arialmt.ttf");
	this->graph = graph;
	this->MainWindow = new sf::RenderWindow(sf::VideoMode(1200, 800), "Salesman", sf::Style::Close, settings);
	std::vector<std::string> bttn_names =
	{
		"Print Adjective Matrix",
		"Print Answer",
		"Delete Vertex",
	};
	for (int i = 0; i < bttn_names.size(); i++)
	{
		this->buttons.push_back(Button(bttn_names[i], sf::Vector2f(20, 20 + i * BUTTON_HEIGHT + 10 * i), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), arial));
	}
}

Window::~Window()
{
	delete this->MainWindow;
}


void Window::drawBttns()
{
	for (int i = 0; i < this->buttons.size(); i++)
	{
		this->buttons[i].draw(*MainWindow);
	}
}

void Window::getButtonsEvent(const sf::Event& event, const sf::Vector2i& mouse_pos)
{
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.key.code == sf::Mouse::Left) 
		{
			for (int i = 0; i < this->buttons.size(); ++i)
			{
				if (this->buttons[i].checkCollision(mouse_pos))
				{
					this->menu.what = Menu::What::Btn_Pressed;

					if (this->buttons[i].getString() == std::string("Print Adjective Matrix"))
					{
						this->menu.btn_key_code = Window::Menu::Btns::PRINT_ADJ;
					}
					else if (this->buttons[i].getString() == std::string("Print Answer")) 
					{
						this->menu.btn_key_code = Window::Menu::Btns::EVAL;
					}
					else if (this->buttons[i].getString() == std::string("Delete Vertex"))
					{
						this->menu.btn_key_code = Window::Menu::Btns::DEL;
					}
					return;
				}
			}

		}

	}
}

void Window::nullMenu()
{
	this->menu.first_index = -1;
	this->menu.what = Window::Menu::What::Nothing;
}


void Window::init()
{

	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;

	Button solution("Solution: ", sf::Vector2f(3, this->MainWindow->getSize().y - BUTTON_HEIGHT), sf::Vector2f(this->MainWindow->getSize().x - 6, BUTTON_HEIGHT - 3), this->arial);

	while (MainWindow->isOpen())
	{
		sf::Event event;
		std::string name;


		while (MainWindow->pollEvent(event))
		{
			this->getButtonsEvent(event, sf::Mouse::getPosition(*MainWindow));

			switch (event.type)
			{
			case sf::Event::Closed:
				MainWindow->close();
				break;
			case sf::Event::Resized:
				break;
			case sf::Event::MouseButtonPressed:

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (this->menu.what != Window::Menu::What::Btn_Pressed) 
					{
						sf::Vector2f position(sf::Mouse::getPosition(*MainWindow).x - 50, sf::Mouse::getPosition(*MainWindow).y - 50);
						TextInput input(30, sf::Color::White, true);
						input.setPosition({ 50, 50 });
						input.setFont(this->arial);

						/*std::cout << "Enter name of vertex: ";
						std::cin >> name;*/
						this->graph.addVertex(Vertex(position, input.getInput(this->arial), arial));

					}
					else
					{
						if (this->menu.btn_key_code == Window::Menu::Btns::EVAL || this->menu.btn_key_code == Window::Menu::Btns::DEL) 
						{

							if (this->graph.coordsIsInVerticies(sf::Vector2f(sf::Mouse::getPosition(*MainWindow).x - 50, sf::Mouse::getPosition(*MainWindow).y - 50))\
								&& this->menu.first_index == -1)
							{
								this->menu.first_index = this->graph.getVertexIndex(this->graph.getVertexInCoords(sf::Vector2f(sf::Mouse::getPosition(*MainWindow).x - 50, sf::Mouse::getPosition(*MainWindow).y - 50)));
							}

						}
					}

				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) )
				{
					if (this->graph.coordsIsInVerticies(sf::Vector2f(sf::Mouse::getPosition(*MainWindow).x - 50, sf::Mouse::getPosition(*MainWindow).y - 50)))
					{
						this->graph.addVertexToBuffer(this->graph.getVertexInCoords(sf::Vector2f(sf::Mouse::getPosition(*MainWindow).x - 50, sf::Mouse::getPosition(*MainWindow).y - 50)));
					}

				}
				break;
			}

			if (this->menu.what == Window::Menu::What::Btn_Pressed) 
			{
				if (this->menu.btn_key_code == Window::Menu::Btns::PRINT_ADJ) 
				{
					this->graph.printAdjMatrix(this->arial);
					this->nullMenu();
				}
				else if (this->menu.btn_key_code == Window::Menu::Btns::EVAL) 
				{
					if (this->menu.first_index != -1) 
					{
						this->graph.clearPath();
						this->graph.eval(this->menu.first_index);
						std::vector<int> path = this->graph.getPath();
						int lenOfPath = this->graph.getLenOfPath();
						std::vector<std::string> names = this->graph.getVertexArray();
						std::string output;

						output = "Shortest way: ";
						for (int i = 0; i < path.size(); i++)
						{
							output += names[path[i]] + " -> ";
						}
						output += names[menu.first_index];
						if (lenOfPath == INT_MAX)
						{
							output = "Problem haven't solving";
							solution.setString(output);
						}
						else
						{
							output += "\t\t\tShortest path length: " + std::to_string(lenOfPath);
							solution.setString(output);
						}
						this->nullMenu();
					}
				}
				else if (this->menu.btn_key_code == Window::Menu::Btns::DEL)
				{
					if (this->menu.first_index != -1)
					{
						this->graph.delVertex(this->menu.first_index);
						this->nullMenu();
					}
				}
				
			}

		}

		MainWindow->clear(bgColor);

		this->graph.draw(*MainWindow, arial);
		this->drawBttns();
		solution.draw(*MainWindow);

		MainWindow->display();
		

	}
	_CrtDumpMemoryLeaks();
}