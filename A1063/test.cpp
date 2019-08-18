#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        string temp = chars;
        int num = words.size();
        bool right = true;
        int count = 0;
        string::iterator it1,it2;
        for(int i=0;i<num;i++)
        {
            right = true;
            chars = temp;
            it1 = words[i].begin();
            while(it1 != words[i].end())
            {
                it2 = chars.begin();
                int tmp = chars.find(*it1);
                if(tmp != -1)
                {
                    it2 += tmp;
                    chars.erase(it2);
                }
                else
                {
                    right = false;
                    break;
                }
                it1++;
            }
            if(right)
                count++;
        }
        
        
        
        return count;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";
    cout << words[0];
    
    return 0;
}