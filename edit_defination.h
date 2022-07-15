#pragma once
#include "Trie2.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "textbox.h"

bool add_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string new_meaning);
bool delete_mean(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning);
bool edit_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning, string new_meaning);
void addingWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef);
bool checkTonTai(TrieNode* root, string s, string meaning);
void deleteWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef);
void editWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef);