#include <cstdio>
#include <vector>
using namespace std;

int n, k, x;
int maxsum = -1;
int a[20];
vector<int> temp, ans;

void DFS(int i, int nowk, int sum, int sqrsum)
{
    if (i == n)
    {
        if (sum == x && sqrsum > maxsum)
        {
            maxsum = sqrsum;
            ans = temp;
        }
        return;
    }
    else
    {
        DFS(i + 1, nowk, sum, sqrsum);
        if (nowk < k)
        {
            temp.push_back(a[i]);
            DFS(i + 1, nowk + 1, sum + a[i], sqrsum + a[i] * a[i]);
            temp.pop_back();
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    DFS(0, 0, 0, 0);

    printf("%d\n", maxsum);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}