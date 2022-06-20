#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int ALP=96;

struct TrieNode {
    int cnt;
    TrieNode *c[ALP];
    bool isEndOfWord;
    string meaning;

    TrieNode() {
        cnt=0;
        for(int i=0; i<ALP; ++i)
            c[i]=nullptr;
        isEndOfWord=false;
    }
};

void insert(TrieNode *&root, string s, string meaning);
bool lookUpMeaning1(TrieNode* root, string s, string& meaning);
bool EditDefination(TrieNode*& root, string s, string change);
void traverse(vector <pair<string, string>> &v, TrieNode* root, string s);
vector <pair<string, string>> lookUpMeaning(TrieNode *root, string s);
void Deallocate(TrieNode* &root);
bool isEmpty(TrieNode* root);
TrieNode* remove(TrieNode* &root, string key, int len);