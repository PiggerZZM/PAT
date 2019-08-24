#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int maxnum = 0, ans = 0;
int count[11] = {0};

vector<int> Node[110];

void DFS(int root, int level)
{
    count[level]++;
    int size = Node[root].size();
    for (int i = 0; i < size; i++)
        DFS(Node[root][i], level + 1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int index;
        scanf("%d", &index);
        int num_child;
        scanf("%d", &num_child);
        for (int j = 0; j < num_child; j++)
        {
            int temp;
            scanf("%d", &temp);
            Node[index].push_back(temp);
        }
    }

    DFS(1, 1);

    for (int i = 1; i <= 10; i++)
        if (count[i] > maxnum)
        {
            maxnum = count[i];
            ans = i;
        }

    printf("%d %d\n", maxnum, ans);

    return 0;
}