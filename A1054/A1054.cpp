#include <cstdio>
#include <map>
using namespace std;

map<int, int> mp;

int main()
{
    int n,m;
    int temp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&temp);
            if(mp.find(temp) == mp.end())
                mp[temp] = 1;
            else
                mp[temp]++;
        }
    }

    int max = 0;
    int domin;
    map<int, int>::iterator it;
    for(it = mp.begin();it != mp.end();it++)
    {
        if(it->second > max)
        {
            max = it->second;
            domin = it->first;
        }
    }

    printf("%d\n",domin);

    return 0;
}