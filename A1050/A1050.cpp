#include <cstdio>
#include <cstring>
using namespace std;

char s1[10010],s2[10010];
bool hashtable[128];

int main()
{
    int count = 0;
    char tmp = ' ';
    while((tmp = getchar()) != '\n')
        s1[count++] = tmp;
    s1[count++] = '\n';
    s1[count] = '\0';
    count = 0;
    tmp = ' ';
    while((tmp = getchar()) != '\n')
        s2[count++] = tmp;
    s2[count++] = '\n';
    s2[count] = '\0';

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0;i<len2;i++)
        hashtable[s2[i]] = true;
    for(int i=0;i<len1;i++)
    {
        char ch = s1[i];
        if(hashtable[ch] == false)
            putchar(ch);
    }

    return 0;
}