#pragma once
#include "Trie2.h"
#include <vector>
#include <string>
#include "UI.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

void add_new_word(TrieNode*& root_key, TrieNode*& root_def, string s, string meaning);
bool remove_word(TrieNode*& root_key, TrieNode*& root_def, string s);
void saveDictionary(TrieNode* root_key, string curWord, ofstream& fout);
void saveDict(TrieNode* root_key, string directory);
std::vector<std::string> split(std::string str, std::string delimiter);
std::vector < std::string> cumTu(std::string str, int limit);
void build_data(TrieNode*& root_key, TrieNode*& root_def, std::string t, char deli);
bool add_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string new_meaning);
bool delete_mean(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning);
bool edit_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning, string new_meaning);
void addingWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
bool checkTonTai(TrieNode* root, string s, string meaning);
void deleteWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
void editWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
void khungSettingEdit(TrieNode*& rootEnglish, TrieNode*& rootVietnam, sf::Font font, TrieNode*& englishVietNam, TrieNode*& englishVietNamDef, TrieNode*& slang, TrieNode*& slangDef, TrieNode*& emotion, TrieNode*& emotionDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
void random_word(TrieNode*& root_key, string& s, string& meaning);
void random_key_4_def(TrieNode* root_key, TrieNode* root_def, string& s, vector<string>& meaning, string& right_meaning);
void random_word2(TrieNode*& root_key, string& s, vector<string>& meaning, int t = 1);