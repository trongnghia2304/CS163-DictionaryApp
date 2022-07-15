#include <fstream>
using namespace std;
#include "saveDictionary.h"

void saveDictionary(TrieNode* root_key, string curWord, ofstream &fout) {
    if(root_key->isEndOfWord) {
        for(string mean: root_key->meaning)
            fout << curWord << "`" << mean << '\n';
    }

    for(int i=0; i<ALP; ++i) {
        if(root_key->c[i]) {
            curWord+=char(i+32);
            saveDictionary(root_key->c[i], curWord, fout);
            curWord.pop_back();
        }
    }
}

void saveDict(TrieNode* root_key, string directory) {
    ofstream fout(directory+"current.txt");
    saveDictionary(root_key, "", fout);
    fout.close();
}