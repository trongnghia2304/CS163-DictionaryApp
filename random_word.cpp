#include <cstdlib>
#include <ctime>
using namespace std;
#include "random_word.h"

void random_word(TrieNode* & root_key, string &s, vector<string> &meaning){
    TrieNode* cur = root_key;
    srand(time(NULL)); 
	int res = rand() % (96);
    while(!cur->c[res]){
        res = rand() % (96);
    }
    cur = cur->c[res];
    s = s + char(res+32);
    while(true){
        if(isEmpty(cur)){
            meaning = cur->meaning;
            break;
        }
        else{
            if(cur->isEndOfWord){
                int g = rand() % (2);
                if(g == 1){
                    meaning = cur->meaning;
                    break;
                }
                else{
                    res = rand() % (96);
                    while(!cur->c[res]){
                        res = rand() % (96);
                    }
                    cur = cur->c[res];
                    s = s + char(res+32);
                }
            }
            else{
                res = rand() % (96);
                while(!cur->c[res]){
                    res = rand() % (96);
                }
                cur = cur->c[res];
                s = s + char(res+32);
            }
        }
    }
}