#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int maxnum = 0, ans = 0;
int count[11] = {0};

struct node
{
    int level;
    vector<int> child;
} Node[110];

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
            Node[index].child.push_back(temp);
        }
    }

    queue<int> q;
    q.push(1);
    Node[1].level = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        count[Node[top].level]++;
        int size = Node[top].child.size();
        for (int i = 0; i < size; i++)
        {
            int child = Node[top].child[i];
            Node[child].level = Node[top].level + 1;
            q.push(child);
        }
    }

    for (int i = 1; i <= 10; i++)
        if (count[i] > maxnum)
        {
            maxnum = count[i];
            ans = i;
        }

    printf("%d %d\n",maxnum,ans);

    return 0;
}