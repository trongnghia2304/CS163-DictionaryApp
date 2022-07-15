#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "textbox.h"

class Button
{
public:
	Button() { };
	Button(std::string t, sf::Vector2f size,int charsize, sf::Color bgColor, sf::Color textColor)
	{
		this->text.setString(t);
		this->text.setFillColor(textColor);
		this->text.setCharacterSize(charsize);
		
		this->shape.setSize(size);
		this->shape.setFillColor(bgColor);

	}
	void settextture(sf::Texture& tthinh)
	{
		this->shape.setTexture(&tthinh);
	}
	void setSizeOfButton(sf::Vector2f size)
	{
		this->shape.setSize(size);
	}
	void setText(std::string text)
	{
		this->text.setString(text);
	}
	void setTextture(sf::Texture texture)
	{
		shape.setTexture(&texture);
	}
	void setFont(sf::Font &font)
	{
		this->text.setFont(font);
	}
	void setoutline(sf::Color color)
	{
		this->shape.setOutlineColor(color);
		this->shape.setOutlineThickness(1.f);
	}
	
	void setBgColor(sf::Color color)
	{
		this->shape.setFillColor(color);
	}

	void setTextColor(sf::Color color)
	{
		this->text.setFillColor(color);
	}

	void setPosition(sf::Vector2f pos,int size, float f)
	{
		this->shape.setPosition(pos);
		this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - ((this->text.getGlobalBounds().width+33.f*size/12) / 2.f)-f, this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - ((this->text.getGlobalBounds().height+14.f*size/12) / 2.f));
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(this->shape);
		window.draw(this->text);
	}

	bool isMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		
		float buttonX = shape.getPosition().x;
		float buttonY = shape.getPosition().y;


		float buttonWidth = buttonX + shape.getGlobalBounds().width;
		float buttonHeight = buttonWidth + shape.getGlobalBounds().height;

		if (mouseX<buttonWidth && mouseX>buttonX && mouseY<buttonHeight && mouseY>buttonY)
			return true;
		return false;

	}
	bool isKickMouse(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonX = shape.getPosition().x;
		float buttonY = shape.getPosition().y;

		float buttonWidth = buttonX + shape.getGlobalBounds().width;
		float buttonHeight = buttonY + shape.getGlobalBounds().height;

		if (mouseX<buttonWidth && mouseX>buttonX && mouseY<buttonHeight && mouseY>buttonY)
			return true;
		return false;

	}
	std::string getText()
	{
		return this->text.getString();
	}
private:
	sf::RectangleShape shape;
	sf::Text text;
};

