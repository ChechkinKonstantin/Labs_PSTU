#include <SFML/Graphics.hpp>
#include "Window.h"


int main()
{
	Window* window = new Window(Graph());
	window->init();
	return 0;
}
