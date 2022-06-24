#pragma once
#include "Trie.h"

bool add_meaning(TrieNode*&root_key, TrieNode*&root_def, string s, string new_meaning);
bool delete_mean(TrieNode*&root_key, TrieNode*&root_def, string s, string old_meaning);
bool edit_meaning(TrieNode*&root_key, TrieNode*&root_def, string s, string old_meaning, string new_meaning);