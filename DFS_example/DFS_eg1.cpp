#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 20;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
vector<int> temp, ans;

// 不剪枝版本：直接遍历所有选和不选第i个物品的可能，直到所有物品都被遍历完则返回，更新最大价值
// 分岔口：第i个物品的选择和不选择
// 死胡同：所有物品的决策都已经确定
void DFS1(int i, int sumW, int sumC)
{
    if (i == n)
    {
        if (sumW <= V && sumC >= maxValue)
        {
            maxValue = sumC;
            ans = temp;
        }
        return;
    }
    else
    {
        temp.push_back(w[i]);
        DFS1(i + 1, sumW + w[i + 1], sumC + c[i + 1]); // 选第i个物品
        temp.pop_back();
        DFS1(i + 1, sumW, sumC); // 不选第i个物品
    }
}

// 剪枝版本：利用物品重量不能超过V这个条件，在分岔路的时候进行决策。或者直接把这个条件视为另一个死胡同

// 分岔口：第i个物品的选择和不选择
// 死胡同：所有物品的决策都已经确定
void DFS2(int i, int sumW, int sumC)
{
    if (i == n)
    {
        if (sumW <= V && sumC >= maxValue)
        {
            maxValue = sumC;
            ans = temp;
        }
        return;
    }
    else
    {
        DFS2(i + 1, sumW, sumC);
        if (sumW + w[i] <= V)
        {
            if (sumC + c[i] >= maxValue)
                maxValue = sumC + c[i];
            temp.push_back(w[i]);
            DFS2(i + 1, sumW + w[i], sumC + c[i]);
            temp.pop_back();
        }
    }
}

// 分岔口：第i个物品的选择和不选择
// 死胡同：1. 所有物品的决策都已经确定 2. 当前所选物品重量超过V
void DFS3(int i, int sumW, int sumC)
{
    if (i == n || sumW > V)
    {
        if (sumW <= V && sumC >= maxValue)
        {
            maxValue = sumC;
            ans = temp;
        }
        return;
    }
    else
    {
        DFS3(i + 1, sumW, sumC);
        temp.push_back(w[i]);
        DFS3(i + 1, sumW + w[i], sumC + c[i]);
        temp.pop_back();
    }
}

int main()
{
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    DFS3(0, 0, 0);

    printf("%d\n", maxValue);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}