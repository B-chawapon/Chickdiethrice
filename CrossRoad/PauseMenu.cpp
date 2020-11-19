#include "PauseMenu.h"


Pausemenu::Pausemenu(float width, float height,float x ,float y)
{
	if (!font.loadFromFile("fonttext/GOTHICB.ttf"))
	{
		// handle error
	}

	pausemenu[0].setFont(font);
	pausemenu[0].setFillColor(sf::Color::Red);
	pausemenu[0].setString("Resume");
	

	pausemenu[1].setFont(font);
	pausemenu[1].setFillColor(sf::Color::White);
	pausemenu[1].setString("Save Game");

	pausemenu[2].setFont(font);
	pausemenu[2].setFillColor(sf::Color::White);
	pausemenu[2].setString("Return to Menu");
	

	selectedItemIndex = 0;
}


Pausemenu::~Pausemenu()
{
}

void Pausemenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(pausemenu[i]);
	}
}

void Pausemenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pausemenu[selectedItemIndex].setScale(1.f, 1.f);
		pausemenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		pausemenu[selectedItemIndex].setFillColor(sf::Color::Red);
		pausemenu[selectedItemIndex].setScale(2.f, 2.f);
	}
}

void Pausemenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		pausemenu[selectedItemIndex].setScale(1.f, 1.f);
		pausemenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		pausemenu[selectedItemIndex].setFillColor(sf::Color::Red);
		pausemenu[selectedItemIndex].setScale(2.f, 2.f);
	}
}
void Pausemenu::SetPOS(float x,float y)
{
	pausemenu[0].setPosition(sf::Vector2f(x + 500, y+200 ));
	pausemenu[1].setPosition(sf::Vector2f(x + 500, y+300));
	pausemenu[2].setPosition(sf::Vector2f(x + 500,y+400 ));
}


