#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct mouse
{
    int weight;
    int rank;
} m[1010];

queue<int> q;

bool cmp(int m1, int m2)
{
    return m[m1].weight >= m[m2].weight;
}

int main()
{
    int np, ng;
    int index;
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++)
        scanf("%d", &m[i].weight);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &index);
        q.push(index);
    }
    int num = np;
    while (q.size() > 1)
    {
        int num_group = num / ng;
        if (num % ng != 0)
            num_group++;
        for (int i = 0; i < num_group; i++)
        {
            int max = q.front();
            for (int j = 0; j < ng; j++)
            {
                if (i * ng + j >= num)
                    break;
                int index = q.front();
                if(m[index].weight > m[max].weight)
                    max = index;
                q.pop();
                m[index].rank = num_group + 1;
            }
            q.push(max);
        }
        num = num_group;
    }

    m[q.front()].rank = 1;

    for (int i = 0; i < np - 1; i++)
        printf("%d ", m[i].rank);
    printf("%d\n", m[np - 1].rank);

    return 0;
}