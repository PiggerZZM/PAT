#include <cstdio>
#include <vector>
using namespace std;

int n, k, p;
vector<int> temp, ans;
int maxsum = -1;

int fac[400];

int mypow_p(int x)
{
    int y = x;
    for (int i = 0; i < p - 1; i++)
        x *= y;
    return x;
}

void DFS(int i, int psum, int sum, int nowk)
{
    // i是数字i,psum是p次方和,sum是底数和,nowk是选中个数
    if (i == 0 || nowk == k)
    {
        if (nowk == k && psum == n && sum > maxsum)
        {
            maxsum = sum;
            ans = temp;
        }
        return;
    }
    else
    {
        if (psum + fac[i] <= n)
        {
            temp.push_back(i);
            DFS(i, psum + fac[i], sum + i, nowk + 1);
            temp.pop_back();
        }
        DFS(i - 1, psum, sum, nowk);
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &p);

    int maxi;
    for (maxi = 1; maxi <= n; maxi++)
    {
        int temp = mypow_p(maxi);
        if(temp <= n)
            fac[maxi] = temp;
        else
            break;
    }
    maxi--;

    DFS(maxi, 0, 0, 0);

    if (!ans.empty())
    {
        printf("%d = ", n);
        for (int i = 0; i < ans.size() - 1; i++)
            printf("%d^%d + ", ans[i],p);
        printf("%d^%d\n", ans[ans.size() - 1],p);
    }

    else
        printf("Impossible\n");

    return 0;
}
