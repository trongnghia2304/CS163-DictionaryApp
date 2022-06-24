using namespace std;
#include "remove_word.h"

int size_meaning(TrieNode* root, string s){
    int n=s.size();
    TrieNode *cur=root;
    for(int i=0; i<n; ++i) {
        int nxt=int(s[i]-32);
        cur=cur->c[nxt];
    }
    return cur->meaning.size();
}
bool remove_word(TrieNode*&root_key, TrieNode*&root_def, string s){
    if(!check_exist(root_key, s)) return false;
    int n=s.size();
    TrieNode *cur=root_key;
    for(int i=0; i<n; ++i) {
        int nxt=int(s[i]-32);
        cur=cur->c[nxt];
    }
    for(int i = 0; i < cur->meaning.size(); i++){
        delete_meaning(root_def, cur->meaning[i], s);
        if(size_meaning(root_def, cur->meaning[i]) == 0) root_def = remove(root_def, cur->meaning[i], 0);
    }
    root_key = remove(root_key, s, 0);
    return true;
}