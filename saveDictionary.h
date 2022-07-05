#pragma once
#include "Trie.h"

void saveDictionary(TrieNode* root_key, string curWord, ofstream &fout);

void saveDict(TrieNode* root_key, string directory);