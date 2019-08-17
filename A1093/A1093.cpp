#include <cstdio>
#include <cstring>
using namespace std;

char ch[100010];
int leftP[100010] = {0};

int main()
{
    scanf("%s",ch);
    int len = strlen(ch);
    for(int i=0;i<len;i++)
        if(ch[i] == 'P')
            leftP[i+1] = leftP[i] + 1;
        else
            leftP[i+1] = leftP[i];
    int rightT = 0;
    int PAT = 0;
    for(int i=len-1;i>0;i--)
    {
        if(ch[i] == 'A')
        {
            PAT += (leftP[i] * rightT);
            PAT %= 1000000007;
        }
        else if(ch[i] == 'T')
            rightT++;
    } 

    printf("%d\n",PAT);

    return 0;
}