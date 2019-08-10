#include <cstdio>

int hashtable[10010] = {0};
int bet[100010];

int main()
{
    int n;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        bet[i] = temp;
        hashtable[temp]++;
    }
    bool win = false;
    for(int i=0;i<n;i++)
    {
        temp = bet[i];
        if(hashtable[temp] == 1)
        {
            printf("%d\n",temp);
            win = true;
            break;
        }
    }
    if(!win)
        printf("None\n");


    return 0;
}