using namespace std;
#include "switch_dataset.h"
#include "addNewWord.h"
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

void build_data(TrieNode*& root_key, TrieNode*& root_def,std::string t,char deli)
{
    ifstream fin;

  
    fin.open(t);

    string s, meaning;
    while (getline(fin, s, deli))
    {
        getline(fin, meaning);
        int len = meaning.size() - 1;
        string str = "";
        for (int i = 0; i <= len; i++)
        {
            if (meaning[i] == '|')
            {
                add_new_word(root_key, root_def, s, str);
                str = "";
                i += 1;
            }
            else str = str + meaning[i];
        }

        add_new_word(root_key, root_def, s, str);
    }

    fin.close();
}

//void build_data(TrieNode*& root_key, TrieNode*& root_def, int mode)
//{
//    ifstream fin;
//
//    string s1 = "sample" + to_string(mode) + ".txt";
//    fin.open(s1);
//
//    string s, meaning;
//    while (getline(fin, s, '`'))
//    {
//        getline(fin, meaning);
//        int len = meaning.size() - 1;
//        string str = "";
//        for (int i = 0; i <= len; i++)
//        {
//            if (meaning[i] == '|')
//            {
//                add_new_word(root_key, root_def, s, str);
//                str = "";
//                i += 1;
//            }
//            else str = str + meaning[i];
//        }
//
//        add_new_word(root_key, root_def, s, str);
//    }
//    fin.close();
//}
