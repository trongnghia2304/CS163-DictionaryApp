using namespace std;
#include "Trie.h"
#include "add_new_word.h"
//mode will be assigned one of 3 values: 
// 1: Anh - Viet
// 2: Viet - Anh
// 3: Anh - Anh
// 
//3 files corresponding to the above datasets are:
// sample1.txt
// sample2.txt
// sample3.txt
// 
//And the format of the txt file will be:
// Nghiem'Hello/ con ga no minh 11k va di chan rau CT1821 PTNK
// Nghiem'Hello
// data'definition

void build_data(TrieNode*& root_key, TrieNode*& root_def, int mode)
{
	ifstream fin;

	string s = "sample" + to_string(mode) + ".txt";
	fin.open(s);
    
    string meaning;
    string s;
    while (getline(fin, s, '\''))
    {
        getline(fin, meaning, '\n');

        add_new_word(root_key, root_def, s, meaning);
    }

    fin.close();
}