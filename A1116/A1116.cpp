#include <cstdio>

using namespace std;

const int maxn = 0x7FFFFFFF;
int hashtable[10010] = {0};

bool isprime(int myrank)
{
    bool flag = true;
    if(myrank == 2)
        return true;
    else
        for(int i=2; i<myrank; i++)
            if(myrank % i == 0)
                flag = false;
    return flag;
}

void print(int id)
{
    if(hashtable[id] > 0)
    {
        if(hashtable[id] == 1)
        {
            printf("Mystery Award\n");
            hashtable[id] = maxn;
        }
        else if(hashtable[id] == maxn)
        {
            printf("Checked\n");
        }
        else if(isprime(hashtable[id]))
        {
            printf("Minion\n");
            hashtable[id] = maxn;
        }
        else
        {
            printf("Chocolate\n");
            hashtable[id] = maxn;
        }
    }
    else
        printf("Are you kidding?\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int id;
        scanf("%d",&id);
        hashtable[id] = i;
    }
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        int id;
        scanf("%d",&id);
        printf("%04d: ",id);
        print(id);
    }

    return 0;
}
