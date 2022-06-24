using namespace std;
#include "viewHistory.h"

void deleteHistory()
{
    ofstream fout;
    fout.open("lookedupWords.txt", ios_base::trunc);
    fout.close();
}

//called in all searching functions
void savetoHistory(string s)
{
    ofstream fout;
    fout.open("lookedupWords.txt", ios_base::app);

    fout << s << endl;

    fout.close();
}

vector <string> viewHistory()
{
    ifstream fin;
    fin.open("lookedupWords.txt");
    vector <string> v;
    string s;
    while (getline(fin, s))
    {
        v.push_back(s);
    }

    fin.close();
    return v;
}