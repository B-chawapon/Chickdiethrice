#include "Menu.h"


Menu::Menu(float width, float height,float x, float y)
{
	if (!font.loadFromFile("fonttext/GOTHICB.ttf"))
	{
		// handle error
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Insert name");
	

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	

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
		menu[selectedItemIndex].setScale(1.f, 1.f);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		menu[selectedItemIndex].setScale(2.f,2.f);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setScale(1.f, 1.f);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		menu[selectedItemIndex].setScale(2.f, 2.f);
	}
}
void Menu::SetPOS(float x, float y)
{
	menu[0].setPosition(sf::Vector2f(x + 500, y + 200));
	menu[1].setPosition(sf::Vector2f(x + 500, y + 300));
	menu[2].setPosition(sf::Vector2f(x + 500, y + 400));
}
