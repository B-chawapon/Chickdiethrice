#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

#include<stdio.h>
#include<sstream>

using namespace std;
class Buttuon {
public:
	Buttuon() {


	}
	Buttuon(string t,sf::Vector2f size,int charSize,sf::Color bgColor,sf::Color textcolor)
	{
		text.setString(t);
		text.setFillColor(textcolor);
		text.setCharacterSize(charSize);
		text.setOrigin(size.x/2,size.y/2);
		
		button.setSize(size);
		button.setFillColor(bgColor);
		button.setOrigin( size.x / 2,size.y / 2 );
	}

	
	void setFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void setBackColor(sf::Color color)
	{
		button.setFillColor(color);
	}
	void setTextColor(sf::Color teecolor)
	{
		text.setFillColor(teecolor);
	}
	void setPosition(sf::Vector2f pos)
	{
		button.setPosition(pos);
	}
	void setScale(sf::Vector2f factor)
	{
		button.setScale({factor.x,factor.y});
		text.setScale({factor.x,factor.y});
	}
	void setPositiontext(sf::Vector2f  pos)
	{
		
		text.setPosition(pos);
	}
	void drawTO(sf::RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}
	bool isMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosx = button.getPosition().x-(button.getSize().x/2);
		float btnPosy = button.getPosition().y- (button.getSize().y / 2);
		
		/*if (mouseX<btnxPosWidth && mouseX>btnPosx && mouseY<btnyPosHeight && mouseY >btnPosy)
		{
			text.setScale(1.2f,1.2f);
			button.setScale(1.2f, 1.2f);
			return true;
		}

		else
		{
			text.setScale(0.9f, 0.9f);
			button.setScale(0.9f, 0.9f);
			return false;
		}*/
		if (((mouseX > btnPosx) && (mouseX < btnPosx + button.getSize().x)
			&& (mouseY > btnPosy) && (mouseY < btnPosy + button.getSize().y)))
		{
			text.setScale(1.2f, 1.2f);
			button.setScale(1.2f, 1.2f);
			return true;
		}

		else
		{
			text.setScale(0.9f, 0.9f);
			button.setScale(0.9f, 0.9f);
			return false;
		}
	}
	bool isMouseOverMove(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		 btnPos.x = button.getPosition().x ;
		 btnPos.y = button.getPosition().y ;
		cout << btnPos.y << '\n';
		if (((mouseX > btnPos.x) && (mouseX < btnPos.x + button.getSize().x)
			&& (mouseY > btnPos.y) && (mouseY < btnPos.y + button.getSize().y)))
		{
			text.setScale(1.2f, 1.2f);
			button.setScale(1.2f, 1.2f);
			
			return true;
		}
		else
		{
			text.setScale(0.9f, 0.9f);
			button.setScale(0.9f, 0.9f);


			return false;
		}
		btnPos.x = 0;
		btnPos.y = 0;
	}
	int  getPos()
	{
		return button.getPosition().y;
	}
private:
	sf::RectangleShape button;
	sf::Text text;
	sf::Vector2f btnPos;





};