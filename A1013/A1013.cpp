#include <cstdio>
#include <cstring>
const int maxn = 1010;
int n;
bool G[maxn][maxn] = {false};
bool vis[maxn] = {false};
void DFS(int index, int del)
{
    if (index == del)
        return;
    vis[index] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && G[index][i])
            DFS(i, del);
    }
}

int main()
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a1, a2;
        scanf("%d %d", &a1, &a2);
        G[a1][a2] = true;
        G[a2][a1] = true;
    }

    for (int i = 0; i < k; i++)
    {
        int count = 0;
        int del;
        memset(vis, false, sizeof(vis));
        scanf("%d", &del);
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && j != del)
            {
                count++;
                DFS(j, del);
            }
        }
        printf("%d\n", count - 1);
    }

    return 0;
}