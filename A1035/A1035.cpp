#include <iostream>
#include <cstdio>
using namespace std;

char name[1010][20];
char pass[1010][20];
bool flag[1010] = {false};

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",name[i]);
        getchar();
        char ch;
        int p = 0;
        while((ch = getchar()) != '\n')
        {
            if(ch == '1')
            {
                pass[i][p++] = '@';
                flag[i] = true;
            }
            else if(ch == '0')
            {
                pass[i][p++] = '%';
                flag[i] = true;
            }
            else if(ch == 'l')
            {
                pass[i][p++] = 'L';
                flag[i] = true;
            }
            else if(ch == 'O')
            {
                pass[i][p++] = 'o';
                flag[i] = true;
            }
            else
                pass[i][p++] = ch;
        }
        pass[i][p] = '\0';
    }

    int mycount = 0;
    for(int i=0;i<n;i++)
        if(flag[i])
            mycount++;
    if(mycount != 0)
    {
        printf("%d\n",mycount);
        for(int i=0;i<n;i++)
        {
            if(flag[i])
                printf("%s %s\n",name[i],pass[i]);
        }
    }
    else
        if(n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n",n);

    return 0;
}
