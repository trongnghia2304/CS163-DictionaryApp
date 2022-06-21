using namespace std;
#include "Trie.h"

void add_new_word(TrieNode* &root_key, TrieNode* &root_def, string s, string meaning){
    insert(root_key, s, meaning);
    insert(root_def, meaning, s);
}

