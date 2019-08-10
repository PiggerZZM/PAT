#include <cstdio>

int coins[1010] = {0};

int main()
{
    int n,m;
    int v1,v2;
    int value;
    int nosolution = 1;
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        coins[value]++;
    }
    for(int i=1;i<=500;i++)
    {
        if(coins[i] > 0)
        {
            v1 = i;
            v2 = m-i;
            if(v1 != v2)
            {
                if(coins[v2] > 0)
                {
                    printf("%d %d\n",v1,v2);
                    nosolution = 0;
                    break;
                }
            }
            else
            {
                if(coins[v1] >= 2)
                {
                    printf("%d %d\n",v1,v2);
                    nosolution = 0;
                    break;
                }
            }
        }
    }
    if(nosolution)
        printf("No Solution\n");

    return 0;
}