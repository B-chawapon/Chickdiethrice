#include "Menu.h"


Menu::Menu(float width, float height,float x, float y)
{
	if (!font.loadFromFile("fonttext/8-BIT WONDER.ttf"))
	{
		// handle error
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Retry");
	menu[0].setScale(1.4f,1.4f);
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setOutlineThickness(3);
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Return to menu");
	menu[1].setScale(1.4f, 1.4f);
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setOutlineThickness(3);

	
	

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		
	}
}
void Menu::SetPOS(float x, float y)
{
	menu[0].setPosition(sf::Vector2f(x + 150, y + 500));
	menu[1].setPosition(sf::Vector2f(x + 450, y + 500));
	
}
