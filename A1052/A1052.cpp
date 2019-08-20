#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int add;
    int val;
    int next;
    int valid;
} node[100010];

bool cmp(Node n1, Node n2)
{
    if (n1.valid != n2.valid)
        return n1.valid > n2.valid;
    else
        return n1.val < n2.val;
}

int main()
{
    int n, first;
    int count = 0;
    scanf("%d %d", &n, &first);
    for (int i = 0; i < 100010; i++)
    {
        node[i].val = 0x7FFFFFFF;
        node[i].next = -1;
        node[i].valid = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int k, val, next;
        scanf("%d %d %d", &k, &val, &next);
        node[k].add = k;
        node[k].val = val;
        node[k].next = next;
    }
    while (first != -1)
    {
        count++;
        node[first].valid = 1;
        first = node[first].next;
    }
    sort(node, node + 100010, cmp);
    if (count > 0)
    {
        printf("%d %05d\n", count, node[0].add);
        for (int i = 0; i < count - 1; i++)
        {
            node[i].next = node[i + 1].add;
            printf("%05d %d %05d\n", node[i].add, node[i].val, node[i].next);
        }
        printf("%05d %d -1\n", node[count - 1].add, node[count - 1].val);
    }
    else
        printf("0 -1\n");

    return 0;
}