using namespace std;
#include "edit_defination.h"
#include "addNewWord.h"
#include "Trie2.h"
#include "removeword.h"



bool add_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string new_meaning) {
    if (!check_exist(root_key, s)) return false;
	/*bool check1 = checkTonTai(root_key, s, new_meaning);*/
	/*if (check1)
		return false;*/
    insert(root_key, s, new_meaning);
    insert(root_def, new_meaning, s);
    return true;
}
bool delete_mean(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning) {
    if (!check_exist(root_key, s)) return false;
    if (check_delete_meaning(root_key, s) && check_delete_meaning(root_def, old_meaning)) {
        return delete_meaning(root_key, s, old_meaning) && delete_meaning(root_def, old_meaning, s);
    }
    else return false;
}
bool edit_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning, string new_meaning) {
	if (!check_exist(root_key, s)) return false;
	if (!delete_meaning(root_key, s, old_meaning)) return false;
	insert(root_key, s, new_meaning);
	delete_meaning(root_def, old_meaning, s);
	int n = old_meaning.size();
	TrieNode* cur = root_def;
	for (int i = 0; i < n; ++i) {
		int nxt = int(old_meaning[i] - 32);
		cur = cur->c[nxt];
	}
	if (cur->meaning.size() == 0) root_def = remove(root_def, old_meaning, 0);
	insert(root_def, new_meaning, s);
	return true;
}

void addingWordScreen(sf::Font font,TrieNode*& rootKey, TrieNode*& rootDef)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungadding.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "ADDING", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 300,300 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(15, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 110.f,80.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 39);

	Textbox noidungnhapDef(15, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 110.f,180.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 39);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 150.f,200.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
			}
			if (eventadd.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowAdd).x;
					float mouseY = sf::Mouse::getPosition(windowAdd).y;
					if (mouseX > 110 && mouseX < 427 && mouseY>74 && mouseY < 101)
					{
						thongbao.newstring("");
						noidungnhapKey.clearString();
						noidungnhapKey.setSelected(true);
					}
					else
						noidungnhapKey.setSelected(false);
					if (mouseX > 110 && mouseX < 427 && mouseY>173 && mouseY < 199)
					{
						thongbao.newstring("");
						noidungnhapDef.clearString();
						noidungnhapDef.setSelected(true);
					}
					else
					{
						noidungnhapDef.setSelected(false);
					}
					if (mouseX > 447 && mouseX < 504 && mouseY>217 && mouseY < 243)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						if (key != "" && def != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							bool check = add_meaning(rootKey, rootDef, key, def);
							if (check)
								thongbao.newstring("SUCCESS");
							else
							{
								thongbao.newstring("FAILURE");
							}

						}
					}
					if (mouseX > 359 && mouseX < 414 && mouseY>219 && mouseY < 243)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						if (key != "" && def != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							add_new_word(rootKey, rootDef, key, def);
							thongbao.newstring("SUCCESS");

						}
					}
				}
			}
		}
		
		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}

void deleteWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungdelete.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "DELETE", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 700,300 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(15, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 110.f,80.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 39);

	Textbox noidungnhapDef(15, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 110.f,180.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 39);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 150.f,200.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float mouseX = sf::Mouse::getPosition(windowAdd).x;
				float mouseY = sf::Mouse::getPosition(windowAdd).y;
				if (mouseX > 110 && mouseX < 427 && mouseY>74 && mouseY < 101)
				{
					thongbao.newstring("");
					noidungnhapKey.clearString();
					noidungnhapKey.setSelected(true);
				}
				else
					noidungnhapKey.setSelected(false);
				if (mouseX > 110 && mouseX < 427 && mouseY>173 && mouseY < 199)
				{
					thongbao.newstring("");
					noidungnhapDef.clearString();
					noidungnhapDef.setSelected(true);
				}
				else
				{
					noidungnhapDef.setSelected(false);
				}
				if (mouseX > 447 && mouseX < 504 && mouseY>217 && mouseY < 243)
				{
					string key = noidungnhapKey.getText();
					string def = noidungnhapDef.getText();
					if (key != "" && def != "")
					{
						noidungnhapKey.newstring("");
						noidungnhapDef.newstring("");
						bool check = delete_mean(rootKey, rootDef, key, def);
						if (check)
							thongbao.newstring("SUCCESS");
						else
						{
							thongbao.newstring("FAILURE");
						}

					}
				}
				if (mouseX > 359 && mouseX < 414 && mouseY>219 && mouseY < 243)
				{
					string key = noidungnhapKey.getText();
					/*string def = noidungnhapDef.getText();*/
					if (key != "")
					{
						noidungnhapKey.newstring("");
						noidungnhapDef.newstring("");
						bool temp = remove_word(rootKey, rootDef, key);
						if (!temp)
							thongbao.newstring("FAILURE");
						else
							thongbao.newstring("SUCCESS");

					}
				}
			}
		}

		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}

void editWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungedit.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "EDIT", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 430,240 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(20, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 163.f,89.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 60);

	Textbox noidungnhapDef(20, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 163.f,222.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 60);

	Textbox noidungnhapNew(20, sf::Color::Black, false);
	noidungnhapNew.setPosition({ 163.f,347.f });
	noidungnhapNew.newstring("");
	noidungnhapNew.setFont(font);
	noidungnhapNew.setLimit1(false, 60);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 244.f,380.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
				noidungnhapNew.typeOn(eventadd);
			}
			if (eventadd.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowAdd).x;
					float mouseY = sf::Mouse::getPosition(windowAdd).y;
					if (mouseX > 158 && mouseX < 593 && mouseY>81 && mouseY < 112)
					{
						thongbao.newstring("");
						noidungnhapKey.clearString();
						noidungnhapKey.setSelected(true);

					}
					else
						noidungnhapKey.setSelected(false);
					if (mouseX > 157 && mouseX < 594 && mouseY>217 && mouseY < 247)
					{
						thongbao.newstring("");
						noidungnhapDef.clearString();
						noidungnhapDef.setSelected(true);
					}
					else
					{
						noidungnhapDef.setSelected(false);
					}

					if (mouseX > 158 && mouseX < 590 && mouseY>341 && mouseY < 370)
					{
						thongbao.newstring("");
						noidungnhapNew.clearString();
						noidungnhapNew.setSelected(true);
					}
					else
					{
						noidungnhapNew.setSelected(false);
					}

					if (mouseX > 626 && mouseX < 702 && mouseY>350 && mouseY < 378)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						string neww = noidungnhapNew.getText();
						if (key != "" && def != "" && neww != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							bool check = edit_meaning(rootKey, rootDef, key, def,neww);
							if (check)
								thongbao.newstring("SUCCESS");
							else
							{
								thongbao.newstring("FAILURE");
							}

						}
					}
				}
			}
		}

		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		noidungnhapNew.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}
