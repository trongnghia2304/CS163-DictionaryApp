#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#include "random_four_def.h"
#include "random_word.h"

void random_key_4_def(TrieNode* root_key, TrieNode* root_def, string &s, vector<string> &meaning, string &right_meaning){
    vector<string>mean;
    random_word(root_key, s, mean);
    srand(time(NULL)); 
	int res = rand() % (mean.size());
    meaning.push_back(mean[res]);
    right_meaning = mean[res];
    while(meaning.size() < 4){
        string new_def;
        vector<string> new_mean;
        random_word(root_def, new_def, new_mean, 0);
        bool check = true;
        for(int i = 0; i < new_mean.size(); i++){
            if(new_mean[i] == s){
                check = false;
                break;
            }
        }
        for(int i = 0; i < meaning.size(); i++){
            if(new_def == meaning[i]){
                check = false;
                break;
            }
        }
        if(check) meaning.push_back(new_def);
    }
    random_shuffle(meaning.begin(), meaning.end());
}
