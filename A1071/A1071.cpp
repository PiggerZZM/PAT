#include <map>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

bool valid(char ch)
{
    return (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

map<string, int> mp;

int main()
{
    string sentence, word;
    getline(cin, sentence);
    sentence += '\n';   // 只有一个单词的情况下，因为getline不读入最后的换行符\n，无法识别出这个单词结尾，没有添加到mp中
    string::iterator it = sentence.begin();
    while (it != sentence.end())
    {
        char ch = *it;
        if (valid(ch))
        {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
            word += ch;
        }
        else
        {
            if (mp.find(word) == mp.end())
            {
                if (word.length() != 0)
                    mp[word] = 1;
            }
            else
                mp[word]++;
            word.clear();
        }
        it++;
    }

    map<string, int>::iterator itmp;
    int max = 0;
    string common;
    for (itmp = mp.begin(); itmp != mp.end(); itmp++)
    {
        if (itmp->second > max)
        {
            common = itmp->first;
            max = itmp->second;
        }
    }

    cout << common << ' ' << max << endl;

    return 0;
}