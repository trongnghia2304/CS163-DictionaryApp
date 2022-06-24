using namespace std;
#include "edit_definition.h"

bool add_meaning(TrieNode*&root_key, TrieNode*&root_def, string s, string new_meaning){
    if(!check_exist(root_key, s)) return false;
    insert(root_key, s, new_meaning);
    insert(root_def, new_meaning, s);
    return true;
}
bool delete_mean(TrieNode*&root_key, TrieNode*&root_def, string s, string old_meaning){
    if(!check_exist(root_key, s)) return false;
    if(check_delete_meaning(root_key, s) && check_delete_meaning(root_def, old_meaning)){
        return delete_meaning(root_key, s, old_meaning)&&delete_meaning(root_def, old_meaning, s);
    }
    else return false;
}
bool edit_meaning(TrieNode*&root_key, TrieNode*&root_def, string s, string old_meaning, string new_meaning){
    if(!check_exist(root_key, s)) return false;
    delete_meaning(root_key, s, old_meaning);
    insert(root_key, s, new_meaning);
    delete_meaning(root_def, old_meaning, s);
    int n=s.size();
    TrieNode *cur=root_def;
    for(int i=0; i<n; ++i) {
        int nxt=int(old_meaning[i]-32);
        cur=cur->c[nxt];
    }
    if(cur->meaning.size() == 0) root_def = remove(root_def, old_meaning, 0);
    insert(root_def, new_meaning, s);    
    return true;
}
