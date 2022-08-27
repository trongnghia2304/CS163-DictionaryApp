//#include <SFML/Graphics.hpp>
//#include "mainmenu.h"
//#include "textbox.h"
//#include "button.h"
//#include "Trie2.h"
//#include "splitTu.h"
//#include "addNewWord.h"
//#include <fstream>
//#include "edit_defination.h"
//#include "randomword.h"
//#include "switch_dataset.h"
//#include "random4.h"
//#include "saveDic.h"

#include "UI.h"
#include "Trie2.h"
#include "Dictionary2.h"


int main()
{
	TrieNode* englishVietnam = nullptr;
	TrieNode* englishVietnamDef = nullptr;
	TrieNode* slang = nullptr;
	TrieNode* slangDef = nullptr;
	TrieNode* emotiondef = nullptr;
	TrieNode* emotion = nullptr;
	TrieNode* VietnamEnglish = nullptr;
	TrieNode* VietnamEnglishDef = nullptr;
	TrieNode* rootEngLish = nullptr;
	TrieNode* rootVietNam = nullptr;

	int chooseDic = 1;
	bool dicEngViet = false;
	bool dicSlang = false;
	bool dicEmotion = false;
	bool dicVietEng = false;


	build_data(englishVietnam, englishVietnamDef, "sample3.txt", '`');
	build_data(slang, slangDef, "sample1.txt", '`');
	build_data(emotion, emotiondef, "emotional.txt", '`');
	build_data(VietnamEnglish, VietnamEnglishDef, "sample4.txt", '`');

	rootEngLish = englishVietnam;
	rootVietNam = englishVietnamDef;

	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Texture bgText;
	bgText.loadFromFile("UI//dohoa1.png");

	sf::Sprite spriteBG;
	spriteBG.setTexture(bgText);
	Textbox nuthome(60, sf::Color::White, false);
	nuthome.setPosition({ 300.f,200.f });
	nuthome.newstring("HOME");
	nuthome.setFont(font);
	nuthome.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutNewword(60, sf::Color::White, false);
	nutNewword.setPosition({ 400.f,300.f });
	nutNewword.newstring("PLAYGAME");
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
		if (nuthome.isKickMouse(window) && event.type == sf::Event::MouseButtonPressed)
		{
			window.close();
			sf::Texture bgSet;
			bgSet.loadFromFile("UI//khungsetting.png");
			sf::RenderWindow windowAdd(sf::VideoMode(bgSet.getSize().x, bgSet.getSize().y), "SETTING", sf::Style::Default);
			windowAdd.setFramerateLimit(60);
			windowAdd.setPosition({ 40,10 });
			sf::Sprite spriteBgAdd;
			spriteBgAdd.setTexture(bgSet);

			Textbox nuthome(60, sf::Color::White, false);
			nuthome.setPosition({ 300.f,220.f });
			nuthome.newstring("ENGLISH");
			nuthome.setFont(font);
			nuthome.setscaleAndOut(2.f, 0, 187, 191);

			Textbox nutNewword(60, sf::Color::White, false);
			nutNewword.setPosition({ 300.f,400.f });
			nutNewword.newstring("VIETNAM");
			nutNewword.setFont(font);
			nutNewword.setscaleAndOut(2.f, 0, 187, 191);

			Textbox nutLang(60, sf::Color::White, false);
			nutLang.setPosition({ 700.f,220.f });
			nutLang.newstring("EMOTION");
			nutLang.setFont(font);
			nutLang.setscaleAndOut(2.f, 0, 187, 191);

			Textbox nutExit(60, sf::Color::White, false);
			nutExit.setPosition({ 700.f,400.f });
			nutExit.newstring("SLANG");
			nutExit.setFont(font);
			nutExit.setscaleAndOut(2.f, 0, 187, 191);

			Textbox nutExit2(60, sf::Color::Blue, false);
			nutExit2.setPosition({ 120.f,100.f });
			nutExit2.newstring("RESET");
			nutExit2.setFont(font);
			nutExit2.setscaleAndOut(2.f, 0, 187, 191);
			while (windowAdd.isOpen())
			{
				sf::Event event;
				while (windowAdd.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						windowAdd.close();
						goto bg;
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						float mouseX = sf::Mouse::getPosition(windowAdd).x;
						float mouseY = sf::Mouse::getPosition(windowAdd).y;
						if (mouseX > 1128 && mouseY > 80 && mouseX < 1162 && mouseY < 128)
						{
							windowAdd.close();
							goto bg;
						}

					}
					if (nuthome.isMouseOver(windowAdd))
					{
						nuthome.setcolor(sf::Color::Red);
						nuthome.setscaleAndOut(3.f, 245, 168, 154);
					}
					else
					{
						nuthome.setcolor(sf::Color::White);
						nuthome.setscaleAndOut(2.f, 0, 187, 191);
					}
					if (nuthome.isKickMouse(windowAdd) && event.type == sf::Event::MouseButtonPressed)
					{
						rootEngLish = englishVietnam;
						rootVietNam = englishVietnamDef;
						chooseDic = 1;
						windowAdd.close();
						goto bg;
					}
					if (nutNewword.isMouseOver(windowAdd))
					{
						nutNewword.setcolor(sf::Color::Red);
						nutNewword.setscaleAndOut(3.f, 245, 168, 154);
					}
					else
					{
						nutNewword.setcolor(sf::Color::White);
						nutNewword.setscaleAndOut(2.f, 0, 187, 191);
					}
					if (nutNewword.isKickMouse(windowAdd) && event.type == sf::Event::MouseButtonPressed)
					{
						rootEngLish = VietnamEnglish;
						rootVietNam = VietnamEnglishDef;
						chooseDic = 4;
						windowAdd.close();
						goto bg;
					}
					if (nutLang.isMouseOver(windowAdd))
					{
						nutLang.setcolor(sf::Color::Red);
						nutLang.setscaleAndOut(3.f, 245, 168, 154);
					}
					else
					{
						nutLang.setcolor(sf::Color::White);
						nutLang.setscaleAndOut(2.f, 0, 187, 191);
					}
					if (nutLang.isKickMouse(windowAdd) && event.type == sf::Event::MouseButtonPressed)
					{
						rootEngLish = emotion;
						rootVietNam = emotiondef;
						chooseDic = 3;
						windowAdd.close();
						goto bg;
					}
					if (nutExit.isMouseOver(windowAdd))
					{
						nutExit.setcolor(sf::Color::Red);
						nutExit.setscaleAndOut(3.f, 245, 168, 154);
					}
					else
					{
						nutExit.setcolor(sf::Color::White);
						nutExit.setscaleAndOut(2.f, 0, 187, 191);
					}
					if (nutExit.isKickMouse(windowAdd) && event.type == sf::Event::MouseButtonPressed)
					{
						rootEngLish = slang;
						rootVietNam = slangDef;
						chooseDic = 2;
						windowAdd.close();
						goto bg;
					}
					//Reset original tree (not finished)
					if (nutExit2.isMouseOver(windowAdd))
					{
						nutExit2.setcolor(sf::Color::Red);
						nutExit2.setscaleAndOut(3.f, 245, 168, 154);
					}
					else
					{
						nutExit2.setcolor(sf::Color::Blue);
						nutExit2.setscaleAndOut(2.f, 0, 187, 191);
					}
					if (nutExit2.isKickMouse(windowAdd))
					{
						if (chooseDic == 2 && !dicSlang)
						{
							windowAdd.close();
							goto bg;
						}
						else if (chooseDic == 2 && dicSlang)
						{
							TrieNode* curr = slang;
							TrieNode* currDef = slangDef;
							slang = nullptr;
							slangDef = nullptr;
							build_data(slang, slangDef, "sample1Ori.txt", '`');
							rootEngLish = slang;
							rootVietNam = slangDef;
							windowAdd.close();
							goto bg;
						}
						if (chooseDic == 1 && !dicEngViet)
						{
							windowAdd.close();
							goto bg;
						}
						else if (chooseDic == 1 && dicEngViet)
						{
							TrieNode* curr = englishVietnam;
							TrieNode* currDef = englishVietnamDef;
							englishVietnam = nullptr;
							englishVietnamDef = nullptr;
							build_data(englishVietnam, englishVietnamDef, "sample3Ori.txt", '`');
							rootEngLish = englishVietnam;
							rootVietNam = englishVietnamDef;
							windowAdd.close();
							goto bg;
						}

						if (chooseDic == 4 && !dicVietEng)
						{
							windowAdd.close();
							goto bg;
						}
						else if (chooseDic == 4 && dicVietEng)
						{
							TrieNode* curr = VietnamEnglish;
							TrieNode* currDef = VietnamEnglishDef;
							VietnamEnglish = nullptr;
							VietnamEnglishDef = nullptr;
							build_data(VietnamEnglish, VietnamEnglishDef, "sample4Ori.txt", '`');
							rootEngLish = VietnamEnglish;
							rootVietNam = VietnamEnglishDef;
							windowAdd.close();
							goto bg;
						}
						if (chooseDic == 3 && !dicSlang)
						{
							windowAdd.close();
							goto bg;
						}
						else if (chooseDic == 3 && dicSlang)
						{
							TrieNode* curr = emotion;
							TrieNode* currDef = emotiondef;
							emotion = nullptr;
							emotiondef = nullptr;
							build_data(emotion, emotiondef, "emotionalOri.txt", '`');
							rootEngLish = emotion;
							rootVietNam = emotiondef;
							windowAdd.close();
							goto bg;
						}
					}


				}
				windowAdd.clear();
				windowAdd.draw(spriteBgAdd);
				nuthome.drawTo(windowAdd);
				nutLang.drawTo(windowAdd);
				nutNewword.drawTo(windowAdd);
				nutExit.drawTo(windowAdd);
				nutExit2.drawTo(windowAdd);
				windowAdd.display();

			}

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
		if (nutNewword.isKickMouse(window) && event.type == sf::Event::MouseButtonPressed)
		{

			sf::Texture ttPlay;
			sf::Texture anhkhung;
			sf::Texture anhKey;
			ttPlay.loadFromFile("UI//playgame.png");
			anhkhung.loadFromFile("UI//anh1.png");
			anhKey.loadFromFile("UI//anh2.png");
			window.close();
			sf::Sprite sPlay;
			sPlay.setTexture(ttPlay);

			sf::RenderWindow windowPlay(sf::VideoMode(ttPlay.getSize().x, ttPlay.getSize().y), "PLAY", sf::Style::None);
			windowPlay.setFramerateLimit(60);

			Textbox language(50, sf::Color::White, false);
			language.newstring("KEY");
			language.setFont(font);
			language.setPosition({ 300.f,225.f });
			language.setscaleAndOut(2.f, 255, 102, 0);
			int langcheck = 1;
			TrieNode* rootkey = rootEngLish;
			TrieNode* rootdef = rootVietNam;


			//Khung key
			Button khungKey("", { 400.f,90.f }, 22, sf::Color(255, 214, 130), sf::Color::Black);
			khungKey.setFont(font);
			khungKey.settextture(anhKey);
			khungKey.setPosition({ 428.f,210.f }, 25, -22.f);

			std::string key;
			std::string meaning;
			std::vector<std::string> hello;
			vector < std::string > checkdapan{ 4 };
			//Khung dap an
			std::vector<Button> khungDapAn;
			khungDapAn.resize(4);
			for (int i = 0; i < 4; i++)
			{
				khungDapAn[i] = Button("", { 400.f,90.f }, 15, sf::Color(200, 200, 200), sf::Color::Black);
				khungDapAn[i].settextture(anhkhung);
				khungDapAn[i].setFont(font);
			}
			khungDapAn[0].setPosition({ 188.f,348.f }, 15, 170.f);
			khungDapAn[1].setPosition({ 688.f,348.f }, 15, 170.f);
			khungDapAn[2].setPosition({ 188.f,448.f }, 15, 170.f);
			khungDapAn[3].setPosition({ 688.f,448.f }, 15, 170.f);

			while (windowPlay.isOpen())
			{
				sf::Event eventPlay;

				while (windowPlay.pollEvent(eventPlay))
				{
					if (eventPlay.type == sf::Event::MouseButtonPressed)
					{
						float posx = sf::Mouse::getPosition(windowPlay).x;
						float posy = sf::Mouse::getPosition(windowPlay).y;
						if (language.isKickMouse(windowPlay))
						{
							if (langcheck == 1)
							{
								language.newstring("DEF");
								rootkey = rootVietNam;
								rootdef = rootEngLish;
								langcheck = -1;
							}
							else
							{
								language.newstring("KEY");
								rootkey = rootEngLish;
								rootdef = rootVietNam;
								langcheck = 1;
							}

						}
						if (khungDapAn[0].isKickMouse(windowPlay))
						{
							if (checkdapan[0] == meaning)
								khungDapAn[0].setBgColor(sf::Color::Green);
							else
								khungDapAn[0].setBgColor(sf::Color::Red);
						}
						if (khungDapAn[1].isKickMouse(windowPlay))
						{
							if (checkdapan[1] == meaning)
								khungDapAn[1].setBgColor(sf::Color::Green);
							else
								khungDapAn[1].setBgColor(sf::Color::Red);
						}
						if (khungDapAn[2].isKickMouse(windowPlay))
						{
							if (checkdapan[2] == meaning)
								khungDapAn[2].setBgColor(sf::Color::Green);
							else
								khungDapAn[2].setBgColor(sf::Color::Red);
						}
						if (khungDapAn[3].isKickMouse(windowPlay))
						{
							if (checkdapan[3] == meaning)
								khungDapAn[3].setBgColor(sf::Color::Green);
							else
								khungDapAn[3].setBgColor(sf::Color::Red);
						}
						if (posx > 1126 && posx < 1169 && posy>77 && posy < 128)
						{
							windowPlay.close();
							goto bg;
						}
						if (posx > 911 && posx < 1095 && posy>221 && posy < 296)
						{
							for (int i = 0; i < 4; i++)
							{
								khungDapAn[i].setBgColor(sf::Color(200, 200, 200));
							}
							hello.clear();
							key.clear();
							meaning.clear();
							random_key_4_def(rootkey, rootdef, key, hello, meaning);
							for (int i = 0; i < 4; i++)
							{
								checkdapan[i] = hello[i];
								if (hello[i].length() > 42)
								{
									hello[i].erase(hello[i].begin() + 41, hello[i].end());
								}
								khungDapAn[i].setText(hello[i]);
								string temp2 = key;
								if (temp2.length() > 35)
								{
									temp2.erase(temp2.begin() + 30, temp2.end());
								}
								khungKey.setText(temp2);
								khungKey.setPosition({ 428.f,210.f }, 25, -22.f);
							}

						}
					}



				}


				windowPlay.clear();
				windowPlay.draw(sPlay);
				for (int i = 0; i < 4; i++)
				{
					khungDapAn[i].drawTo(windowPlay);
				}
				khungKey.drawTo(windowPlay);
				language.drawTo(windowPlay);
				windowPlay.display();
			}
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
		if (nutLang.isKickMouse(window) && event.type == sf::Event::MouseButtonPressed)
		{
			window.close();

			sf::Texture BgLang;
			sf::Texture BgLang1;
			BgLang.loadFromFile("UI//khung2.png");
			BgLang1.loadFromFile("UI//khung21.png");
		bgHis:
			sf::RenderWindow windowLang(sf::VideoMode(BgLang.getSize().x, BgLang.getSize().y), "LANGUGES", sf::Style::None);
			windowLang.setFramerateLimit(60);
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

			//Choose Language
			Textbox language(50, sf::Color::White, false);
			language.newstring("KEY");
			language.setFont(font);
			language.setPosition({ 170.f,90.f });
			language.setscaleAndOut(2.f, 255, 102, 0);
			int langcheck = 1;
			TrieNode* root = rootEngLish;


			Textbox definationoRKey(30, sf::Color(247, 234, 118), false);
			definationoRKey.newstring("MEANING: ");
			definationoRKey.setFont(font);
			definationoRKey.setPosition({ 400.f,200.f });
			/*definationoRKey.setscaleAndOut(2.f, 232, 214, 49);*/

			//Khung chua tu yeu thich
			vector<pair<string, string>> likeWord = loadLikeWord("LIKEWORD.txt");


			vector<Textbox> expressKhung;
			expressKhung.resize(5);
			for (int i = 0; i < 5; i++)
			{
				expressKhung[i].setcolor(sf::Color::White);
				expressKhung[i].setSize(20);
				expressKhung[i].setSelected(false);
				expressKhung[i].newstring("");
				expressKhung[i].setFont(font);
				expressKhung[i].setPosition({ 405.f,250.f + 25 * i });
			}
			int n = 0;
			std::string meaning;
			std::string key;

			//Khung goi y
			bool congtac = false;
			std::vector<Button> expressButton;
			expressButton.resize(4);
			for (int i = 0; i < 4; i++)
			{
				expressButton[i] = Button("", { 620.f,50.f }, 20, sf::Color(37, 40, 57), sf::Color::White);
				expressButton[i].setPosition({ 368.f,155.f + i * 51.f }, 20, 250);
				expressButton[i].setFont(font);
				expressButton[i].setoutline(sf::Color::Green);
			}

			Textbox add_button(70, sf::Color(250, 224, 152), false);
			add_button.setFont(font);
			add_button.newstring("ADD");
			add_button.setscaleAndOut(2.f, 193, 255, 193);
			add_button.setPosition({ 400.f,500.f });

			Textbox edit_button(70, sf::Color(250, 224, 152), false);
			edit_button.setFont(font);
			edit_button.newstring("EDIT");
			edit_button.setscaleAndOut(2.f, 193, 255, 193);
			edit_button.setPosition({ 700.f,500.f });

			Textbox del_button(70, sf::Color(250, 224, 152), false);
			del_button.setFont(font);
			del_button.newstring("DEL");
			del_button.setscaleAndOut(2.f, 193, 255, 193);
			del_button.setPosition({ 1000.f,500.f });

			while (windowLang.isOpen())
			{
				sf::Event eventLang;
				change = -1;
				string tempKey = noidungnhap.getText();
				string tempMeaning = "";
				if (tempKey != "")
				{
					bool checkExist = lookUpMeaning1(root, tempKey, tempMeaning);
					vector<pair<string, string>>::iterator kiemtra = find(likeWord.begin(), likeWord.end(), make_pair(tempKey, tempMeaning));
					if (checkExist && kiemtra != likeWord.end())
					{
						change = 1;
					}
				}
				if (add_button.isMouseOver(windowLang))
				{
					add_button.setcolor(sf::Color::Green);
				}
				else
				{
					add_button.setcolor(sf::Color(250, 224, 152));
				}
				if (add_button.isKickMouse(windowLang))
				{
					if (langcheck == 1)
						addingWordScreen(font, rootEngLish, rootVietNam, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
					else if (langcheck == -1)
						addingWordScreen(font, rootVietNam, rootEngLish, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
				}
				if (edit_button.isMouseOver(windowLang))
				{
					edit_button.setcolor(sf::Color::Green);
				}
				else
				{
					edit_button.setcolor(sf::Color(250, 224, 152));
				}
				if (edit_button.isKickMouse(windowLang))
				{
					if (langcheck == 1)
						editWordScreen(font, rootEngLish, rootVietNam, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
					else if (langcheck == -1)
						editWordScreen(font, rootVietNam, rootEngLish, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
				}
				if (del_button.isMouseOver(windowLang))
				{
					del_button.setcolor(sf::Color::Green);
				}
				else
				{
					del_button.setcolor(sf::Color(250, 224, 152));
				}
				if (del_button.isKickMouse(windowLang))
				{
					if (langcheck == 1)
						deleteWordScreen(font, rootEngLish, rootVietNam, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
					else if (langcheck == -1)
						deleteWordScreen(font, rootVietNam, rootEngLish, chooseDic, dicEngViet, dicSlang, dicEmotion, dicVietEng);
				}
				while (windowLang.pollEvent(eventLang))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						float posx = sf::Mouse::getPosition(windowLang).x;
						float posy = sf::Mouse::getPosition(windowLang).y;
						if (posx > 1039 && posx < 1090 && posy>80 && posy < 124)
						{
							if (change == -1 && tempKey != "" && tempMeaning != "")
							{
								likeWord.push_back(make_pair(tempKey, tempMeaning));
							}
						}

						if (posx > 367 && posx < 986 && posy>99 && posy < 153)
						{
							noidungnhap.clearString();
							noidungnhap.setSelected(true);
							congtac = true;
						}
						else
						{
							noidungnhap.setSelected(false);
							congtac = false;
						}
						for (int i = 0; i < 4; i++)
						{
							if (expressButton[i].isKickMouse(windowLang))
							{
								std::string temp = expressButton[i].getText();
								noidungnhap.newstring2(temp);
							}
						}
						if (posx > 159 && posx < 284 && posy>228 && posy < 348)
						{
							windowLang.close();
							sf::Texture texttureLike;
							texttureLike.loadFromFile("UI//favourite.png");
							sf::RenderWindow windowLike(sf::VideoMode(texttureLike.getSize().x, texttureLike.getSize().y), "LIKE", sf::Style::None);
							windowLike.setFramerateLimit(60);
							windowLike.setPosition({ 40,10 });
							sf::Sprite spriteLike;
							spriteLike.setTexture(texttureLike);

							//khung 1



							vector<Textbox> expressKhung1KeyLike;
							expressKhung1KeyLike.resize(3);
							vector<Textbox> expressKhung1meaningLike;
							expressKhung1meaningLike.resize(3);
							for (int i = 0; i < 3; i++)
							{
								expressKhung1meaningLike[i].setcolor(sf::Color::Black);
								expressKhung1meaningLike[i].setSize(15);
								expressKhung1meaningLike[i].setSelected(false);
								expressKhung1meaningLike[i].newstring("");
								expressKhung1meaningLike[i].setFont(font);
								expressKhung1meaningLike[i].setPosition({ 170.f,391.f + 25 * i });
								expressKhung1KeyLike[i].setcolor(sf::Color::Black);
								expressKhung1KeyLike[i].setSize(15);
								expressKhung1KeyLike[i].setSelected(false);
								expressKhung1KeyLike[i].newstring("");
								expressKhung1KeyLike[i].setFont(font);
								expressKhung1KeyLike[i].setPosition({ 170.f,300.f + 25 * i });

							}
							int n1LikeKey = 0;
							int n1LikeMeaning = 0;

							////khung 2
							vector<Textbox> expressKhung2KeyLike;
							expressKhung2KeyLike.resize(3);
							vector<Textbox> expressKhung2meaningLike;
							expressKhung2meaningLike.resize(3);
							for (int i = 0; i < 3; i++)
							{
								expressKhung2meaningLike[i].setcolor(sf::Color::Black);
								expressKhung2meaningLike[i].setSize(15);
								expressKhung2meaningLike[i].setSelected(false);
								expressKhung2meaningLike[i].newstring("");
								expressKhung2meaningLike[i].setFont(font);
								expressKhung2meaningLike[i].setPosition({ 780.f,391.f + 25 * i });
								expressKhung2KeyLike[i].setcolor(sf::Color::Black);
								expressKhung2KeyLike[i].setSize(15);
								expressKhung2KeyLike[i].setSelected(false);
								expressKhung2KeyLike[i].newstring("");
								expressKhung2KeyLike[i].setFont(font);
								expressKhung2KeyLike[i].setPosition({ 780.f,300.f + 25 * i });

							}
							int n2LikeKey = 0;
							int n2LikeMeaning = 0;
							int kickcoLike = likeWord.size();
							int chisoLike = 0;

							while (windowLike.isOpen())
							{
								sf::Event eventLike;
								while (windowLike.pollEvent(eventLike))
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										float posx = sf::Mouse::getPosition(windowLike).x;
										float posy = sf::Mouse::getPosition(windowLike).y;
										if (posx > 218 && posx < 310 && posy>93 && posy < 179)
										{
											releaseLikeWord("LIKEWORD.txt", likeWord);
											likeWord.clear();
											windowLike.close();
											goto bgHis;
										}
										if (posx > 483 && posx < 593 && posy>555 && posy < 605)
										{
											if (chisoLike - 2 >= 0)
												chisoLike -= 2;
										}
										if (posx > 732 && posx < 841 && posy>555 && posy < 603)
										{
											if (kickcoLike - 1 - chisoLike >= 2)
												chisoLike += 2;
										}
										if (posx > 460 && posx < 507 && posy>316 && posy < 363 && (kickcoLike - chisoLike - 1) >= 0)
										{
											likeWord.erase(likeWord.begin() + kickcoLike - 1 - chisoLike);
											kickcoLike = likeWord.size();
										}
										if (posx > 1069 && posx < 1120 && posy>318 && posy < 366 && (kickcoLike - 2 - chisoLike) >= 0)
										{
											likeWord.erase(likeWord.begin() + kickcoLike - 2 - chisoLike);
											kickcoLike = likeWord.size();
										}
									}
									if (kickcoLike - 1 - chisoLike < 0)
									{
										n1LikeKey = 0;
										n1LikeMeaning = 0;

									}
									else
									{
										n1LikeKey = 0;
										std::vector<string> cumDong1Key = cumTu(likeWord[kickcoLike - 1 - chisoLike].first, 42);
										for (int i = 0; i < cumDong1Key.size() && i < 3; i++)
										{
											n1LikeKey++;
											expressKhung1KeyLike[i].newstring(cumDong1Key[i]);
										}
										n1LikeMeaning = 0;
										std::vector<string> cumDong1meaning = cumTu(likeWord[kickcoLike - 1 - chisoLike].second, 42);
										for (int i = 0; i < cumDong1meaning.size() && i < 3; i++)
										{
											n1LikeMeaning++;
											expressKhung1meaningLike[i].newstring(cumDong1meaning[i]);
										}
									}
									if (kickcoLike - 2 - chisoLike < 0)
									{
										n2LikeKey = 0;
										n2LikeMeaning = 0;

									}
									else
									{
										n2LikeKey = 0;
										std::vector<string> cumDong2Key = cumTu(likeWord[kickcoLike - 2 - chisoLike].first, 47);
										for (int i = 0; i < cumDong2Key.size() && i < 3; i++)
										{
											n2LikeKey++;
											expressKhung2KeyLike[i].newstring(cumDong2Key[i]);
										}
										n2LikeMeaning = 0;
										std::vector<string> cumDong2meaning = cumTu(likeWord[kickcoLike - 2 - chisoLike].second, 47);
										for (int i = 0; i < cumDong2meaning.size() && i < 3; i++)
										{
											n2LikeMeaning++;
											expressKhung2meaningLike[i].newstring(cumDong2meaning[i]);
										}
									}
								}

								windowLike.clear();
								windowLike.draw(spriteLike);
								for (int i = 0; i < n1LikeKey; i++)
								{
									expressKhung1KeyLike[i].drawTo(windowLike);
								}
								for (int i = 0; i < n1LikeMeaning; i++)
								{
									expressKhung1meaningLike[i].drawTo(windowLike);
								}
								for (int i = 0; i < n2LikeKey; i++)
								{
									expressKhung2KeyLike[i].drawTo(windowLike);
								}
								for (int i = 0; i < n2LikeMeaning; i++)
								{
									expressKhung2meaningLike[i].drawTo(windowLike);
								}
								windowLike.display();
							}

						}
						if (posx > 156 && posx < 281 && posy>430 && posy < 537)
						{
							releaseLikeWord("LIKEWORD.txt", likeWord);
							likeWord.clear();
							windowLang.close();
							if (langcheck == 1)
							{
								sf::Texture texttureHis;
								texttureHis.loadFromFile("UI//history.png");
								sf::RenderWindow windowHis(sf::VideoMode(texttureHis.getSize().x, texttureHis.getSize().y), "HISTORY", sf::Style::None);
								windowHis.setFramerateLimit(60);
								windowHis.setPosition({ 40,10 });
								sf::Sprite spriteHis;
								spriteHis.setTexture(texttureHis);

								Textbox deleteButton(40, sf::Color::White, false);
								deleteButton.setPosition({ 120.f,550.f });
								deleteButton.newstring("DELETE");
								deleteButton.setFont(font);
								deleteButton.setscaleAndOut(2.f, 0, 187, 191);

								vector<pair<string, string>> khungluu;
								khungluu = viewHistory("ENGLISHWORD.txt");
								int chiso = 0;
								int kichco = khungluu.size();

								//history 1
								Textbox expressKhung1Key(15, sf::Color::Black, false);
								expressKhung1Key.setFont(font);
								expressKhung1Key.setPosition({ 167.f,237.f });

								//history 2
								Textbox expressKhung2Key(15, sf::Color::Black, false);
								expressKhung2Key.setFont(font);
								expressKhung2Key.setPosition({ 753.f,237.f });

								//history 3
								Textbox expressKhung3Key(15, sf::Color::Black, false);
								expressKhung3Key.setFont(font);
								expressKhung3Key.setPosition({ 167.f,415.f });

								//history 4
								Textbox expressKhung4Key(15, sf::Color::Black, false);
								expressKhung4Key.setFont(font);
								expressKhung4Key.setPosition({ 757.f,415.f });

								//history 1
								vector<Textbox> expressKhung1meaning;
								expressKhung1meaning.resize(3);

								//history 2
								vector<Textbox> expressKhung2meaning;
								expressKhung2meaning.resize(3);

								//history 3
								vector<Textbox> expressKhung3meaning;
								expressKhung3meaning.resize(3);

								//history 4
								vector<Textbox> expressKhung4meaning;
								expressKhung4meaning.resize(3);

								for (int i = 0; i < 3; i++)
								{
									//history 1
									expressKhung1meaning[i].setcolor(sf::Color::Black);
									expressKhung1meaning[i].setSize(14);
									expressKhung1meaning[i].setSelected(false);
									expressKhung1meaning[i].newstring("");
									expressKhung1meaning[i].setFont(font);
									expressKhung1meaning[i].setPosition({ 202.f,291.f + 25 * i });

									//history 2
									expressKhung2meaning[i].setcolor(sf::Color::Black);
									expressKhung2meaning[i].setSize(14);
									expressKhung2meaning[i].setSelected(false);
									expressKhung2meaning[i].newstring("");
									expressKhung2meaning[i].setFont(font);
									expressKhung2meaning[i].setPosition({ 788.f,291.f + 25 * i });

									//history 3
									expressKhung3meaning[i].setcolor(sf::Color::Black);
									expressKhung3meaning[i].setSize(14);
									expressKhung3meaning[i].setSelected(false);
									expressKhung3meaning[i].newstring("");
									expressKhung3meaning[i].setFont(font);
									expressKhung3meaning[i].setPosition({ 202.f,469.f + 25 * i });

									//history 4
									expressKhung4meaning[i].setcolor(sf::Color::Black);
									expressKhung4meaning[i].setSize(14);
									expressKhung4meaning[i].setSelected(false);
									expressKhung4meaning[i].newstring("");
									expressKhung4meaning[i].setFont(font);
									expressKhung4meaning[i].setPosition({ 792.f,469.f + 25 * i });
								}
								int n1 = 0;
								int n2 = 0;
								int n3 = 0;
								int n4 = 0;





								while (windowHis.isOpen())
								{
									sf::Event eventHis;
									while (windowHis.pollEvent(eventHis))
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											float posx = sf::Mouse::getPosition(windowHis).x;
											float posy = sf::Mouse::getPosition(windowHis).y;
											if (posx > 299 && posx < 380 && posy>99 && posy < 177)
											{
												windowHis.close();
												khungluu.clear();
												goto bgHis;
											}
											if (posx > 483 && posx < 593 && posy>555 && posy < 605)
											{
												if (chiso - 4 >= 0)
													chiso -= 4;
											}
											if (posx > 732 && posx < 841 && posy>555 && posy < 603)
											{
												if (kichco - 1 - chiso >= 4)
													chiso += 4;
											}
										}

									}
									if (deleteButton.isMouseOver(windowHis))
									{
										deleteButton.setcolor(sf::Color::Red);
										deleteButton.setscaleAndOut(3.f, 245, 168, 154);
									}
									else
									{
										deleteButton.setcolor(sf::Color::White);
										deleteButton.setscaleAndOut(2.f, 0, 187, 191);
									}
									if (deleteButton.isKickMouse(windowHis))
									{
										deleteHistory("ENGLISHWORD.txt");
										windowHis.close();
										khungluu.clear();
										goto bgHis;
									}
									//History 1 content
									if (kichco - 1 - chiso < 0)
									{
										expressKhung1Key.newstring("");
										n1 = 0;
									}
									else
									{
										n1 = 0;
										expressKhung1Key.newstring(khungluu[kichco - 1 - chiso].first);
										std::vector<string> cumDong1 = cumTu(khungluu[kichco - 1 - chiso].second, 50);
										for (int i = 0; i < cumDong1.size() && i < 3; i++)
										{
											n1++;
											expressKhung1meaning[i].newstring(cumDong1[i]);
										}
									}



									//History 2 content
									if (kichco - 2 - chiso < 0)
									{
										expressKhung2Key.newstring("");
										n2 = 0;
									}
									else
									{
										n2 = 0;
										expressKhung2Key.newstring(khungluu[kichco - 2 - chiso].first);
										std::vector<string> cumDong2 = cumTu(khungluu[kichco - 2 - chiso].second, 50);
										for (int i = 0; i < cumDong2.size() && i < 3; i++)
										{
											n2++;
											expressKhung2meaning[i].newstring(cumDong2[i]);
										}
									}
									//History 3 content
									if (kichco - 3 - chiso < 0)
									{
										expressKhung3Key.newstring("");
										n3 = 0;
									}
									else
									{
										n3 = 0;
										expressKhung3Key.newstring(khungluu[kichco - 3 - chiso].first);
										std::vector<string> cumDong3 = cumTu(khungluu[kichco - 3 - chiso].second, 50);
										for (int i = 0; i < cumDong3.size() && i < 3; i++)
										{
											n3++;
											expressKhung3meaning[i].newstring(cumDong3[i]);
										}
									}
									//History 4 content
									if (kichco - 4 - chiso < 0)
									{
										expressKhung4Key.newstring("");
										n4 = 0;
									}
									else
									{
										n4 = 0;
										expressKhung4Key.newstring(khungluu[kichco - 4 - chiso].first);
										std::vector<string> cumDong4 = cumTu(khungluu[kichco - 4 - chiso].second, 50);
										for (int i = 0; i < cumDong4.size() && i < 3; i++)
										{
											n4++;
											expressKhung4meaning[i].newstring(cumDong4[i]);
										}
									}
									windowHis.clear();
									windowHis.draw(spriteHis);
									expressKhung1Key.drawTo(windowHis);
									for (int i = 0; i < n1; i++)
									{
										expressKhung1meaning[i].drawTo(windowHis);
									}
									expressKhung2Key.drawTo(windowHis);
									for (int i = 0; i < n2; i++)
									{
										expressKhung2meaning[i].drawTo(windowHis);
									}
									expressKhung3Key.drawTo(windowHis);
									for (int i = 0; i < n3; i++)
									{
										expressKhung3meaning[i].drawTo(windowHis);
									}
									expressKhung4Key.drawTo(windowHis);
									for (int i = 0; i < n4; i++)
									{
										expressKhung4meaning[i].drawTo(windowHis);
									}
									deleteButton.drawTo(windowHis);
									windowHis.display();
								}
							}
							else if (langcheck == -1)
							{
								sf::Texture texttureHis;
								texttureHis.loadFromFile("UI//historyViet.png");
								sf::RenderWindow windowHis(sf::VideoMode(texttureHis.getSize().x, texttureHis.getSize().y), "HISTORY", sf::Style::None);
								windowHis.setFramerateLimit(60);
								windowHis.setPosition({ 40,10 });
								sf::Sprite spriteHis;
								spriteHis.setTexture(texttureHis);

								Textbox deleteButton(40, sf::Color::White, false);
								deleteButton.setPosition({ 120.f,550.f });
								deleteButton.newstring("DELETE");
								deleteButton.setFont(font);
								deleteButton.setscaleAndOut(2.f, 0, 187, 191);

								vector<pair<string, string>> khungluu;
								khungluu = viewHistory("VIETNAMWORD.txt");
								int chiso = 0;
								int kichco = khungluu.size();

								//history 1
								Textbox expressKhung1meaning(15, sf::Color::Black, false);
								expressKhung1meaning.setFont(font);
								expressKhung1meaning.setPosition({ 287.f,315.f });


								vector<Textbox> expressKhung1key;
								expressKhung1key.resize(3);
								for (int i = 0; i < 3; i++)
								{
									expressKhung1key[i].setcolor(sf::Color::Black);
									expressKhung1key[i].setSize(15);
									expressKhung1key[i].setSelected(false);
									expressKhung1key[i].newstring("");
									expressKhung1key[i].setFont(font);
									expressKhung1key[i].setPosition({ 202.f,230.f + 25 * i });
								}
								int n1 = 0;



								//history 2
								Textbox expressKhung2meaning(15, sf::Color::Black, false);
								expressKhung2meaning.setFont(font);
								expressKhung2meaning.setPosition({ 837.f,315.f });


								vector<Textbox> expressKhung2key;
								expressKhung2key.resize(3);
								for (int i = 0; i < 3; i++)
								{
									expressKhung2key[i].setcolor(sf::Color::Black);
									expressKhung2key[i].setSize(15);
									expressKhung2key[i].setSelected(false);
									expressKhung2key[i].newstring("");
									expressKhung2key[i].setFont(font);
									expressKhung2key[i].setPosition({ 752.f,230.f + 25 * i });
								}
								int n2 = 0;




								//history 3
								Textbox expressKhung3meaning(15, sf::Color::Black, false);
								expressKhung3meaning.setFont(font);
								expressKhung3meaning.setPosition({ 287.f,490.f });


								vector<Textbox> expressKhung3key;
								expressKhung3key.resize(3);
								for (int i = 0; i < 3; i++)
								{
									expressKhung3key[i].setcolor(sf::Color::Black);
									expressKhung3key[i].setSize(15);
									expressKhung3key[i].setSelected(false);
									expressKhung3key[i].newstring("");
									expressKhung3key[i].setFont(font);
									expressKhung3key[i].setPosition({ 202.f,405.f + 25 * i });
								}
								int n3 = 0;



								//history 4
								Textbox expressKhung4meaning(15, sf::Color::Black, false);
								expressKhung4meaning.setFont(font);
								expressKhung4meaning.setPosition({ 837.f,490.f });


								vector<Textbox> expressKhung4key;
								expressKhung4key.resize(3);
								for (int i = 0; i < 3; i++)
								{
									expressKhung4key[i].setcolor(sf::Color::Black);
									expressKhung4key[i].setSize(15);
									expressKhung4key[i].setSelected(false);
									expressKhung4key[i].newstring("");
									expressKhung4key[i].setFont(font);
									expressKhung4key[i].setPosition({ 752.f,405.f + 25 * i });
								}
								int n4 = 0;





								while (windowHis.isOpen())
								{
									sf::Event eventHis;
									while (windowHis.pollEvent(eventHis))
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											float posx = sf::Mouse::getPosition(windowHis).x;
											float posy = sf::Mouse::getPosition(windowHis).y;
											if (posx > 299 && posx < 380 && posy>99 && posy < 177)
											{
												windowHis.close();
												khungluu.clear();
												goto bgHis;
											}
											if (posx > 483 && posx < 593 && posy>555 && posy < 605)
											{
												if (chiso - 4 >= 0)
													chiso -= 4;
											}
											if (posx > 732 && posx < 841 && posy>555 && posy < 603)
											{
												if (kichco - 1 - chiso >= 4)
													chiso += 4;
											}
										}

									}
									if (deleteButton.isMouseOver(windowHis))
									{
										deleteButton.setcolor(sf::Color::Red);
										deleteButton.setscaleAndOut(3.f, 245, 168, 154);
									}
									else
									{
										deleteButton.setcolor(sf::Color::White);
										deleteButton.setscaleAndOut(2.f, 0, 187, 191);
									}
									if (deleteButton.isKickMouse(windowHis))
									{
										deleteHistory("VIETNAMWORD.txt");
										windowHis.close();
										khungluu.clear();
										goto bgHis;
									}

									//History 1 content
									if (kichco - 1 - chiso < 0)
									{
										expressKhung1meaning.newstring("");
										n1 = 0;
									}
									else
									{
										n1 = 0;
										expressKhung1meaning.newstring(khungluu[kichco - 1 - chiso].second);
										std::vector<string> cumDong1 = cumTu(khungluu[kichco - 1 - chiso].first, 50);
										for (int i = 0; i < cumDong1.size(); i++)
										{
											n1++;
											expressKhung1key[i].newstring(cumDong1[i]);
										}
									}



									//History 2 content
									if (kichco - 2 - chiso < 0)
									{
										expressKhung2meaning.newstring("");
										n2 = 0;
									}
									else
									{
										n2 = 0;
										expressKhung2meaning.newstring(khungluu[kichco - 2 - chiso].second);
										std::vector<string> cumDong2 = cumTu(khungluu[kichco - 2 - chiso].first, 50);
										for (int i = 0; i < cumDong2.size(); i++)
										{
											n2++;
											expressKhung2key[i].newstring(cumDong2[i]);
										}
									}
									//History 3 content
									if (kichco - 3 - chiso < 0)
									{
										expressKhung3meaning.newstring("");
										n3 = 0;
									}
									else
									{
										n3 = 0;
										expressKhung3meaning.newstring(khungluu[kichco - 3 - chiso].second);
										std::vector<string> cumDong3 = cumTu(khungluu[kichco - 3 - chiso].first, 50);
										for (int i = 0; i < cumDong3.size(); i++)
										{
											n3++;
											expressKhung3key[i].newstring(cumDong3[i]);
										}
									}
									//History 4 content
									if (kichco - 4 - chiso < 0)
									{
										expressKhung4meaning.newstring("");
										n4 = 0;
									}
									else
									{
										n4 = 0;
										expressKhung4meaning.newstring(khungluu[kichco - 4 - chiso].second);
										std::vector<string> cumDong4 = cumTu(khungluu[kichco - 3 - chiso].first, 50);
										for (int i = 0; i < cumDong4.size(); i++)
										{
											n4++;
											expressKhung4key[i].newstring(cumDong4[i]);
										}
									}
									windowHis.clear();
									windowHis.draw(spriteHis);
									expressKhung1meaning.drawTo(windowHis);
									for (int i = 0; i < n1; i++)
									{
										expressKhung1key[i].drawTo(windowHis);
									}
									expressKhung2meaning.drawTo(windowHis);
									for (int i = 0; i < n2; i++)
									{
										expressKhung2key[i].drawTo(windowHis);
									}
									expressKhung3meaning.drawTo(windowHis);
									for (int i = 0; i < n3; i++)
									{
										expressKhung3key[i].drawTo(windowHis);
									}
									expressKhung4meaning.drawTo(windowHis);
									for (int i = 0; i < n4; i++)
									{
										expressKhung4key[i].drawTo(windowHis);
									}
									deleteButton.drawTo(windowHis);
									windowHis.display();
								}
							}
						}
						if (posx > 1127 && posx < 1159 && posy>77 && posy < 130)
						{
							releaseLikeWord("LIKEWORD.txt", likeWord);
							likeWord.clear();
							windowLang.close();
							goto bg;
						}
						if (posx > 288 && posy > 100 && posx < 346 && posy < 144)
						{
							noidungnhap.clearString();
							string key = "";
							string meaning = "";
							random_word(root, key, meaning);
							noidungnhap.newstring(key);
							noidungnhap.setString2(key);
						}
					}
					if (eventLang.type == sf::Event::TextEntered)
					{
						for (int i = 0; i < 4; i++)
						{
							expressButton[i].setText("");
						}
						noidungnhap.typeOn(eventLang);
						std::string textCheck = noidungnhap.getText();
						vector <pair<string, string>> hello = lookUpMeaning(root, textCheck);
						for (int i = 0; i < 4 && i < hello.size(); i++)
						{
							expressButton[i].setText(hello[i].first);
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && eventLang.type == sf::Event::KeyPressed)
					{
						congtac = false;
						n = 0;
						noidungnhap.setSelected(false);

						key = noidungnhap.getText();
						bool check = lookUpMeaning1(root, key, meaning);
						if (!check)
						{
							n++;
							expressKhung[0].newstring("NOT WORD");
						}
						else if (check)
						{
							std::vector<string> cumDong = cumTu(meaning, 80);
							for (int i = 0; i < cumDong.size() && i < 5; i++)
							{
								n++;
								expressKhung[i].newstring(cumDong[i]);
							}
							if (langcheck == 1)
								savetoHistory(key, "ENGLISHWORD.txt", meaning);
							else if (langcheck == -1)
								savetoHistory(key, "VIETNAMWORD.txt", meaning);
							for (int i = 0; i < 4; i++)
							{
								expressButton[i].setText(key);
							}
						}
					}
					if (language.isKickMouse(windowLang))
					{
						if (langcheck == 1)
						{
							language.newstring("DEF");
							root = rootVietNam;
							langcheck = -1;
						}
						else if (langcheck == -1)
						{
							language.newstring("KEY");
							root = rootEngLish;
							langcheck = 1;
						}
					}
					if (change == 1)
					{
						spriteBgLang.setTexture(BgLang1);
					}
					else if (change == -1)
					{
						spriteBgLang.setTexture(BgLang);
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
				if (congtac)
				{
					for (int i = 0; i < 4; i++)
					{
						expressButton[i].drawTo(windowLang);
					}
				}
				language.drawTo(windowLang);
				add_button.drawTo(windowLang);
				edit_button.drawTo(windowLang);
				del_button.drawTo(windowLang);
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
		if (nutExit.isKickMouse(window) && event.type == sf::Event::MouseButtonPressed)
			window.close();


		window.clear();


		window.draw(spriteBG);
		nuthome.drawTo(window);
		nutLang.drawTo(window);
		nutNewword.drawTo(window);
		nutExit.drawTo(window);
		window.display();
	}
	if (dicEngViet)
		saveDict(englishVietnam, "sample3.txt");
	if (dicSlang)
		saveDict(slang, "sample1.txt");
	if (dicEmotion)
		saveDict(emotion, "emotional.txt");
	if (dicVietEng)
		saveDict(VietnamEnglish, "sample4.txt");

	deallocate(englishVietnam);
	deallocate(englishVietnamDef);
	deallocate(slang);
	deallocate(slangDef);
	deallocate(emotion);
	deallocate(emotiondef);
	deallocate(VietnamEnglish);
	deallocate(VietnamEnglishDef);
}