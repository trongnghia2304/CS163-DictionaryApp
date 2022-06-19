#include <iostream>
#include <algorithm>

// alphabet: ASCII 32-127 (all printable characters)
// For Dictionary project (with special characters like -, $, #...)
using namespace std;
#include "Trie.h"

void insert(TrieNode *&root, string &s, string &meaning) {
    int n=s.size();
    TrieNode *cur=root;
    for(int i=0; i<n; ++i) {
        int nxt=int(s[i]-32);
        if(!cur->c[nxt]) cur->c[nxt]=new TrieNode();
        cur=cur->c[nxt];
    }

    cur->isEndOfWord=true;
    cur->meaning=meaning;
}

vector <pair<string, string>> lookUpMeaning(TrieNode *root, string s) {
    int n=s.size();
    TrieNode *cur=root;

    for(int i=0; i<n; ++i) {
        int nxt=int(s[i]-32);
        if(!cur->c[nxt]) return {};
        cur=cur->c[nxt];
    }

    // BFS to check all strings exist on trie with s as prefix
    vector <pair<string, string>> v;
    queue <pair<string, TrieNode*>> q;
    q.push({s, cur});
    while(q.size()) {
        pair<string, TrieNode*> tmp=q.front();
        q.pop();

        if(tmp.second->isEndOfWord)
            v.push_back({tmp.first, tmp.second->meaning});
        
        for(int i=0; i<ALP; ++i) {
            if(tmp.second->c[i]) {
                string nS=tmp.first;
                nS+=char(32+i);
                q.push({nS, tmp.second->c[i]});
            }
        }
    }

    return v;
}

void Deallocate(TrieNode* &root) {
    if(!root) return;
    
    for(int i=0; i<ALP; ++i)
        Deallocate(root->c[i]);
    
    root->meaning.clear();
    delete root;
}

bool isEmpty(TrieNode* root) {
    for(int i=0; i<ALP; ++i)
        if(root->c[i]) return false;
    return true;
}

TrieNode* remove(TrieNode* &root, string key, int len=0) {
    if(!root || len>key.size()) return nullptr;

    if(len==key.size()) {
        if(root->isEndOfWord)
            root->isEndOfWord=false;
        if(isEmpty(root)) {
            delete root;
            root=nullptr;
        }

        return root;
    }

    int nxt=key[len]-32;
    root->c[nxt]=remove(root->c[nxt], key, len+1);

    if(isEmpty(root) && !root->isEndOfWord) {
        delete root;
        root=nullptr;
    }

    return root;
}