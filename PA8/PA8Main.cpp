#include "PA8Header.h"

int main()
{
	sf::Font font;
	font.loadFromFile("LucidaBrightRegular.ttf");

	int x = 0, y = 0;

	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Thanksgiving Invaders", sf::Style::Close);
	window.setPosition(sf::Vector2i(500, 300));

	sf::Event windowEvent;
	while (window.isOpen())
	{
		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
				//if window is closed
			case sf::Event::Closed:
				window.close(); // how you close the window
				break;
			}
		}
		mainMenu(window, font);
	}

	return 0;
}