#include <cstdio>
#include <set>
#include <vector>
using namespace std;

vector<int> node[10010];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        node[a1].push_back(a2);
        node[a2].push_back(a1);
    }
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        set<int> s;
        int nv;
        scanf("%d",&nv);
        for(int j=0; j<nv; j++)
        {
            int temp;
            scanf("%d",&temp);
            s.insert(temp);
        }
        bool flag = true;
        for(int index=0; index<n; index++)
        {
            if(s.find(index) == s.end())
            {
                for(int q=0; q<node[index].size(); q++)
                {
                    if(s.find(node[index][q]) == s.end())
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(!flag)
                break;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
