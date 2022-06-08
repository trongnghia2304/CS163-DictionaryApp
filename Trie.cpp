#include <iostream>
#include <algorithm>

// alphabet: ASCII 32-127 (all printable characters)
// For Dictionary project (with special characters like -, $, #...)
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

void insert(TrieNode *&root, string s, string meaning) {
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

bool lookUpMeaning(TrieNode *root, string s, string &meaning) {
    int n=s.size();
    TrieNode *cur=root;

    for(int i=0; i<n; ++i) {
        int nxt=int(s[i]-32);
        if(!cur->c[nxt]) return false;
        cur=cur->c[nxt];
    }

    if(!cur->isEndOfWord) return false;

    meaning=cur->meaning;
    return true;
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

int main() {
    TrieNode* root=nullptr;
    root=new TrieNode();

    insert(root, "Coffee", "Ca phe");
    insert(root, "Tea", "Tra");
    insert(root, "Nghiem", "Con ga bac phoi");
    remove(root, "Tea", 0);

    string s;
    cin >> s;
    
    string meaning="";
    if(lookUpMeaning(root, s, meaning)) {
        cout << "Word: " << s << '\n';
        cout << "Meaning: " << meaning << '\n';
    }

    else {
        cout << "The word " << s << " doesn't exist in the dictionary.\n";
    }

    Deallocate(root);
}