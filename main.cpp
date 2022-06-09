#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
	int main()
	{
		sf::Font font;
		font.loadFromFile("font.ttf");
		sf::Texture bgText;
		bgText.loadFromFile("khungchinh.png");
		sf::RenderWindow window(sf::VideoMode(bgText.getSize().x, bgText.getSize().y), "Main menu", sf::Style::Default);
		window.setFramerateLimit(60);
		sf::Sprite spriteBG;
		spriteBG.setTexture(bgText);

		Textbox nuthome(60, sf::Color::White, false);
		nuthome.setPosition({ 200.f,200.f });
		nuthome.newstring("HOME");
		nuthome.setFont(font);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::Resized:
					break;
				case Event::TextEntered:
					break;
				case Event::KeyPressed:
					break;
				case Event::MouseMoved:
					break;
				case Event::MouseButtonPressed:
					break;
				default:
					break;

			}

			if (nuthome.isMouseOver(window))
			{
				nuthome.setcolor(sf::Color::Red);
			}
			else
			{
				nuthome.setcolor(sf::Color::White);
			}

			window.clear();


			window.draw(spriteBG);
			nuthome.drawTo(window);
			window.display();
		}
		return 0;
	}