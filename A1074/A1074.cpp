#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int next;
    int order;
    int add;
} node[100010];

bool cmp(Node n1, Node n2)
{
    return n1.order < n2.order;
}

int main()
{
    int count = 0;
    int index, data, next;
    int first, n, k;
    for (int i = 0; i < 100010; i++)
        node[i].order = 0x7FFFFFFF;
    scanf("%d %d %d", &first, &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &index, &data, &next);
        node[index].add = index;
        node[index].data = data;
        node[index].next = next;
    }
    int p = first;
    while (p != -1)
    {
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + 100010, cmp);

    for (int i = 0; i < count / k; i++) // 枚举所有完整的块
    {
        for (int j = (i + 1) * k - 1; j > i * k; j--) // 倒序输出非每一块的非最后一个结点
            printf("%05d %d %05d\n", node[j].add, node[j].data, node[j - 1].add);
        // 下面输出每一块最后一个结点
        printf("%05d %d ", node[i * k].add, node[i * k].data);
        if (i < count / k - 1) // 不是最后一块
            printf("%05d\n", node[(i + 2) * k - 1].add);
        else // 是最后一块
        {
            if (count % k == 0) // 恰好是最后一个结点，说明没有不完整块
                printf("-1\n");
            else // 有不完整块，按照原先的顺序输出
            {
                printf("%05d\n", node[(i + 1) * k].add);
                for (int q = count / k * k; q < count; q++)
                {
                    printf("%05d %d ", node[q].add, node[q].data);
                    if (q < count - 1)
                        printf("%05d\n", node[q + 1].add);
                    else
                        printf("-1\n");
                }
            }
        }
    }

    return 0;
}