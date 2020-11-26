#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
#include<stdio.h>
#include<string.h>
using namespace std;

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
class Textbox
{
public:
	Textbox() {



	}
	Textbox(int size, sf::Color color, bool sel, sf::Color outline, int sizeoutline)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		textbox.setOutlineColor(outline);
		textbox.setOutlineThickness(sizeoutline);
		isSelected = sel;
		if (sel)
		{
			textbox.setString("_");
		}
		else
		{
			textbox.setString("");
		}
	}
	void setFont(sf::Font& font)
	{
		textbox.setFont(font);
	}
	void setPosition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}
	void setLimit(bool Tof,int lim)
	{
		hasLimit = Tof;
		limit = lim - 1;
	}
	void setColor(sf::Color color)
	{
		textbox.setFillColor(color);
	}
	void setSelected(bool sel)
	{
		isSelected = sel;
		if (! sel)
		{
			string t = text.str();
			string newT = "";
			for (int i = 0; i < t.length() ; i++)
			{
				newT += t[i];
			}
		}
	}
	void setStr(string a)
	{
		return textbox.setString(a);
	}
	void setInt(int k)
	{
		stringstream aa;
			aa << k;
			string wtf;
			aa >> wtf;
		return textbox.setString(wtf);
	}
	string getText()
	{
		return text.str();
	}
	void drawTo(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}
	void typeOn(sf::Event input)
	{
		if (isSelected)
		{
			int charTyped = input.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit) {
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY)
					{
						deleteLastChar();
					}
				}
				else {
					inputLogic(charTyped);
				}
			}
		}
	}
	
private:
	sf::Text textbox;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped)
	{
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
		textbox.setString(text.str()+"");
	}
		void deleteLastChar() 
		{
			string t = text.str();
			string newT = "";
			for (int i = 0; i < t.length() - 1; i++)
			{
				newT += t[i];
			}
			text.str("");
			text << newT;

			textbox.setString(text.str());
		}
	
};

 