#include <cstdio>
#include <algorithm>
using namespace std;

int father[1010];
int hobby[1010];

int Findfather(int i)
{
    int temp = i;
    while (father[i] > 0)
        i = father[i];
    while(temp != i)
    {
        int a = father[temp];
        father[temp] = i;
        temp = a;
    }
    
    return i;
}

void Union(int i, int j)
{
    int root1 = Findfather(i);
    int root2 = Findfather(j);
    if (root1 != root2)
    {
        father[root2] += father[root1];
        father[root1] = root2;
    }
}

int main()
{
    for (int i = 0; i < 1010; i++)
        father[i] = -1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int num_hob;
        scanf("%d:", &num_hob);
        for (int j = 0; j < num_hob; j++)
        {
            int hobbyindex;
            scanf("%d", &hobbyindex);
            if (hobby[hobbyindex] == 0)
                hobby[hobbyindex] = i;
            else
                Union(i, hobby[hobbyindex]);
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++)
        if (father[i] < 0)
            total++;
    printf("%d\n",total);
    sort(father, father + 1010);

    for (int i = 0; i < total - 1; i++)
        printf("%d ", -father[i]);
    printf("%d\n", -father[total - 1]);

    return 0;
}