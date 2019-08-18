#include <cstdio>
#include <set>
using namespace std;

set<int> s[51];

int main()
{
    int n,m,x,query;
    int nc,nt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&x);
            s[i].insert(x);
        }
    }
    
    int set1,set2;
    set<int>:: iterator it1;
    scanf("%d",&query);
    while(query--)
    {
        nc = 0;
        scanf("%d %d",&set1,&set2);
        it1 = s[set1].begin();
        nt = s[set2].size();
        while(it1 != s[set1].end())
        {
            if(s[set2].find(*it1) != s[set2].end())
                nc++;
            else
                nt++;
            it1++;
        }

        printf("%.1f%%\n",1.0*nc/nt*100);
    }
    

    return 0;
}