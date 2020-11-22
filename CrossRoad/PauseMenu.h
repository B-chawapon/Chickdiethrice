#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2

class Pausemenu
{
public:
	Pausemenu(float width, float height, float x, float y);
	~Pausemenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void SetPOS(float x, float y);
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text pausemenu[MAX_NUMBER_OF_ITEMS];

};

class PauseMenu
{
};
