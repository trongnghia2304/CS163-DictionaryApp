#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include "textbox.h"
#include "button.h"
#include "Trie.h"
#include "splitTu.h"



int main()
{
	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Texture bgText;
	bgText.loadFromFile("dohoa1.png");

	sf::Sprite spriteBG;
	spriteBG.setTexture(bgText);

	TrieNode* root = nullptr;
	root = new TrieNode();
	insert(root, "hello", "xin chao");



	Textbox nuthome(60, sf::Color::White, false);
	nuthome.setPosition({ 300.f,200.f });
	nuthome.newstring("HOME");
	nuthome.setFont(font);
	nuthome.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutNewword(60, sf::Color::White, false);
	nutNewword.setPosition({ 400.f,300.f });
	nutNewword.newstring("NEW WORD");
	nutNewword.setFont(font);
	nutNewword.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutLang(60, sf::Color::White, false);
	nutLang.setPosition({ 570.f,400.f });
	nutLang.newstring("LANGUAGES");
	nutLang.setFont(font);
	nutLang.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutExit(60, sf::Color::White, false);
	nutExit.setPosition({ 870.f,500.f });
	nutExit.newstring("EXIT");
	nutExit.setFont(font);
	nutExit.setscaleAndOut(2.f, 0, 187, 191);
bg:
	sf::RenderWindow window(sf::VideoMode(bgText.getSize().x, bgText.getSize().y), "Main menu", sf::Style::Default);
	window.setFramerateLimit(60);
	window.setPosition({ 40,10 });
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		if (nuthome.isMouseOver(window))
		{
			nuthome.setcolor(sf::Color::Red);
			nuthome.setscaleAndOut(3.f, 245, 168, 154);
		}
		else
		{
			nuthome.setcolor(sf::Color::White);
			nuthome.setscaleAndOut(2.f, 0, 187, 191);
		}

		if (nutNewword.isMouseOver(window))
		{
			nutNewword.setcolor(sf::Color::Red);
			nutNewword.setscaleAndOut(3.f, 245, 168, 154);
		}
		else
		{
			nutNewword.setcolor(sf::Color::White);
			nutNewword.setscaleAndOut(2.f, 0, 187, 191);
		}

		if (nutLang.isMouseOver(window))
		{
			nutLang.setcolor(sf::Color::Red);
			nutLang.setscaleAndOut(3.f, 245, 168, 154);
		}
		else
		{
			nutLang.setcolor(sf::Color::White);
			nutLang.setscaleAndOut(2.f, 0, 187, 191);
		}
		if (nutLang.isKickMouse(window))
		{
			window.close();
			sf::Texture BgLang;
			BgLang.loadFromFile("khung2.png");
			sf::RenderWindow windowLang(sf::VideoMode(BgLang.getSize().x, BgLang.getSize().y), "LANGUGES", sf::Style::None);
			windowLang.setPosition({ 40,10 });
			sf::Sprite spriteBgLang;
			spriteBgLang.setTexture(BgLang);
			sf::RectangleShape khungnhap;
			int change = 1;
			Textbox noidungnhap(20, sf::Color::Black, false);
			noidungnhap.setPosition({ 390.f,115.f });
			noidungnhap.newstring("");
			noidungnhap.setFont(font);
			noidungnhap.setLimit1(false, 60);

			Textbox language(50, sf::Color::White, false);
			language.newstring("ENG");
			language.setFont(font);
			language.setPosition({ 170.f,90.f });
			language.setscaleAndOut(2.f, 255, 102, 0);
			int langcheck = 1;

			Textbox definationoRKey(30, sf::Color(247, 234, 118), false);
			definationoRKey.newstring("DEFINITION:");
			definationoRKey.setFont(font);
			definationoRKey.setPosition({ 400.f,200.f });
			/*definationoRKey.setscaleAndOut(2.f, 232, 214, 49);*/


			//express content when inputing
			/*Textbox expressOutWord(20, sf::Color::White, false);
			expressOutWord.newstring("Meaning");
			expressOutWord.setFont(font);
			expressOutWord.setPosition({ 405.f,250.f });*/
			vector<Textbox> expressKhung;
			expressKhung.resize(5);
			for (int i = 0; i < 5; i++)
			{
				expressKhung[i].setcolor(sf::Color::White);
				expressKhung[i].setSize(20);
				expressKhung[i].setSelected(false);
				expressKhung[i].newstring("");
				expressKhung[i].setFont(font);
				expressKhung[i].setPosition({ 405.f,250.f + 0 * i });
			}
			int n = 0;
			std::string meaning;
			std::string key;




			while (windowLang.isOpen())
			{
				sf::Event eventLang;

				while (windowLang.pollEvent(eventLang))
				{
					if (eventLang.type == sf::Event::Closed)
						windowLang.close();
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						float posx = sf::Mouse::getPosition(windowLang).x;
						float posy = sf::Mouse::getPosition(windowLang).y;
						if (posx > 1039 && posx < 1090 && posy>80 && posy < 124)
						{
							if (change == 1)
							{
								BgLang.loadFromFile("khung21.png");
								spriteBgLang.setTexture(BgLang);
								change = -1;
							}
							else if (change == -1)
							{

								BgLang.loadFromFile("khung2.png");
								spriteBgLang.setTexture(BgLang);
								change = 1;
							}
						}
						if (posx > 367 && posx < 986 && posy>99 && posy < 153)
						{
							noidungnhap.clearString();
							noidungnhap.setSelected(true);
						}
						else
						{
							noidungnhap.setSelected(false);
						}
						if (posx > 1127 && posx < 1159 && posy>77 && posy < 130)
						{
							windowLang.close();
							goto bg;
						}

					}
					if (eventLang.type == sf::Event::TextEntered)
					{
						noidungnhap.typeOn(eventLang);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						n = 0;
						noidungnhap.setSelected(false);

						key = noidungnhap.getText();
						bool check = lookUpMeaning1(root, key, meaning);
						if (!check)
						{
							n++;
							expressKhung[0].newstring("NOT WORD");
						}
						else
						{
							std::vector<string> cumDong = cumTu(meaning, 90);
							for (int i = 0; i < cumDong.size(); i++)
							{
								n++;
								expressKhung[i].newstring(cumDong[i]);
							}
						}


					}
					if (language.isKickMouse(windowLang))
					{
						if (langcheck == 1)
						{
							language.newstring("VNM");
							langcheck = -1;
						}
						else if (langcheck == -1)
						{
							language.newstring("ENG");
							langcheck = 1;
						}
					}
				}


				windowLang.clear();
				windowLang.draw(spriteBgLang);
				windowLang.draw(khungnhap);
				noidungnhap.drawTo(windowLang);
				for (int i = 0; i < n; i++)
					expressKhung[i].drawTo(windowLang);
				/*expressOutWord.drawTo(windowLang);*/
				definationoRKey.drawTo(windowLang);
				language.drawTo(windowLang);
				windowLang.display();
			}

		}
		if (nutExit.isMouseOver(window))
		{
			nutExit.setcolor(sf::Color::Red);
			nutExit.setscaleAndOut(3.f, 245, 168, 154);
		}
		else
		{
			nutExit.setcolor(sf::Color::White);
			nutExit.setscaleAndOut(2.f, 0, 187, 191);
		}
		if (nutExit.isKickMouse(window))
			window.close();


		window.clear();


		window.draw(spriteBG);
		nuthome.drawTo(window);
		nutLang.drawTo(window);
		nutNewword.drawTo(window);
		nutExit.drawTo(window);
		window.display();
	}
	Deallocate(root);
}