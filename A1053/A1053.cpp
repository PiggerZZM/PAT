#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> ans;

struct node
{
    int weight;
    vector<int> child;
    bool isleaf;
} Node[110];

void preorder(int root, int sum)
{
    if (sum + Node[root].weight <= s)
    {
        sum += Node[root].weight;
        ans.push_back(Node[root].weight);
        if (sum == s && Node[root].isleaf)
        {
            for (int i = 0; i < ans.size() - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[ans.size() - 1]);
            ans.pop_back();
            return;
        }
    }
    else
        return;

    for (int i = 0; i < Node[root].child.size(); i++)
    {
        preorder(Node[root].child[i], sum);
    }
    ans.pop_back();
    return;
}

bool cmp(int a, int b)
{
    return Node[a].weight > Node[b].weight;
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Node[i].weight);
        Node[i].isleaf = true;
    }
    for (int i = 0; i < m; i++)
    {
        int id;
        scanf("%d", &id);
        Node[id].isleaf = false;
        int num_child;
        scanf("%d", &num_child);
        for (int j = 0; j < num_child; j++)
        {
            int childid;
            scanf("%d", &childid);
            Node[id].child.push_back(childid);
        }
        // 邻接表结点降序排列，解决逆字典序输出
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }

    preorder(0, 0);

    return 0;
}