#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int depthmax = 0;
bool vis[10010] = {false};
vector<int> node[10010];
vector<int> ans;
void DFS(int index)
{
    vis[index] = true;
    for(int i=0; i<node[index].size(); i++)
    {
        if(!vis[node[index][i]])
            DFS(node[index][i]);
    }
}

int DFS2(int index)
{
    vis[index] = true;
    int depth = 1;
    vector<int> temp;
    for(int i=0; i<node[index].size(); i++)
    {
        if(!vis[node[index][i]])
            temp.push_back(DFS2(node[index][i]));
    }
    int m = 0;
    for(int i=0; i<temp.size(); i++)
        if(temp[i] > m)
            m = temp[i];

    return depth + m;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n-1; i++)
    {
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        node[a1].push_back(a2);
        node[a2].push_back(a1);
    }

    int components = 0;
    for(int index = 1; index <= n; index++)
    {
        if(!vis[index])
        {
            DFS(index);
            components++;
        }
    }
    if(components == 1)
    {
        for(int i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            int depth = DFS2(i);
            if(depth > depthmax)
            {
                depthmax = depth;
                ans.clear();
                ans.push_back(i);
            }
            else if(depth == depthmax)
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++)
            printf("%d\n",ans[i]);
    }
    else
        printf("Error: %d components\n",components);

    return 0;
}
