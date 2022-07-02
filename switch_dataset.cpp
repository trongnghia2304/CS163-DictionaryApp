using namespace std;
#include "switch_dataset.h"

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
// Nghiem'Hello/con ga no minh 11k va di chan rau CT1821 PTNK
// Nghiem'Hello
// data'definition1/definition2/definition3/...

void build_data(TrieNode*& root_key, TrieNode*& root_def, int mode)
{
	ifstream fin;

	string s = "sample" + to_string(mode) + ".txt";
	fin.open(s);

    string s, meaning;
    while (getline(fin, s, '\''))
    {
        getline(fin, meaning);
        int len = meaning.size() - 1;
        string str = "";
        for (int i = 0; i <= len; i++)
        {
            if (meaning[i] == '/')
            {
                add_new_word(root_key, root_def, s, str);
                str = "";
            }
            else str = str + meaning[i];
        }

        add_new_word(root_key, root_def, s, str);
    }
    fin.close();
}

// 3 files which are the original datasets and used to recover the very first data:
// origin1.txt
// origin2.txt
// origin3.txt

// this function called when we press reset button
void reset_file(int mode)
{
    ifstream fin;
    ofstream fout;

    string s = "origin" + to_string(mode) + ".txt";
    string s1 = "sample" + to_string(mode) + ".txt";

    fin.open(s);
    fout.open(s1);
    
    while (getline(fin, s))
    {
        fout << s << endl;
    }

    fin.close();
    fout.close();
}

//this function called to write down the 
void write_changes(int mode)
{

}