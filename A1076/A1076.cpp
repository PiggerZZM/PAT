#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;

bool G[maxn][maxn];
int n, l, count;
bool inque[maxn] = {false};
int level[maxn];

void BFS(int index)
{
    queue<int> q;
    q.push(index);
    level[index] = 0;
    inque[index] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (level[top] > l)
            break;
        count++;
        for (int i = 1; i <= n; i++)
        {
            if (G[top][i] && !inque[i])
            {
                q.push(i);
                inque[i] = true;
                level[i] = level[top] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            int temp;
            scanf("%d", &temp);
            G[temp][i] = true;
        }
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int temp;
        scanf("%d", &temp);
        count = 0;
        for(int i=1;i<=n;i++)
        {
            inque[i] = false;
            level[i] = 0;
        }
        BFS(temp);
        printf("%d\n", count - 1);
    }

    return 0;
}