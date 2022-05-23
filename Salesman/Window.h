#pragma once
#include "Graph.h"
#include "Button.h"
#include <vector>

class Window
{
private:
	Graph graph;
	std::vector<Button> buttons;
	sf::Font arial;
	sf::RenderWindow *MainWindow;
	
	struct Menu
	{
		enum What
		{
			Nothing,
			Btn_Pressed
		}what;

		enum Btns
		{
			PRINT_ADJ,
			EVAL,
			DEL

		}btn_key_code;

		int first_index;
		Menu() : first_index(-1) {};

	} menu;




public:
	Window();
	Window(Graph graph);
	~Window();

	void drawBttns();

	void getButtonsEvent(const sf::Event& event, const sf::Vector2i& mouse_pos);
	
	void nullMenu();

	void init();
};
