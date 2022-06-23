#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
// alphabet: ASCII 32-127 (all printable characters)
// For Dictionary project (with special characters like -, $, #...)
const int ALP=96;

struct TrieNode {
    int cnt;
    TrieNode *c[ALP];
    bool isEndOfWord;
    vector <string> meaning;

    TrieNode() {
        cnt=0;
        for(int i=0; i<ALP; ++i)
            c[i]=nullptr;
        isEndOfWord=false;
        meaning={};
    }
};

void insert(TrieNode *&root, string s, string meaning);
// bool lookUpMeaning1(TrieNode* root, string s, string& meaning);
void traverse(vector <pair<string, string>> &v, TrieNode* root, string s);
vector <pair<string, string>> lookUpMeaning(TrieNode *root, string s);
void deallocate(TrieNode* &root);
bool isEmpty(TrieNode* root);
TrieNode* remove(TrieNode* &root, string key, int len);
bool check_exist(TrieNode* &root_key, string s);
bool check_delete_meaning(TrieNode*&root, string s, string meaning);
bool delete_meaning(TrieNode*&root, string s, string meaning);
void deleteHistory();
void savetoHistory(string s);
vector <string> viewHistory();